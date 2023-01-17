#include "PC.h"

namespace N
{
	class PC
	{
	public:
		PC(int numberOfCores)
		{
			this->_numberOfCores = numberOfCores;
		}

		void PrintParam()
		{
			std::cout << "cores: " << _numberOfCores << std::endl;
		}
	private:
		int _numberOfCores;
	};
}

int main()
{
	MyPC::PC pc1("Asus", 4, 3000, 12, 3400, 16, 1000, 7200);
	N::PC pc2(1);
	
	pc1.PrintParam();
	std::cout << std::endl << "--------------------" << std::endl;
	pc2.PrintParam();
}

