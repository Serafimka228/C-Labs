#include "Memory.h"

MyPC::Memory::Memory(int size) :
	_size(size)
{
};

void MyPC::Memory::SetSize(int size)
{
	this->_size = size;
}

int MyPC::Memory::GetSize()
{
	return this->_size;
}