#include "computer.h"

MyPC::Computer::Computer(int cores, int coreFrequency, int cache, int ramFrequency, int ramSize, int hddSize, int hddSpeed) :
	_cpu(coreFrequency, cores, cache), _ram(ramFrequency, ramSize), _hdd(hddSpeed, hddSize)
{
}