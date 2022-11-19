#include <iostream>
#include <string>
#include <eh.h>
#define CAPACITY 5

void My_Term();

class StackException : public std::exception
{
public:
	StackException(const char* Exception) :
		std::exception(Exception)
	{
	}

private:
};

template <typename type> class Stack
{
public:
	Stack() :
		_capacity(CAPACITY), _numberOfElement(-1)
	{
	}

	~Stack()
	{
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
			throw StackException("Stack is Full");
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
			throw StackException("Stack is Empty");
		}
		_numberOfElement--;
		return Arr[_numberOfElement + 1];
	}

	bool operator==(const Stack& OtherStack)
	{
		return this->_capacity == OtherStack->_capacity;
	}

	bool operator!=(const Stack& OtherStack)
	{
		return this->_capacity != OtherStack->_capacity;
	}

private:
	int _capacity;
	int _numberOfElement;
	type Arr[CAPACITY];
};

int main()
{
	set_terminate(My_Term);
	Stack<char> MyStack1;

	try
	{
		MyStack1.Pop();
	}
	catch (const std::exception& Exception)
	{
		std::cout << Exception.what() << std::endl;
	}

	MyStack1.Push('K');
	MyStack1.Push('I');
	MyStack1.Push('T');
	MyStack1.Push('O');
	MyStack1.Push('K');

	try
	{
		MyStack1.Push('O');
	}
	catch (const StackException& Exception)
	{
		std::cout << Exception.what() << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << MyStack1.Pop() << std::endl;
	}
	terminate();
}

void My_Term()
{
	std::cout << "The programm was terminated" << std::endl;
	exit(-1);
}
