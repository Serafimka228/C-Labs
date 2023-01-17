#include "HDD.h"

MyPC::HDD::HDD(int speed, int size):
	_speed(speed), _size(size)
{
}

void MyPC::HDD::SetSize(int size)
{
	this->_size.SetSize(size);
}

void MyPC::HDD::SetSpeed(int speed)
{
	this->_speed = speed;
}

int MyPC::HDD::GetSize()
{
	return this->_size.GetSize();
}

int MyPC::HDD::GetSpeed()
{
	return this->_speed;
}