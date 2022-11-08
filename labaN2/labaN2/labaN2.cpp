#include <iostream>
#include <cmath>

int GetVariable(int* variable);

class MaxElementOfMatrix
{
public:
	MaxElementOfMatrix(int maxElement)
	{
		_MaxElement = maxElement;
	}

	friend std::ostream& operator<<(std::ostream& stream, MaxElementOfMatrix& obj);

private:
	int _MaxElement;
};
 
class MyMatrix
{
public:
	MyMatrix(int NewNumberOfStrings, int NewNumberOfColumns)
	{
		NumberOfStrings = NewNumberOfStrings;
		NumberOfColumns = NewNumberOfColumns;
		matrix = new int* [NumberOfStrings];
		for (int n = 0; n < NumberOfStrings; n++)
		{
			matrix[n] = new int[NumberOfColumns];
		}
		InitializeAsZero();
	}

	MyMatrix(const MyMatrix& obj)
	{
		this->NumberOfStrings = obj.NumberOfStrings;
		this->NumberOfColumns = obj.NumberOfColumns;
		this->matrix = new int* [this->NumberOfStrings];
		for (int n = 0; n < this->NumberOfStrings; n++)
		{
			this->matrix[n] = new int[this->NumberOfColumns];
		}
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				this->matrix[i][j] = obj.matrix[i][j];
			}
		}
	}

	~MyMatrix()
	{
		for (int n = 0; n < NumberOfStrings; n++)
		{
			delete[] matrix[n];
		}
		delete[] matrix;
	}

	int GetNumberOfStrings()
	{
		return NumberOfStrings;
	}

	int GetNumberOfColumns()
	{
		return NumberOfColumns;
	}

	void InitializeAsZero()
	{
		for (int n = 0; n < NumberOfStrings; n++)
		{
			for (int k = 0; k < NumberOfColumns; k++)
			{
				matrix[n][k] = 0;
			}
		}
	}

	void PrintMatrix()
	{
		for (int n = 0; n < NumberOfStrings; n++)
		{
			for (int k = 0; k < NumberOfColumns; k++)
			{
				std::cout << matrix[n][k] << "   ";
			}
			std::cout << std::endl;
		}
	}

	void InitializeMatrix()
	{
		int var = 0;
		for (int n = 0; n < NumberOfStrings; n++)
		{
			for (int k = 0; k < NumberOfColumns; k++)
			{
				GetVariable(&var);
				matrix[n][k] = var;
			}
		}

	}

	int* operator[](const int& i)
	{
		return matrix[i];
	}

	MyMatrix operator+(MyMatrix& obj)
	{
		MyMatrix NewMatrix(obj.NumberOfStrings, obj.NumberOfColumns);
		if (obj.NumberOfColumns != this->NumberOfColumns || obj.NumberOfStrings != this->NumberOfStrings)
		{
			std::cout << "Different matrix sizes" << std::endl;
			return NewMatrix;
		}
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				NewMatrix.matrix[i][j] = this->matrix[i][j] + obj.matrix[i][j];
			}
		}
		return NewMatrix;
	}

	friend MyMatrix operator-(MyMatrix& Matrix1, MyMatrix& Matrix2) 
	{
		MyMatrix NewMatrix(Matrix1.NumberOfStrings, Matrix1.NumberOfColumns);
		if (Matrix1.NumberOfStrings != Matrix2.NumberOfStrings && Matrix1.NumberOfColumns != Matrix2.NumberOfColumns)
		{
			std::cout << "Different matrix sizes" << std::endl;
			return NewMatrix;
		}
		for (int i = 0; i < Matrix1.NumberOfStrings; i++)
		{
			for (int j = 0; j < Matrix2.NumberOfColumns; j++)
			{
				NewMatrix.matrix[i][j] = Matrix1.matrix[i][j] - Matrix2.matrix[i][j];
			}
		}
		return NewMatrix;
	}

	MyMatrix& operator=(MyMatrix& obj)
	{
		this->NumberOfStrings = obj.NumberOfStrings;
		this->NumberOfColumns = obj.NumberOfColumns;
		if (this->matrix != nullptr)
		{
			for (int n = 0; n < NumberOfStrings; n++)
			{
				delete[] this->matrix[n];
			}
			delete[] this->matrix;
		}
		this->matrix = new int* [this->NumberOfStrings];
		for (int n = 0; n < this->NumberOfStrings; n++)
		{
			this->matrix[n] = new int[this->NumberOfColumns];
		}
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				this->matrix[i][j] = obj.matrix[i][j];
			}
		}
		return *this;
	}

	MyMatrix& operator++()
	{
		for (int i = 0; i < this->NumberOfStrings; i++)
		{
			for (int j = 0; j < this->NumberOfColumns; j++)
			{
				this->matrix[i][j]++;
			}
		}
		return *this;
	}

	MyMatrix operator++(int)
	{
		MyMatrix Matrix = *this;
		++* this;
		return Matrix;
	}

	bool operator==(const MyMatrix& OtherMatrix) const
	{
		if (NumberOfStrings != OtherMatrix.NumberOfStrings || NumberOfColumns != OtherMatrix.NumberOfColumns)
		{
			return 0;
		}
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				if (matrix[i][j] != OtherMatrix.matrix[i][j])
					return 0;
			}
		}
		return 1;
	}

	bool operator!=(const MyMatrix& OtherMatrix) const
	{
		return !(*this == OtherMatrix);
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const MyMatrix& Matrix)
	{
		for (int i = 0; i < Matrix.NumberOfStrings; i++)
		{
			for (int j = 0; j < Matrix.NumberOfColumns; j++)
			{
				stream << Matrix.matrix[i][j] << "   ";
			}
			stream << std::endl;
		}
		return stream;
	}

	int FindMaxElement()
	{
		int MaxElement = matrix[0][0];
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				if (matrix[i][j] > MaxElement)
					MaxElement = matrix[i][j];
			}
		}
		return MaxElement;
	}

	operator int()
	{
		return FindMaxElement();
	}

	operator MaxElementOfMatrix()
	{
		return MaxElementOfMatrix(FindMaxElement());
	}

	MyMatrix operator+(int** variable)
	{
		MyMatrix NewMatrix(this->NumberOfStrings, this->NumberOfColumns);
		for (int i = 0; i < NumberOfStrings; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				NewMatrix.matrix[i][j] = this->matrix[i][j] + variable[i][j];
			}
		}
		return NewMatrix;
	}

