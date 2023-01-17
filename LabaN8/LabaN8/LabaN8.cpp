#include <iostream>
#include <string>
#include <eh.h>

class StackException : public std::exception
{
public:
	StackException(const char* Exception) :
		std::exception(Exception)
	{
	}
};

template <typename type> struct Node
{
	Node<type>* _next;
	type _data;
};

template <typename type> class Stack
{
public:
	Stack(bool mode):
		_head(nullptr), _mode(mode)
	{
	}

	~Stack()
	{
	}

	void Push(type data)
	{
		Node<type>* p;

		if (!(p = new Node<type>))
			throw StackException("Memmory allocating error");
		if (_head != nullptr && _mode == 1)
		{
			if (SearchSameElement(data))
			{
				throw StackException("Repeating element");
			}
		}
		p->_data = data;
		p->_next = _head;
		_head = p;
	}

	void Show()
	{
		if (_head == nullptr)
		{
			throw StackException("Stack is empty");
		}
		else
		{
			Node<type>* p = _head;

			while (p != nullptr)
			{
				std::cout << p->_data << std::endl;
				p = p->_next;
			}
			return ;
		}
	}

	type Pop()
	{
		if (_head == nullptr)
			throw StackException("Stack is Empty");
		Node<type>* p1;
		type data = _head->_data;
		p1 = _head;
		_head = _head->_next;
		delete p1;
		return data;
	}

	bool SearchSameElement(type data)
	{
		if (_head == nullptr)
		{
			throw StackException("Stack is empty");
		}
		else
		{
			Node<type>* p = _head;

			while (p != nullptr)
			{
				if (p->_data == data)
					return 1;
				p = p->_next;
			}
			return 0;
		}
	}


private:
	bool _mode = 0;
	Node<type>* _head;
};

int main()
{
	Stack<int> Stack1(1);
	int i = 0, var = 0, value = 0;
	std::cout << "Push(1)" << std::endl << "Pop(2)" << std::endl << "Show(3)" << std::endl << "IsExist(4)" << std::endl << "Exit(5)" << std::endl;
	std::cin >> i;
	while (var != 1)
	{
		switch (i)
		{
		case 1:
			std::cout << "Enter value " << std::endl;
			std::cin >> value;
			try
			{
				Stack1.Push(value);
			}
			catch (StackException& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;
		case 2:
			try
			{
				Stack1.Pop();
			}
			catch (StackException& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;
		case 3:
			try
			{
				std::cout << "----------------" << std::endl;
				Stack1.Show();
				std::cout << "----------------" << std::endl;
			}
			catch (StackException& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;
		case 4:
			std::cout << "Enter value " << std::endl;
			std::cin >> value;
			try
			{
				std::cout << Stack1.SearchSameElement(value) << std::endl;
			}
			catch (StackException& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;
		case 5:
			var = 1;
			break;
		default:
			break;
		}
		std::cout << "Enter variant" << std::endl;
		std::cin >> i;
	}
}