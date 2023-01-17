#pragma once
#include "Memory.h"

namespace MyPC
{
	class CPU
	{
	public:
		CPU(int frequency, int numberOfCores, int sizeOfCache);

		void SetNumberOfCores(int cores);

		void SetFrequency(int frequency);

		int GetNumberOfCores();

		int GetFrequency();

	private:
		int _frequency;
		int _numberOfCores;
		Memory _cache;
	};
}