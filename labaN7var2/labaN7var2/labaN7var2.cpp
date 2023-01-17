#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

class Airport;
void binWrite(std::string fileName, std::vector<Airport>& airport);

class Airport
{
public:

	Airport(int numberOfWorkers, int numberOfPassengers, int numberOfPlanes) :
		_numberOfPassengers(numberOfPassengers), _numberOfPlanes(numberOfPlanes), _numberOfWorkers(numberOfWorkers)
	{
	}

	friend std::ostream& operator<<(std::ostream& stream, Airport& airport)
	{
		stream << airport._numberOfWorkers << ' ' << airport._numberOfPassengers << ' ' << airport._numberOfPlanes << std::endl;
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, Airport& airport)
	{
		stream >> airport._numberOfWorkers >> airport._numberOfPassengers >> airport._numberOfPlanes;
		return stream;
	}

	void WriteToBin(std::ofstream& stream)
	{
		stream.write((char*)&_numberOfWorkers, sizeof(_numberOfWorkers));
		stream.write((char*)&_numberOfPassengers, sizeof(_numberOfPassengers));
		stream.write((char*)&_numberOfPlanes, sizeof(_numberOfPlanes));
	}

	void ReadFromBin(std::ifstream& stream)
	{
		stream.read((char*)&_numberOfWorkers, sizeof(_numberOfWorkers));
		stream.read((char*)&_numberOfPassengers, sizeof(_numberOfPassengers));
		stream.read((char*)&_numberOfPlanes, sizeof(_numberOfPlanes));
	}

	static bool SearchInBinFile(std::ifstream& stream, Airport& airport)
	{
		Airport tmp(0, 0, 0);
		for (int i = 0; i < 5; i++)
		{
			tmp.ReadFromBin(stream);
			if (tmp._numberOfPassengers == airport._numberOfPassengers && tmp._numberOfPlanes == airport._numberOfPlanes && tmp._numberOfWorkers == airport._numberOfWorkers)
				return true;
		}
		return false;
	}

	static bool SearchInTxtFile(std::ifstream& stream, Airport& airport)
	{
		Airport tmp(0, 0, 0);
		for (int i = 0; i < 5; i++)
		{
			stream >> tmp;
			if (tmp._numberOfPassengers == airport._numberOfPassengers && tmp._numberOfPlanes == airport._numberOfPlanes && tmp._numberOfWorkers == airport._numberOfWorkers)
				return true;
		}
		return false;
	}

	static void DeleteInBinFile(std::string fileName, Airport& airport)
	{
		Airport tmp(0, 0, 0);
		std::vector<Airport> airports;
		std::ifstream binFile(fileName, std::ios::binary);
		for (int i = 0; i < 5; i++)
		{
			tmp.ReadFromBin(binFile);
			if (!(tmp._numberOfPassengers == airport._numberOfPassengers && tmp._numberOfPlanes == airport._numberOfPlanes && tmp._numberOfWorkers == airport._numberOfWorkers))
				airports.push_back(tmp);
		}
		binFile.close();
		std::ofstream file(fileName, std::ios::trunc);
		file.close();
		binWrite(fileName, airports);
	}

	void SetNumberOfPlanes(int numberOfPlanes)
	{
		this->_numberOfPlanes = numberOfPlanes;
	}

	void SetNumberOfPassengers(int numberOfPassengers)
	{
		this->_numberOfPassengers = numberOfPassengers;
	}

	void SetNumberOfWorkers(int numberOfWorkers)
	{
		this->_numberOfWorkers = numberOfWorkers;
	}

private:
	int _numberOfPlanes;
	int _numberOfWorkers;
	int _numberOfPassengers;
};

void txtWrite(std::string fileName, std::vector<Airport>& airport);

void txtRead(std::string fileName, std::vector<Airport>& airport);

void binWrite(std::string fileName, std::vector<Airport>& airport);

void binRead(std::string fileName, std::vector<Airport>& airport);

void txtBinWrite(std::string fileName, std::vector<Airport>& airport);

void txtBinRead(std::string fileName, std::vector<Airport>& airport);

void SearchBin(std::string fileName);

void SearchTxt(std::string fileName);

void DeleteBin(std::string fileName);

int GetInt();

int main()
{
	Airport airport(1000, 7000, 40);
	std::vector<Airport> airports;
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			airport.SetNumberOfPassengers(41);
			airport.SetNumberOfPlanes(i);
			airport.SetNumberOfWorkers(i);
			airports.push_back(airport);
		}
		else
		{
			airport.SetNumberOfPassengers(i);
			airport.SetNumberOfPlanes(i);
			airport.SetNumberOfWorkers(i);
			airports.push_back(airport);
		}
	}

	int variant = 0;
	bool A = 1;
	while (A)
	{
		std::cout << "write to txtFile.txt (1)" << std::endl << "write to binFile.bin (2)" << std::endl << "write to binFile.txt(binary mode) (3)" << std::endl;
		std::cout << "read txtFile.txt (4)" << std::endl << "read binFile.bin (5)" << std::endl << "read binFile.txt (binary mode) (6)" << std::endl;
		std::cout << "Search in binFile.bin (7)" << std::endl << "Search in txtFile.txt (8)" << std::endl << "Delete in binFile.bin (9)" << std::endl << "exit (0)" << std::endl;
		variant = GetInt();
		switch (variant)
		{
		case 1:
			txtWrite("txtFile.txt", airports);
			break;
		case 2:
			binWrite("binFile.bin", airports);
			break;
		case 3:
			txtBinWrite("binFile.txt", airports);
			break;
		case 4:
			txtRead("txtFile.txt", airports);
			break;
		case 5:
			binRead("binFile.bin", airports);
			break;
		case 6:
			txtBinRead("binFile.txt", airports);
			break;
		case 7:
			SearchBin("binFile.bin");
			break;
		case 8:
			SearchTxt("txtFile.txt");
			break;
		case 9:
			DeleteBin("binFile.bin");
			break;
		case 0:
			A = 0;
			break;
		default:
			break;
		}
	}
}

