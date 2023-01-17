#pragma once
#include "CPU.h"
#include "HDD.h"
#include "RAM.h"

namespace MyPC
{
	class Computer
	{
	public:
		
		Computer(int cores, int coreFrequency, int cache, int ramFrequency, int ramSize, int hddSize, int hddSpeed);

		void PrintParam()
		{
			std::cout << "CPU: " << std::endl << "cores: " << _cpu.GetNumberOfCores() << std::endl << "coreFrequency " << _cpu.GetFrequency() << std::endl;
			std::cout << "RAM: " << std::endl << "Frequency " << _ram.GetFrequency() << std::endl << "Size " << _ram.GetSize() << std::endl;
			std::cout << "HDD: " << std::endl << "Speed " << _hdd.GetSpeed() << std::endl << "Size " << _hdd.GetSize() << std::endl;
		}

		void 

	private:
		CPU _cpu;
		RAM _ram;
		HDD _hdd;
	};
}