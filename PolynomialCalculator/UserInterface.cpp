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
* Source: Implements the user interface and manages user interactions.
*
*/

#include <iostream>

#include "UserInterface.h"
#include "MainFunctions.h"

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
	std::cout << "7) Display Vieta's formulas for a given polynomial" << std::endl;
	std::cout << "8) Find k-th derivative for a given polynomial" << std::endl;
	std::cout << "9) Quit program" << std::endl;
}

void handleOptionSelection()
{
	int option;

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
				dividePolynomials();

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
				displayVietasFormulas();

				break;
			}
			case 8:
			{
				findKthDerivative();

				break;
			}
			case 9:
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

		std::cout << std::endl;
	}
}
