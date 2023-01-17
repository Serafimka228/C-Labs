#pragma once
#include <iostream>

namespace MyPC
{
	class Memory
	{
	public:
		Memory(int size);

		int GetSize();

		void SetSize(int size);


	private:
		int _size;
	};
}