#include <iostream>

class Human
{
public:
	Human():
		_name("Name"), _age(0)
	{
	}

	Human(std::string name, int age):
		_name(name), _age(age)
	{
	}

	virtual ~Human()
	{
		std::cout << "Human destructor" << std::endl;
	}

	std::string GetName()
	{
		return _name;
	}

	virtual void Run()
	{
		std::cout << "Running" << std::endl;
	};

	virtual void PrintInfo()
	{
		std::cout << std::endl << "---Human---" << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
	}

private:
	std::string _name;
	int _age = 0;
};

class Worker : public Human
{
public:
	Worker (std::string name, int age, int salary) :
		Human(name, age), _salary(salary)
	{
	}

	~Worker() override
	{
		std::cout << "Worker destructor" << std::endl;
	}

	void Run() override
	{
		std::cout << "Run" << std::endl;
	}

	void PrintInfo() override
	{
		std::cout << std::endl << "---Worker---" << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Salary: " << GetSalary() << std::endl;
	}

	int GetSalary()
	{
		return _salary;
	}

private:
	int _salary;
};

class Sportsman: public Human
{
public:
	Sportsman(std::string name, int age, int numberOfMedals) :
		Human(name, age), _numberOfMedals(numberOfMedals)
	{
	}

	~Sportsman() override
	{
		std::cout << "Sportsman destructor" << std::endl;
	}

	void Run() override
	{
		std::cout << "Run faster" << std::endl;
	}

	void PrintInfo() override
	{
		std::cout << std:: endl << "---Sporsman---" << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Number of medals: " << GetNumberOfMedals() << std::endl;
	}

	int GetNumberOfMedals()
	{
		return _numberOfMedals;
	}

private:
	int _numberOfMedals;
};

class Sprinter: public Sportsman
{
public:
	Sprinter(std::string name, int age, int numberOfMedals, float bestTime) :
		Sportsman(name, age, numberOfMedals), _bestTime(bestTime)
	{
	}

	~Sprinter() override
	{
		std::cout << "Sprinter destructor" << std::endl;
	}

	void Run() override
	{
		std::cout << "Run very fast" << std::endl;
	}

	void PrintInfo() override
	{
		std::cout << std::endl << "---Sprinter---" << std::endl;
		std::cout << "Name: " << GetName() << std::endl;
		std::cout << "Number of medals: " << GetNumberOfMedals() << std::endl;
		std::cout << "Best time: " << GetBestTime() << std::endl;
	}

	float GetBestTime()
	{
		return _bestTime;
	}

private:
	float _bestTime;
};

class God
{
public:
	void MakeHumanRun(Human* human)
	{
		human->Run();
	}
};

int main()
{
	Human* array[3];
	Worker* Worker1 = new Worker("Artem", 44, 4000);
	Sportsman* Sportsman1 = new Sportsman("Denis", 18, 3);
	Sprinter* Sprinter1 = new Sprinter("Mark", 22, 7, 10.11);
	array[0] = Worker1;
	array[1] = Sportsman1;
	array[2] = Sprinter1;


	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;
		array[i]->PrintInfo();
		array[i]->Run();
		std::cout << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete array[i];
	}
}