void txtWrite(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Write to " << fileName + ':' << std::endl << std::endl;
	try
	{
		std::ofstream textFile(fileName);
		for (int i = 0; i < airport.size(); i++)
		{
			textFile << airport[i];
		}
		textFile.close();
		for (int i = 0; i < 5; i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void txtRead(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Read from " << fileName + ':' << std::endl << std::endl;
	try
	{
		std::ifstream textFile(fileName);
		for (int i = 0; i < airport.size(); i++)
		{
			textFile >> airport[i];
		}
		textFile.close();
		for (int i = 0; i < airport.size(); i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void binWrite(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Write to " << fileName + ':' << std::endl << std::endl;
	try
	{
		std::ofstream binFile(fileName, std::ios::binary);
		for (int i = 0; i < airport.size(); i++)
		{
			airport[i].WriteToBin(binFile);
		}
		binFile.close();
		for (int i = 0; i < airport.size(); i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void binRead(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Read from " << fileName + ':' << std::endl << std::endl;
	try
	{
		std::ifstream binFile(fileName, std::ios::binary);
		for (int i = 0; i < airport.size(); i++)
		{
			airport[i].ReadFromBin(binFile);
		}
		binFile.close();
		for (int i = 0; i < airport.size(); i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void txtBinWrite(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Write to " << fileName << "(Bin mode): " << std::endl << std::endl;
	try
	{
		std::ofstream binFile(fileName, std::ios::binary);
		for (int i = 0; i < airport.size(); i++)
		{
			airport[i].WriteToBin(binFile);
		}
		binFile.close();
		for (int i = 0; i < airport.size(); i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void txtBinRead(std::string fileName, std::vector<Airport>& airport)
{
	std::cout << "Read from " << fileName << "(Bin mode): " << std::endl << std::endl;
	try
	{
		std::ifstream binFile(fileName, std::ios::binary);
		for (int i = 0; i < airport.size(); i++)
		{
			airport[i].ReadFromBin(binFile);
		}
		binFile.close();
		for (int i = 0; i < airport.size(); i++)
		{
			std::cout << airport[i];
		}
		std::cout << std::endl << "------------------------------" << std::endl;
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void SearchBin(std::string fileName)
{
	try
	{
		std::cout << "Enter a number of workers: " << std::endl;
		int numberOfWorkers = GetInt();
		std::cout << "Enter a number of passengers: " << std::endl;
		int numberOfPassengers = GetInt();
		std::cout << "Enter a number of planes: " << std::endl;
		int numberOfPlanes = GetInt();
		Airport airport(numberOfWorkers, numberOfPassengers, numberOfPlanes);
		std::cout << std::endl << "Searching in " << fileName << ": " << std::endl;
		std::ifstream binFile(fileName, std::ios::binary);
		if (Airport::SearchInBinFile(binFile, airport))
		{
			binFile.close();
			std::cout << "Was found" << std::endl << "------------------------------" << std::endl;;
		}
		else
		{
			binFile.close();
			std::cout << "Was not found" << std::endl << "------------------------------" << std::endl;
		}
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void SearchTxt(std::string fileName)
{
	try
	{
		std::cout << "Enter a number of workers: " << std::endl;
		int numberOfWorkers = GetInt();
		std::cout << "Enter a number of passengers: " << std::endl;
		int numberOfPassengers = GetInt();
		std::cout << "Enter a number of planes: " << std::endl;
		int numberOfPlanes = GetInt();
		Airport airport(numberOfWorkers, numberOfPassengers, numberOfPlanes);
		std::cout << std::endl << "Searching in " << fileName << ": " << std::endl;
		std::ifstream txtFile(fileName);
		if (Airport::SearchInTxtFile(txtFile, airport))
		{
			txtFile.close();
			std::cout << "Was found" << std::endl << "------------------------------" << std::endl;;
		}
		else
		{
			txtFile.close();
			std::cout << "Was not found" << std::endl << "------------------------------" << std::endl;
		}
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

void DeleteBin(std::string fileName)
{
	try
	{
		std::cout << "Enter a number of workers: " << std::endl;
		int numberOfWorkers = GetInt();
		std::cout << "Enter a number of passengers: " << std::endl;
		int numberOfPassengers = GetInt(); 
		std::cout << "Enter a number of planes: " << std::endl;
		int numberOfPlanes = GetInt();
		Airport airport(numberOfWorkers, numberOfPassengers, numberOfPlanes);
		std::cout << std::endl << "Deleting in " << fileName << ": " << std::endl;
		Airport::DeleteInBinFile(fileName, airport);
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what();
	}
}

int GetInt()
{
	int value = 0;
	while (1)
	{
		rewind(stdin);
		if (scanf_s("%d", &value))
			return value;
		else
			rewind(stdin);
	}
}