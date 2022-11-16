#include <iostream>

template <typename type> class Stack
{
public:
	Stack(int capacity):
		_capacity(capacity), _numberOfElement(-1)
	{
		Arr = new type[_capacity];
	}

	~Stack()
	{
		delete[] Arr;
	}

	bool IsEmpty()
	{
		return _numberOfElement < 0;
	}

	bool IsFull()
	{
		return _numberOfElement >= _capacity - 1;
	}

	void Push(type value)
	{
		if (IsFull())
		{
			std::cout << "The stack is full" << std::endl;
			return;
		}

		_numberOfElement++;
		Arr[_numberOfElement] = value;
	}

	int Size()
	{
		return _capacity;
	}

	type Pop()
	{
		if (IsEmpty())
		{
			std::cout << "The stack is empty" << std::endl;
			return 0;
		}
		_numberOfElement--;
		return Arr[_numberOfElement + 1];
	}

private:
	int _capacity;
	int _numberOfElement;
	type* Arr;
};

template <> class Stack<char*>
{
public:
	Stack(int capacity) :
		_capacity(capacity), _numberOfElement(-1)
	{
		Arr = new char*[_capacity];
	}

	~Stack()
	{
		delete[] Arr;
	}

	bool IsEmpty()
	{
		return _numberOfElement < 0;
	}

	bool IsFull()
	{
		return _numberOfElement >= _capacity - 1;
	}

	void Push(char* value)
	{
		if (IsFull())
		{
			std::cout << "The stack is full" << std::endl;
			return;
		}

		_numberOfElement++;
		Arr[_numberOfElement] = value;
	}

	char* Pop()
	{
		if (IsEmpty())
		{
			std::cout << "The stack is empty" << std::endl;
			return 0;
		}
		_numberOfElement--;
		return Arr[_numberOfElement + 1];
	}

private:
	int _capacity;
	int _numberOfElement;
	char** Arr;
};


int main()
{
	Stack<char> MyStack1(5);
	MyStack1.Pop();
	MyStack1.Push('K');
	MyStack1.Push('I');
	MyStack1.Push('T');
	MyStack1.Push('O');
	MyStack1.Push('K');
	MyStack1.Push('O');

	for (int i = 0; i < 5; i++)
	{
		std::cout << MyStack1.Pop() << std::endl;
	}

	std::cout << "-------------------------------" << std::endl;

	Stack<char*> MyStack2(3);

	char c = 'C';
	char* C = &c;
	char a = 'A';
	char* A = &a;
	char t = 'T';
	char* T = &t;
	MyStack2.Push(T);
	MyStack2.Push(A);
	MyStack2.Push(C);


	for (int i = 0; i < 3; i++)
	{
		std::cout << *MyStack2.Pop() << std::endl;
	}

}