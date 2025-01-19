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
#include <vector>

constexpr int MAX_OPTION_SIZE = 10;
constexpr int MAX_FRACTION_SIZE = 10;
constexpr int MAX_DEGREE_SIZE = 10;
constexpr int FISRT_OPTION = 1;
constexpr int LAST_OPTION = 11;
constexpr char TERMINATE_SYMBOL = '\0';

void showOptions();
void handleOptionSelection();
bool isValidOption(char* option);
int arrayToInteger(char* string);
bool isValidDegree(char* degreeInput);
void readPolynomial(char name);
void printPolynomial(char name, const std::vector<std::pair<int, int>>& polynomial);

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
	            //Dividing polynomials...
	            break;
	        }
	        case 5:
	        {
	            //Multiplying polynomial by scalar...
	            break;
	        }
	        case 6:
	        {
	            //Finding value of polynomial...
	            break;
	        }
	        case 7:
	        {
	            //Finding GCD of polynomials...
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

    for (int i = 0; option[i] != TERMINATE_SYMBOL; i++)
    {
        if (option[i] < '0' || option[i] > '9')
        {
            return false;
        }
    }

    int optionNumber = arrayToInteger(option);

    return FISRT_OPTION <= optionNumber && optionNumber <= LAST_OPTION;
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

int min(int a, int b)
{
	return a > b ? b : a;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int abs(int a)
{
	return a < 0 ? -a : a;
}

int gcd(int a, int b)
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return abs(a);
}

int lcm(int a, int b)
{
	if (a == 0 || b == 0) 
	{        
		return 0;
	}

	return abs(a * b) / gcd(a, b);
}

int readPolynomialDegree()
{
	std::cout << "Enter degree of your polynomial>> ";

	char degree[MAX_DEGREE_SIZE];
	std::cin >> degree;

	if (!isValidDegree(degree))
	{
        std::cout << "Hmm, that doesn't look right. Please enter a non-negative integer for the degree of the polynomial." << std::endl;

        return readPolynomialDegree();
	}

	return arrayToInteger(degree);
}

bool isValidDegree(char* degreeInput)
{
    int i = 0;

    if (degreeInput[i] == TERMINATE_SYMBOL)
    {
        return false;
    }

    if (degreeInput[i] == '-')
    {
        return false;
    }

    while (degreeInput[i] != TERMINATE_SYMBOL)
    {
        if (degreeInput[i] < '0' || degreeInput[i] > '9')
        {
            return false;
        }

        i++;
    }

    return true;
}

bool isValidInteger(char* str) {
    if (!str || *str == TERMINATE_SYMBOL) {
        return false;
    }

    if (*str == '+' || *str == '-') {
        str++;
    }

    if (*str == TERMINATE_SYMBOL) {
        return false;
    }

    while (*str != TERMINATE_SYMBOL) {
        if (*str < '0' || *str > '9') {
            return false;
        }
        str++;
    }

    return true;
}

std::pair<int, int> readFraction()
{
    char input[MAX_FRACTION_SIZE];
    std::cin >> input;

    int numerator = 0, denominator = 1;
    char* slashPosition = nullptr;

    for (int i = 0; input[i] != TERMINATE_SYMBOL; i++) 
    {
        if (input[i] == '/') {
            slashPosition = &input[i];
            break;
        }
    }

    if (slashPosition == nullptr) 
    {
        if (!isValidInteger(input)) 
        {
            std::cout << "Invalid input! Please enter a valid number: ";

            return readFraction();
        }

        numerator = arrayToInteger(input);
    }
    else 
    {
        *slashPosition = TERMINATE_SYMBOL;
        char* numeratorStr = input;
        char* denominatorStr = slashPosition + 1;

        if (!isValidInteger(numeratorStr) || !isValidInteger(denominatorStr)) 
        {
            std::cout << "Invalid fraction format! Both numerator and denominator should be integers. Please enter a valid number: ";

            return readFraction();
        }

        numerator = arrayToInteger(numeratorStr);
        denominator = arrayToInteger(denominatorStr);

        if (denominator == 0) 
        {
            std::cerr << "Denominator can't be zero. Please enter a valid number: ";
            return readFraction();
        }
    }

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    return { numerator, denominator };
}

std::pair<int, int> addFractions(const std::pair<int, int>& firstFaction, const std::pair<int, int>& secondFraction)
{
    int firstNumerator = firstFaction.first;
    int firstDenominator = firstFaction.second;

    int secondNumerator = secondFraction.first;
    int secondDenominator = secondFraction.second;

    int lcmDenominator = lcm(firstDenominator, secondDenominator);

    int sumOfNumerators = (firstNumerator * (lcmDenominator / firstDenominator)) + (secondNumerator * (lcmDenominator / secondNumerator));

    int divisor = gcd(sumOfNumerators, lcmDenominator);
    sumOfNumerators /= divisor;
    lcmDenominator /= divisor;

    return { sumOfNumerators, lcmDenominator };
}

std::pair<int, int> subtractFractions(const std::pair<int, int>& firstFraction, const std::pair<int, int>& secondFraction)
{
    int firstNumerator = firstFraction.first;
    int firstDenominator = firstFraction.second;

    int secondNumerator = secondFraction.first;
    int secondDenominator = secondFraction.second;

    int lcmDenominator = lcm(firstDenominator, secondDenominator);

    int differenceOfNumerators = (firstNumerator * (lcmDenominator / firstDenominator)) -
        (secondNumerator * (lcmDenominator / secondDenominator));

    int divisor = gcd(differenceOfNumerators, lcmDenominator);
    differenceOfNumerators /= divisor;
    lcmDenominator /= divisor;

    return { differenceOfNumerators, lcmDenominator };
}


void readPolynomial(char name)
{
	std::cout << "Enter Polynomial>>" << name << "(x)" << std::endl;

	int degree = readPolynomialDegree();

	std::vector<std::pair<int, int>> polynomial(degree + 1);

	for (int i = degree; i >= 0; i--)
	{
        std::cout << "Enter coefficient before x^" << i << ": ";
		std::pair<int, int> coefficient = readFraction();

        polynomial[i] = coefficient;
	}

    printPolynomial(name, polynomial);
}

void printPolynomial(char name, const std::vector<std::pair<int, int>>& polynomial)
{
    std::cout << name << "(x) = ";
    bool firstTerm = true;

    for (int i = polynomial.size() - 1; i >= 0; --i)
    {
        int numerator = polynomial[i].first;
        int denominator = polynomial[i].second;

        if (numerator == 0)
        {
            continue;
        }

        if (!firstTerm)
        {
            if (numerator > 0)
            {
                std::cout << "+";
            }
            else
            {
                std::cout << " ";
            }
        }

        if (numerator == 1 && denominator == 1 && i > 0)
        {
            std::cout << "";
        }
        else if (numerator == -1 && denominator == 1 && i > 0)
        {
            std::cout << "-";
        }
        else if (denominator == 1)
        {
            std::cout << numerator;
        }
        else
        {
            std::cout << numerator << "/" << denominator;
        }

        if (i > 0)
        {
            std::cout << "x";
            if (i > 1)
            {
                std::cout << "^" << i;
            }
        }

        firstTerm = false;
    }

    if (firstTerm)
    {
        std::cout << "0";
    }

    std::cout << std::endl;
}

