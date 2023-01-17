#pragma once
#include "Memory.h"

namespace MyPC
{
	class RAM
	{
	public:

		RAM(int frequency, int size);

		void SetFrequency(int frequency);

		int GetFrequency();

		int GetSize();

	private:
		Memory _size;
		int _frequency;
	};
}