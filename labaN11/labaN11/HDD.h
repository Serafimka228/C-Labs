#pragma once
#include "Memory.h"

namespace MyPC
{
	class HDD
	{
	public:
		HDD(int speed, int size);

		void SetSize(int size);

		void SetSpeed(int speed);

		int GetSize();

		int GetSpeed();

	private:
		int _speed;
		Memory _size;
	};
}
