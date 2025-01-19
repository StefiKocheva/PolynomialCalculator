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
constexpr int MAX_FRACTION_SIZE = 50;
constexpr int MAX_DEGREE_SIZE = 30;
constexpr char TERMINATE_SYMBOL = '\0';

void showOptions();
void handleOptionSelection();
void printSeparator();

bool isValidOption(char* option);
bool isValidInteger(char* str);
bool isValidDegree(char* degree);

int min(int a, int b);
int max(int a, int b);
int abs(int a);
int gcd(int a, int b);
int lcm(int a, int b);
int arrToInteger(char* str);

std::pair<int, int> readFraction();
std::pair<int, int> addFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB);
std::pair<int, int> subtractFractions(const std::pair<int, int> firstFraction, const std::pair<int, int> secondFraction);
std::pair<int, int> multiplyFractions(const std::pair<int, int> firstFraction, const std::pair<int, int> secondFraction);
std::pair<int, int> simplifyFraction(int numerator, int denominator);
void printFraction(const std::pair<int, int>& fraction);

std::vector<std::pair<int, int>> readPolynomial(char name);
int readPolynomialDegree();
void addPolynomials();
void subtractPolynomials();
void multiplyPolynomialByScalar();
void multiplyPolynomials();
void evaluatePolynomial();
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
        std::cout << std::endl;

        if (!isValidOption(option))
        {
            std::cout << "Invalid option! Try again>> " << std::endl;

            continue;
        }

        int optionNumber = arrToInteger(option);

        switch (optionNumber)
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
        }

        printSeparator();
    }
}

void printSeparator()
{
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
}

bool isValidOption(char* option)
{
    if (!option || *option == TERMINATE_SYMBOL)
    {
        return false;
    }

    for (int i = 0; option[i] != TERMINATE_SYMBOL; i++)
    {
        if (option[i] < '0' || option[i] > '11')
        {
            return false;
        }
    }

    int optionNumber = arrToInteger(option);

    return FISRT_OPTION <= optionNumber && optionNumber <= LAST_OPTION;
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

bool isValidDegree(char* degree)
{
    int i = 0;

    if (degree[i] == TERMINATE_SYMBOL)
    {
        return false;
    }

    if (degree[i] == '-')
    {
        return false;
    }

    while (degree[i] != TERMINATE_SYMBOL)
    {
        if (degree[i] < '0' || degree[i] > '9')
        {
            return false;
        }

        i++;
    }

    return true;
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

int arrToInteger(char* str)
{
    int sign = 1;
    int result = 0;

    while (*str == ' ' || *str == '\t' || *str == '\n')
    {
        str++;
    }

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    while (*str != TERMINATE_SYMBOL)
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
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
            std::cout << "Invalid number! Try again>> ";

            return readFraction();
        }

        numerator = arrToInteger(input);
    }
    else
    {
        *slashPosition = TERMINATE_SYMBOL;
        char* numeratorStr = input;
        char* denominatorStr = slashPosition + 1;

        if (!isValidInteger(numeratorStr) || !isValidInteger(denominatorStr))
        {
            std::cout << "Invalid fraction! Try again>>: ";

            return readFraction();
        }

        numerator = arrToInteger(numeratorStr);
        denominator = arrToInteger(denominatorStr);

        if (denominator == 0)
        {
            std::cout << "Invalid denominator! Try again>> ";
            return readFraction();
        }
    }

    return simplifyFraction(numerator, denominator);;
}

std::pair<int, int> addFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB)
{
    int lcmDenominator = lcm(fractionA.second, fractionB.second);

    int sumNumerator = (fractionA.first * (lcmDenominator / fractionA.second)) + (fractionB.first * (lcmDenominator / fractionB.second));

    return simplifyFraction(sumNumerator, lcmDenominator);
}


std::pair<int, int> subtractFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB)
{
    int lcmDenominator = lcm(fractionA.second, fractionB.second);

    int differenceNumerator = (fractionA.first * (lcmDenominator / fractionA.second)) - (fractionB.first * (lcmDenominator / fractionB.second));

    return simplifyFraction(differenceNumerator, lcmDenominator);
}


std::pair<int, int> multiplyFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB)
{
    int numeratorProduct = fractionA.first * fractionA.second;
    int denominatorProduct = fractionB.first * fractionB.second;

    return simplifyFraction(numeratorProduct, denominatorProduct);
}

std::pair<int, int> divideFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB)
{
    int numeratorProduct = fractionA.first * fractionB.second;
    int denominatorProduct = fractionA.second * fractionB.first;

    return simplifyFraction(numeratorProduct, denominatorProduct);
}

std::pair<int, int> simplifyFraction(int numerator, int denominator)
{
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    return { numerator, denominator };
}

void printFraction(const std::pair<int, int>& fraction)
{
    int numerator = fraction.first;
    int denominator = fraction.second;

    if (numerator == 0)
    {
        std::cout << "0";

        return;
    }

    if (denominator == 1)
    {
        std::cout << numerator;
    }
    else
    {
        std::cout << numerator << "/" << denominator;
    }
}

