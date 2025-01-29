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

#include "MainFunctions.h"
#include "Constants.h"

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
