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

constexpr unsigned MAX_OPTION_SIZE = 10;
constexpr char TERMINATE_SYMBOL = '\0';

void showOptions();
void handleOptionSelection();
bool isValidOption(char* option);
int arrayToInteger(char* string);

int main()
{
    std::cout << "Welcome to Polynomial Calculator - a mini project intended to work with polynomials with rational coefficients" << std::endl;

    showOptions();
    handleOptionSelection();

    return 0;
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

        if (!isValidOption(option))
        {
            std::cout << "Invalid option!" << std::endl;

            continue;
        }

        int optionNumber = arrayToInteger(option);

        switch (optionNumber)
        {
	        case 1:
	        {
	            //Adding polynomials...
	            break;
	        }
	        case 2:
	        {
	            //Subtracting polynomials...
	            break;
	        }
	        case 3:
	        {
	            //Multiplying polynomials...
	            break;
	        }
	        case 4:
	        {
	            //Dividing polynomials...\n
	            break;
	        }
	        case 5:
	        {
	            //Multiplying polynomial by scalar...
	            break;
	        }
	        case 6:
	        {
	            //Finding value of polynomial...\n"
	            break;
	        }
	        case 7:
	        {
	            //Finding GCD of polynomials...\n
	            break;
	        }
	        case 8:
	        {
	            //Displaying Vieta's formulas...
	            break;
	        }
	        case 9:
	        {
	            //Representing polynomial in powers of (x + a)...
	            break;
	        }
	        case 10:
	        {
	            //Factoring polynomial...
	            break;
	        }
	        case 11:
	        {
	            std::cout << "Exiting... Goodbye!" << std::endl;
	            return;
	        }
        }
    }
}

bool isValidOption(char* option)
{
    if (!option || *option == TERMINATE_SYMBOL)
    {
        return false;
    }

    int i = 0;
    while (option[i] != TERMINATE_SYMBOL)
    {
        if (option[i] < '0' || option[i] > '9')
        {
            return false;
        }
        i++;
    }

    int optionNumber = arrayToInteger(option);
    return optionNumber >= 1 && optionNumber <= 11;
}

int arrayToInteger(char* string)
{
    int sign = 1;
    int result = 0;

    while (*string == ' ' || *string == '\t' || *string == '\n')
    {
        string++;
    }

    if (*string == '-')
    {
        sign = -1;
        string++;
    }
    else if (*string == '+')
    {
        string++;
    }

    while (*string != TERMINATE_SYMBOL)
    {
        result = result * 10 + (*string - '0');
        string++;
    }

    return result * sign;
}
