/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter Semester 2024/2025
*
* @author Stefani Kocheva
* @idnumber 0MI0600436
* @compiler VC
*
* What this file contains
*
*/

#include <iostream>

#include "UserInterface.h"
#include "MainFunctions.h"
#include "Constants.h"

void startPolynomialCalculator()
{
	showOptions();
	handleOptionSelection();
}

void showOptions()
{
	std::cout << "Choose one of the following functionalities:" << std::endl;
	std::cout << "1) Add polynomials" << std::endl;
	std::cout << "2) Subtract polynomials" << std::endl;
	std::cout << "3) Multiply polynomials" << std::endl;
	std::cout << "4) Divide polynomials" << std::endl;
	std::cout << "5) Multiply polynomial by scalar" << std::endl;
	std::cout << "6) Find value of polynomial at a given number" << std::endl;
	std::cout << "7) Find GCD of two polynomials" << std::endl;
	std::cout << "8) Display Vieta's formulas for a given polynomial" << std::endl;
	std::cout << "9) Represent a polynomial in powers of (x + a)" << std::endl;
	std::cout << "10) Factor polynomial and find its rational roots" << std::endl;
	std::cout << "11) Quit program" << std::endl;
}

void handleOptionSelection()
{
	char option[MAX_OPTION_SIZE];

	while (true)
	{
		std::cout << "Enter your option here>> ";
		std::cin >> option;
		std::cout << std::endl;

		switch (option)
		{
		case 1:
		{
			addPolynomials();

			break;
		}
		case 2:
		{
			subtractPolynomials();

			break;
		}
		case 3:
		{
			multiplyPolynomials();

			break;
		}
		case 4:
		{
			//Dividing polynomials...
			break;
		}
		case 5:
		{
			multiplyPolynomialByScalar();

			break;
		}
		case 6:
		{
			evaluatePolynomial();

			break;
		}
		case 7:
		{
			//Finding GCD of polynomials...
			break;
		}
		case 8:
		{

			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			//Factoring polynomial...
			break;
		}
		case 11:
		{
			std::cout << "Exiting..." << std::endl;

			return;
		}
		default:
		{
			std::cout << "Invalid option! Try again>> " << std::endl;

			continue;
		}
		}

		printSeparator();
	}
}

void printSeparator()
{
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
}
