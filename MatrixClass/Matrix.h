#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
class Matrix
{
private:

	int row;
	int column;
	int number = 0;
	std::vector<std::vector<int>> vec;

public:

	Matrix()
	{
		row = 0;
		column = 0;

		std::cout << "Enter your matrix's size (row,col): ";
		std::cin >> row >> column;

		if (row * column < 0) throw "Invalid Size!!";

		vec.resize(row, std::vector<int>(column));
	}

	Matrix(int row, int column)
	{
		this->row = row;
		this->column = column;

		vec.resize(row, std::vector<int>(column));
	}

	void GenerateMatrix();
	//Copy constructor

	Matrix(const Matrix& obj);
	// << Operator overloading
	friend std::ostream& operator<<(std::ostream& os, Matrix& obj);
	// + Operator overloading
	Matrix operator+(const int& number);
	//Assignment Operator Overloading
	Matrix& operator=(const Matrix& obj);
	// * Operator Overloading
	Matrix operator*(const int& number);
	// - Operator Overloading
	Matrix operator-(const int& number);
	// / Operator Overloading
	Matrix operator/(const int& number);




	//Set Method for number
	void set_number(int number) { this->number = number; }
	//Get Method for number
	int get_number() { return number; }
};