std::vector<std::pair<int, int>> readPolynomial(char name)
{
    std::cout << "Enter Polynomial " << name << "(x)" << std::endl;

    int degree = readPolynomialDegree();

    std::vector<std::pair<int, int>> polynomial(degree + 1);

    for (int i = degree; i >= 0; i--)
    {
        std::cout << "Enter coefficient before x^" << i << ": ";
        std::pair<int, int> coefficient = readFraction();

        polynomial[i] = coefficient;
    }

    printPolynomial(name, polynomial);

    return polynomial;
}

int readPolynomialDegree()
{
    std::cout << "Enter degree of your polynomial>> ";

    char degree[MAX_DEGREE_SIZE];
    std::cin >> degree;

    if (!isValidDegree(degree))
    {
        std::cout << "Invalid degree! Try again>> " << std::endl;

        return readPolynomialDegree();
    }

    return arrToInteger(degree);
}

void addPolynomials()
{
    std::vector<std::pair<int, int>> firstPolynomial = readPolynomial('P');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> secondPolynomial = readPolynomial('Q');
    std::cout << std::endl;

    int maxDegree = max(firstPolynomial.size(), secondPolynomial.size()) - 1;

    std::vector<std::pair<int, int>> result(maxDegree + 1, { 0, 1 });

    std::pair<int, int> emptyPair = { 0, 1 };

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = addFractions(
            i < firstPolynomial.size() ? firstPolynomial[i] : emptyPair,
            i < secondPolynomial.size() ? secondPolynomial[i] : emptyPair);
    }

    std::cout << "P(x)+Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, result);
}

void subtractPolynomials()
{
    std::vector<std::pair<int, int>> firstPolynomial = readPolynomial('P');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> secondPolynomial = readPolynomial('Q');
    std::cout << std::endl;

    int maxDegree = max(firstPolynomial.size(), secondPolynomial.size()) - 1;

    std::vector<std::pair<int, int>> result(maxDegree + 1, { 0, 1 });

    std::pair<int, int> emptyPair = { 0, 1 };

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = subtractFractions(
            i < firstPolynomial.size() ? firstPolynomial[i] : emptyPair,
            i < secondPolynomial.size() ? secondPolynomial[i] : emptyPair);
    }

    std::cout << "P(x)-Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, result);
}

void multiplyPolynomialByScalar()
{
    std::vector<std::pair<int, int>> polynomial = readPolynomial('P');
    std::cout << std::endl;

    std::cout << "Enter rational number>> ";
    std::pair<int, int> scalar = readFraction();

    for (int i = 0; i < polynomial.size(); i++)
    {
        polynomial[i] = multiplyFractions(polynomial[i], scalar);
    }

    std::cout << "Result: ";
    printPolynomial(TERMINATE_SYMBOL, polynomial);
}

void evaluatePolynomial()
{
    std::vector<std::pair<int, int>> polynomial = readPolynomial('P');
    std::cout << std::endl;

    std::cout << "Enter rational number>> ";

    std::pair<int, int> xValue = readFraction();

    std::pair<int, int> power = { 1, 1 };
    std::pair<int, int> result = { 0, 1 };

    for (int i = 0; i < polynomial.size(); i++)
    {
        if (i > 0) 
        {
            power = multiplyFractions(power, xValue);
        }

        std::pair<int, int> term = multiplyFractions(polynomial[i], power);
        result = addFractions(result, term);
    }

    std::cout << "P(";
    printFraction(xValue);
    std::cout << ") = ";
    printFraction(result);
    std::cout << std::endl;
}

void printPolynomial(char name, const std::vector<std::pair<int, int>>& polynomial)
{
	if (name != TERMINATE_SYMBOL)
	{
        std::cout << name << "(x) = ";
	}

    bool firstTerm = true;

    for (int i = polynomial.size() - 1; i >= 0; i--)
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
        }
        else if (numerator < 0)
        {
            std::cout << "-";
            numerator = -numerator;
        }

        if (denominator == 1)
        {
            if (numerator != 1 || i == 0)
            {
                std::cout << numerator;
            }
        }
        else
        {
            if (numerator == 1 && i != 0)
            {
                std::cout << "1";
            }
            else
            {
                std::cout << numerator;
            }

            std::cout << "/" << denominator;
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

void multiplyPolynomials()
{
    std::vector<std::pair<int, int>> firstPolynomial = readPolynomial('P');
    std::cout << std::endl;
    std::vector<std::pair<int, int>> secondPolynomial = readPolynomial('Q');
    std::cout << std::endl;

    int degreeResult = (firstPolynomial.size() - 1) + (secondPolynomial.size() - 1);
    std::vector<std::pair<int, int>> result(degreeResult + 1, { 0, 1 });

    for (int i = 0; i < firstPolynomial.size(); i++)
    {
        for (int j = 0; j < secondPolynomial.size(); j++)
        {
            std::pair<int, int> fractionProduct = multiplyFractions(firstPolynomial[i], secondPolynomial[j]);

            result[i + j] = addFractions(result[i + j], fractionProduct);
        }
    }

    std::cout << "P(x)*Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, result);
    std::cout << std::endl;
}
