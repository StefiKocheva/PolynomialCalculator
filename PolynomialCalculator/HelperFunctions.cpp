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
* Source: Implements fraction operations, including input handling, arithmetic operations, and validation.
*
*/

#include <iostream>
#include <vector>

#include "HelperFunctions.h"
#include "Constants.h"

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
        if (!isValidNumber(input, false))
        {
            std::cout << "Error: Invalid number! Try again>> ";

            return readFraction();
        }

        numerator = arrToInteger(input);
    }
    else
    {
        *slashPosition = TERMINATE_SYMBOL;
        char* numeratorStr = input;
        char* denominatorStr = slashPosition + 1;

        if (!isValidNumber(numeratorStr, false) || !isValidNumber(denominatorStr, false))
        {
            std::cout << "Error: Invalid fraction! Try again>> ";

            return readFraction();
        }

        numerator = arrToInteger(numeratorStr);
        denominator = arrToInteger(denominatorStr);

        if (denominator == 0)
        {
            std::cout << "Error: Division by zero! Try again>> ";

            return readFraction();
        }
    }

    return simplifyFraction(numerator, denominator);
}

std::pair<int, int> addFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB)
{
    int denominatorLcm = lcm(fractionA.second, fractionB.second);

    int adjustedNumeratorA = fractionA.first * (denominatorLcm / fractionA.second);
    int adjustedNumeratorB = fractionB.first * (denominatorLcm / fractionB.second);

    int numeratorSum = adjustedNumeratorA + adjustedNumeratorB;

    return simplifyFraction(numeratorSum, denominatorLcm);
}

std::pair<int, int> subtractFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB)
{
    int denominatorLcm = lcm(fractionA.second, fractionB.second);

    int adjustedNumeratorA = fractionA.first * (denominatorLcm / fractionA.second);
    int adjustedNumeratorB = fractionB.first * (denominatorLcm / fractionB.second);

    int numeratorDifference = adjustedNumeratorA - adjustedNumeratorB;

    return simplifyFraction(numeratorDifference, denominatorLcm);
}

std::pair<int, int> multiplyFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB)
{
    int numeratorProduct = fractionA.first * fractionB.first;
    int denominatorProduct = fractionA.second * fractionB.second;

    return simplifyFraction(numeratorProduct, denominatorProduct);
}

std::pair<int, int> divideFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB)
{
    int numeratorProduct = fractionA.first * fractionB.second;
    int denominatorProduct = fractionA.second * fractionB.first;

    return simplifyFraction(numeratorProduct, denominatorProduct);
}

std::pair<int, int> simplifyFraction(int numerator, int denominator)
{
    const int divisor = gcd(numerator, denominator);
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
    if (fraction.first == 0)
    {
        std::cout << "0";

        return;
    }

    if (fraction.second == 1)
    {
        std::cout << fraction.first;
    }
    else
    {
        std::cout << fraction.first << "/" << fraction.second;
    }
}

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

int absolute(int a)
{
    return a < 0 ? -a : a;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return absolute(a);
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return absolute(a * b) / gcd(a, b);
}

int readInteger(bool nonNegativeOnly)
{
    char str[MAX_INTEGER_SIZE];
    std::cin >> str;

    if (!isValidNumber(str, nonNegativeOnly))
    {
        std::cout << "Error: Invalid number! Try again>> ";

        return readInteger(nonNegativeOnly);
    }

    return arrToInteger(str);
}

const char* skipWhitespace(const char* str)
{
    while (*str == SPACE_SYMBOL || *str == TERMINATE_SYMBOL || *str == NEWLINE_SYMBOL)
    {
        str++;
    }

    return str;
}

bool isValidNumber(const char* str, bool nonNegativeOnly)
{
    str = skipWhitespace(str);

    if (!str || *str == TERMINATE_SYMBOL) 
    {
        return false;
    }

    if (*str == '-')
    {
        if (nonNegativeOnly)
        {
            return false;
        }

        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    if (*str == TERMINATE_SYMBOL) 
    {
        return false;
    }

    while (*str != TERMINATE_SYMBOL) 
    {
        if (*str < '0' || *str > '9') 
        {
            return false;
        }

        str++;
    }

    return true;
}

int arrToInteger(const char* str)
{
    str = skipWhitespace(str);

    int sign = 1;
	int result = 0;

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
