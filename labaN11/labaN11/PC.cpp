#include "PC.h"

MyPC::PC::PC(std::string model, int cores, int coreFrequency, int cache, int ramFrequency, int ramSize, int hddSize, int hddSpeed) :
	Computer(cores, coreFrequency, cache, ramFrequency, ramSize, hddSize, hddSpeed), _model(model)
{
}

void MyPC::PC::PrintParam()
{
	std::cout << "Model: " << _model << std::endl;
	Computer::PrintParam();
}