private:

	int NumberOfStrings = 0, NumberOfColumns = 0;
	int** matrix;
};

std::ostream& operator<<(std::ostream& stream, MaxElementOfMatrix& obj)
{
	stream << obj._MaxElement;
	return stream;
}

int main()
{
	int Strings = 0;
	int Columns = 0;
	std::cout << "The number of strings is " << std::endl;
	GetVariable(&Strings);
	std::cout << "The number of columns is " << std::endl;
	GetVariable(&Columns);

	MyMatrix Matrix1(Strings, Columns);
	Matrix1.PrintMatrix();

	std::cout << "Initialize Matrix1 " << std::endl;
	Matrix1.InitializeMatrix();
	Matrix1.PrintMatrix();

	int** array = new int* [Strings];
	for (int i = 0; i < Columns; i++)
	{
		array[i] = new int[Columns];
	}
	for (int i = 0; i < Strings; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			array[i][j] = 2;
		}
	}


	//operator[][]
	std::cout << "Element[1][1] is " << Matrix1[1][1] << std::endl;
	//std::cout << Matrix1[1][1] << std::endl;

	
	int NumberOfElements = (int)Matrix1;
	//MaxElementOfMatrix f = (MaxElementOfMatrix)(int)Matrix1;
	MaxElementOfMatrix f = (MaxElementOfMatrix)Matrix1.FindMaxElement();
	std::cout << "Max Element is " << f << std::endl;
	std::cout << "Number of elements is " << NumberOfElements << std::endl;


	MyMatrix Matrix2(Strings, Columns);
	std::cout << "Initialize Matrix2 " << std::endl;
	Matrix2.InitializeMatrix();
	Matrix2.PrintMatrix();

	bool s = Matrix1 == Matrix2;
	if (s)
		std::cout << "Matrix1 == Matrix2" << std::endl;
	else
		std::cout << "Matrix1 != Matrix2" << std::endl;

	//operator - 
	std::cout << "Matrix3 = Matrix1 - Matrix2  " << std::endl;
	MyMatrix Matrix3 = Matrix1 - Matrix2;
	Matrix3.PrintMatrix();
	
	//operator +
	std::cout << "Matrix4 = Matrix1 + Matrix2 " << std::endl;
	MyMatrix Matrix4(Matrix1 + Matrix2);
	Matrix4.PrintMatrix();

	//operator =
	std::cout << "Matrix4 = Matrix1 " << std::endl;
	Matrix4 = Matrix1;
	Matrix4.PrintMatrix();
	 
	//operator ++
	std::cout << "++Matrix1" << std::endl;
	++Matrix1;
	Matrix1.PrintMatrix();
	Matrix1++;
	std::cout << "Matrix1++" << std::endl;
	Matrix1.PrintMatrix();

	//operator+ int**

	MyMatrix Matrix0 = Matrix1 + array;
	std::cout << "Matrix0 = Matrix1 + array: " << std::endl;
	std::cout << Matrix0 << std::endl;
	for (int i = 0; i < Strings; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	//operator << 
	std::cout << "--------------------------" << std::endl;
	std::cout << "Matrix2 is " << std::endl;
	std::cout << Matrix2 << std::endl;
	std::cout << "--------------------------" << std::endl;

	//operator == and !=
	std::cout << std::endl;
	bool k = Matrix1 != Matrix2;
	if (k)
		std::cout << "Matrix1 != Matrix2" << std::endl;
	else
		std::cout << "Matrix1 == Matrix2" << std::endl;
	return 0;
}

int GetVariable(int* variable)
{
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (;;)
	{
		if ((std::cin >> (*variable)).good())
			return 0;
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Not a number" << std::endl;
	}
}
