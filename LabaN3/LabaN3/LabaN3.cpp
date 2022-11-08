#include <iostream>
#include <cmath>

class Human
{
public:

	Human()
	{
	}

	Human(std::string name, int age):
		_name(name), _age(age)
	{
		std::cout << "Human Constructor" << std::endl;
	}

	~Human()
	{
	}

	void SetName(std::string newName)
	{
		_name = newName;
	}

	void SetAge(int newAge)
	{
		_age = newAge;
	}

	std::string GetName()
	{
		return _name;
	}

	int GetAge()
	{
		return _age;
	}

	virtual void PrintInfo() 
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl << std::endl;
	}

private: 
	std::string _name;
	int _age = 0;
};



class Worker: public virtual Human
{
public:
	Worker()
	{
	}

	Worker(std::string name, int age, int salary):
		Human(name, age),
		_salary(salary)
	{
		std::cout << "Worker Constructor" << std::endl;
	}

	~Worker()
	{
	}

	void SetSalary(int newSalary)
	{
		_salary = newSalary;
	}

	int GetSalary()
	{
		return _salary;
	}

	virtual void PrintInfo() override
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl;
		std::cout << "Salary: " << this->GetSalary() << std::endl << std::endl;
	}

private:
	int _salary = 0;
};



class Trainee : public Worker
{
public:
	Trainee(std::string name, int age, int salary, int timeToBecomeWorker):
		Human(name, age),Worker(name, age, salary),
		_timeToBecomeWorker(timeToBecomeWorker)
	{
		std::cout << "Trainee Constructor" << std::endl;
	}

	void SetTimeToBecomeWorker(int newTime)
	{
		_timeToBecomeWorker = newTime;
	}

	int GetTimeToBecomeWorker()
	{
		return _timeToBecomeWorker;
	}

	void PrintInfo() override
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl;
		std::cout << "Salary: " << this->GetSalary() << std::endl;
		std::cout << "Time to become worker: " << this->GetTimeToBecomeWorker() << std::endl << std::endl;
	}

private:
	int _timeToBecomeWorker;
};



class Sportsman: public virtual Human
{
public:

	Sportsman()
	{
	}

	Sportsman(std::string name, int age, int numberOfMedals):
		Human(name, age), _numberOfMedals(numberOfMedals)
	{
		std::cout << "Sportsman Constructor" << std::endl;
	}

	void SetNumberOfMedals(int newNumberOfMedals)
	{
		_numberOfMedals = newNumberOfMedals;
	}

	int GetNumberOfMedals()
	{
		return _numberOfMedals;
	}

	virtual void PrintInfo() override
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl;
		std::cout << "Number of medals: " << this->GetNumberOfMedals() << std::endl << std::endl;
	}

private:
	int _numberOfMedals = 0;
};



class FootballPlayer: public Sportsman
{
public:
	FootballPlayer(std::string name, int age, int numberOfMedals, std::string team):
		Human(name, age), Sportsman(name, age, numberOfMedals), _team(team)
	{
		std::cout << "FootballPlayer Constructor" << std::endl;
	}

	void SetTeam(std::string newTeam)
	{
		_team = newTeam;
	}

	std::string GetTeam()
	{
		return _team;
	}

	void PrintInfo() override
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl;
		std::cout << "Number of medals: " << this->GetNumberOfMedals() << std::endl;
		std::cout << "Team: " << this->GetTeam() << std::endl << std::endl;
	}

private:
	std::string _team;
};



class Sasha : public FootballPlayer, public Trainee
{
public:
	Sasha(std::string name, int age, int numberOfMedals, std::string team, int salary, int timeToBecomeWorker, bool isWorking, bool isPlayingFootball) :
		Human(name, age), FootballPlayer(name, age, numberOfMedals, team),  Trainee(name, age, salary, timeToBecomeWorker), _isWorking(isWorking), _isPlayingFootball(isPlayingFootball)
	{
		std::cout << "Sasha Constructor" << std::endl;
	}

	~Sasha()
	{
	}

	void PlayFootball()
	{
		_isPlayingFootball = 1;
		_isWorking = 0;
	}

	void Work()
	{
		_isWorking = 1;
		_isPlayingFootball = 0;
	}

	bool IsWorking()
	{
		return _isWorking;
	}

	bool IsPlayingFootball()
	{
		return _isPlayingFootball;
	}

	std::string CurrentState()
	{
		if (IsPlayingFootball())
			return "Playing Football";
		if (IsWorking())
			return "Working";
	}

	void PrintInfo() override
	{
		std::cout << "Name: " << this->GetName() << std::endl;
		std::cout << "Age: " << this->GetAge() << std::endl;
		std::cout << "Number of medals: " << this->GetNumberOfMedals() << std::endl;
		std::cout << "Team: " << this->GetTeam() << std::endl;
		std::cout << "Salary: " << this->GetSalary() << std::endl;
		std::cout << "Time to become worker: " << this->GetTimeToBecomeWorker() << std::endl;
		std::cout << this->CurrentState() << std::endl << std::endl;
	}

private:
	bool _isPlayingFootball;
	bool _isWorking;
};

int main()
{
	Human Mark("Mark", 26);
	Worker Steve("Steve", 47, 4000);
	Trainee Max("Max", 19, 1000, 400);
	Sportsman Tyler("Tyler", 27, 11);
	FootballPlayer Joe("Joe", 23, 1, "Arsenal");
	Sasha Alexander("Alexander", 18, 0, "Barcelona", 2000, 200, 0, 1);

	std::cout << std::endl;
	Mark.PrintInfo();
	Steve.PrintInfo();
	Max.PrintInfo();
	Tyler.PrintInfo();
	Joe.PrintInfo();
	Alexander.PrintInfo();

	return 0;
}


int GetVariable(int* variable)
{
	for (;;)
	{
		if ((std::cin >> (*variable)).good())
			return 0;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Not a number" << std::endl;
	}
}