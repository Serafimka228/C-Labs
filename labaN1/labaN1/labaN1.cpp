#include <iostream>
#include <string>

static int COUNTER = 0;

int GetNumber()
{
	int number = 0;
	for(;;)
	{
		if ((std::cin >> number).good() && number > 0)
			return number;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Wrong number" << std::endl;
	}
}

class Employee
{
public:
	Employee()
	{
		ID = COUNTER++;
		Salary = 0;
		Name = "Not named";
	}
	Employee(std::string name)
	{
		Name = name;
		ID = COUNTER++;
		Salary = 0;
	}
	~Employee()
	{
		std::cout << std::endl << "--------------------------";
		std::cout << "Destructor N" << ID << " worked" << std::endl;
	}
	friend class Accountant;
	void friend PrintEmployeeInfo(Employee& employee);

private:
	int ID;
	int Salary;
	std::string Name;
};

class Accountant
{
public:
	void SetEmployeeSalary(Employee& employee)
	{
		std::cout << "Employee N" << employee.ID << " salary:" << std::endl;
		employee.Salary = GetNumber();
	}
};

void PrintEmployeeInfo(Employee& employee)
{
	std::cout << "Name: " << employee.Name << std::endl;
	std::cout << "Id: " << employee.ID << std::endl;
	std::cout << "Salary: " << employee.Salary << std::endl;
}

int main()
{
	Employee worker1;
	PrintEmployeeInfo(worker1);
	std::cout << std::endl;
	Employee worker2("Maxim");
	PrintEmployeeInfo(worker2);

	std::cout << "---------------------------------------" << std::endl;
	
	Accountant accountant;
	accountant.SetEmployeeSalary(worker1);
	std::cout << std::endl;
	PrintEmployeeInfo(worker1);
	std::cout << std::endl;

	accountant.SetEmployeeSalary(worker2);
	std::cout << std::endl;
	PrintEmployeeInfo(worker2);

	std::cout << "---------------------------------------" << std::endl;

	Employee* Company = new Employee[2];
	for (int i = 0; i < 2; i++)
	{
		std::cout << std::endl;
		PrintEmployeeInfo(Company[i]);
		std::cout << std::endl;
		accountant.SetEmployeeSalary(Company[i]);
		std::cout << std::endl;
		PrintEmployeeInfo(Company[i]);
	}

	delete[] Company;
	return 0;
}