#include "Matrix.h"

void Matrix::GenerateMatrix()
{
	//Random matrix Generator
	int upperLimit = 10;
	int lowerLimit = 0;

	srand(static_cast <unsigned int> (time(0)));

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec[i].size(); j++)
		{
			vec[i][j] = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
		}
	}
}

//Copy constructor
Matrix::Matrix(const Matrix& obj)
{
	vec.clear();
	std::cout << "\nCopy Constructor called" << std::endl;
	this->row = obj.row;
	this->column = obj.column;
	vec.resize(row, std::vector<int>(column));

	for (size_t i = 0; i < obj.vec.size(); i++)
	{
		for (size_t j = 0; j < obj.vec[i].size(); j++)
		{
			this->vec[i][j] = obj.vec[i][j];
		}
	}
}

Matrix Matrix::operator+(const int& number)
{
	for (size_t i = 0; i < this->vec.size(); i++)
	{
		for (size_t j = 0; j < this->vec[i].size(); j++)
			this->vec[i][j] += number;
	}
	return *this;
}

Matrix& Matrix::operator=(const Matrix& obj)
{
	if (this != &obj)
	{
		vec.clear();
		std::cout << "\nAssignment operator called" << std::endl;
		this->row = obj.row;
		this->column = obj.column;
		vec.resize(row, std::vector<int>(column));
		for (size_t i = 0; i < obj.vec.size(); i++)
		{
			for (size_t j = 0; j < obj.vec[i].size(); j++)
			{
				this->vec[i][j] = obj.vec[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator*(const int& number)
{
	for (size_t i = 0; i < this->vec.size(); i++)
	{
		for (size_t j = 0; j < this->vec[i].size(); j++)
			this->vec[i][j] *= number;
	}
	return *this;
}

Matrix Matrix::operator-(const int& number)
{
	for (size_t i = 0; i < this->vec.size(); i++)
	{
		for (size_t j = 0; j < this->vec[i].size(); j++)
			this->vec[i][j] -= number;
	}
	return *this;
}

Matrix Matrix::operator/(const int& number)
{
	try {

		if (number == 0) throw - 1;
		for (size_t i = 0; i < this->vec.size(); i++)
		{
			for (size_t j = 0; j < this->vec[i].size(); j++)
				this->vec[i][j] /= number;
		}
		
	}
	catch (int &excpt)
	{
		std::cout << "Divided by zero error!!!" << std::endl;
		exit(0);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Matrix& obj)
{
	for (size_t i = 0; i < obj.vec.size(); i++)
	{
		for (size_t j = 0; j < obj.vec[i].size(); j++)
			os << obj.vec[i][j] << " ";
		os << std::endl;
	}

	return os;
}
