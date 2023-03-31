#include <iostream>
#include <cstdlib>
#include "Matrix.h"


/*
      Implement a Matrix Class and divide, multiply, subtract or add all elements
	  of a matrix with a constant number
*/

using namespace std;

void operation(int *n,char *choice)
{
	cout << "1) Addition" << endl;
	cout << "2) Subtraction" << endl;
	cout << "3) Multiplication" << endl;
	cout << "4) Division" << endl;
	cout << "Enter your choice: " << endl;
	cin >> (*choice);
	cout << "\nEnter the number needed: ";
	cin >> (*n);
}

int main()
{
	
	char choice;
	int number;
	operation(&number, &choice);

	Matrix* vec = new Matrix(5, 5);

	try {

		vec->GenerateMatrix();
		cout << "Default Matrix" << endl;
		cout << *vec;
		//Call the set method for number
		vec->set_number(number);
		//------------------------------  Operations with switch case instruction  --------------------
		
		switch (choice)
		{
		case '1': *vec = *vec + number; break;
		case '2': *vec = *vec - number; break;
		case '3': *vec = *vec * number; break;
		case '4': *vec = *vec / number; break;
		default:
			cout << "Enter an option between(1 - 4)" << endl;
		}

		if (choice == '1') {
			cout << "\n+ Operator applied!" << endl;
			cout << *vec;
		}
		else if (choice == '2')
		{
			cout << "\n- Operator applied!" << endl;
			cout << *vec;
		}
		else if (choice == '3')
		{
			cout << "\n* Operator applied!" << endl;
			cout << *vec;
		}
		else if (choice == '4')
		{
			cout << "\n/ Operator applied!" << endl;
			cout << *vec;
		}

		delete vec;
	}catch(const char* exp)
	{
		cout << "Exception Handled!!!" << endl;
	}
	return 0;
}