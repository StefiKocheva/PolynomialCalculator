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

#include "HelperFunctions.h"
#include "Constants.h."

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
