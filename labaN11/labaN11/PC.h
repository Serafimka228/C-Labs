#pragma once
#include "computer.h"

namespace MyPC
{
	class PC: Computer
	{
	public:
		PC(std::string model, int cores, int coreFrequency, int cache, int ramFrequency, int ramSize, int hddSize, int hddSpeed);

		void PrintParam();
	
	private:
		std::string _model;
	};
}
