#include "RAM.h"

MyPC::RAM::RAM(int frequency, int size) :
	_frequency(frequency), _size(size)
{
}

void MyPC::RAM::SetFrequency(int frequency)
{
	this->_frequency = frequency;
}

int MyPC::RAM::GetFrequency()
{
	return this->_frequency;
}

int MyPC::RAM::GetSize()
{
	return this->_size.GetSize();
}