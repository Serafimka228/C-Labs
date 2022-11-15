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

int main()
{
	Stack<char> MyStack(5);
	MyStack.Pop();
	MyStack.Push('K');
	MyStack.Push('O');
	MyStack.Push('T');
	MyStack.Push('I');
	MyStack.Push('K');
	MyStack.Push('O');

	for (int i = 0; i < 5; i++)
	{
		std::cout << MyStack.Pop() << std::endl;
	}

}