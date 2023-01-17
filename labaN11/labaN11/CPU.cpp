#include "CPU.h"

MyPC::CPU::CPU(int frequency, int numberOfCores, int sizeOfCache):
	_frequency(frequency), _numberOfCores(numberOfCores), _cache(sizeOfCache)
{
}

int MyPC::CPU::GetFrequency()
{
	return this->_frequency;
}

int MyPC::CPU::GetNumberOfCores()
{
	return this->_numberOfCores;
}

void MyPC::CPU::SetNumberOfCores(int cores)
{
	this->_numberOfCores = cores;
}

void MyPC::CPU::SetFrequency(int frequency)
{
	this->_frequency = frequency;
}
