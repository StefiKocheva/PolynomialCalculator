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
#include "HelperFunctions.h"
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

    std::cout << std::endl;

    return polynomial;
}

int readPolynomialDegree()
{
    std::cout << "Enter degree of your polynomial>> ";

    char degree[MAX_DEGREE_SIZE];
    std::cin >> degree;

    if (!isValidDegree(degree))
    {
        std::cout << "Invalid input! Try again>> " << std::endl;

        return readPolynomialDegree();
    }

    return arrayToInteger(degree);
}

void addPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    std::vector<std::pair<int, int>> polynomialQ = readPolynomial('Q');

    const int maxDegree = max(polynomialP.size(), polynomialQ.size()) - 1;

    const std::pair<int, int> defaultFraction = { 0, 1 };
    std::vector<std::pair<int, int>> polynomialSum(maxDegree + 1, defaultFraction);

    for (int i = 0; i <= maxDegree; i++)
    {
        polynomialSum[i] = addFractions(
        i < polynomialP.size() ? polynomialP[i] : defaultFraction,
        i < polynomialQ.size() ? polynomialQ[i] : defaultFraction);
    }

    std::cout << "P(x)+Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, polynomialSum);
}

void subtractPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    std::vector<std::pair<int, int>> polynomialQ = readPolynomial('Q');

    int maxDegree = max(polynomialP.size(), polynomialQ.size()) - 1;

    std::pair<int, int> defaultFraction = { 0, 1 };
    std::vector<std::pair<int, int>> result(maxDegree + 1, defaultFraction);

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = subtractFractions(
            i < polynomialP.size() ? polynomialP[i] : defaultFraction,
            i < polynomialQ.size() ? polynomialQ[i] : defaultFraction);
    }

    std::cout << "P(x)-Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, result);
}

std::vector<std::pair<int, int>> subtractPolynomials(std::vector<std::pair<int, int>> polynomialP, std::vector<std::pair<int, int>> polynomialQ)
{
    int maxDegree = max(polynomialP.size(), polynomialQ.size()) - 1;

    std::pair<int, int> defaultFraction = { 0, 1 };
    std::vector<std::pair<int, int>> result(maxDegree + 1, defaultFraction);

    for (int i = 0; i <= maxDegree; i++)
    {
        result[i] = subtractFractions(
            i < polynomialP.size() ? polynomialP[i] : defaultFraction,
            i < polynomialQ.size() ? polynomialQ[i] : defaultFraction);
    }

    return result;
}

void multiplyPolynomialByRationalNumber()
{
    std::vector<std::pair<int, int>> polynomial = readPolynomial('P');

    std::cout << "Enter rational number>> ";
    const std::pair<int, int> fraction = readFraction();

    for (int i = 0; i < polynomial.size(); i++)
    {
        polynomial[i] = multiplyFractions(polynomial[i], fraction);
    }

    std::cout << "Result: ";
    printPolynomial(TERMINATE_SYMBOL, polynomial);
}

void evaluatePolynomial()
{
    std::vector<std::pair<int, int>> polynomial = readPolynomial('P');

    std::cout << "Enter rational number>> ";
    const std::pair<int, int> fraction = readFraction();

    std::pair<int, int> powers = { 1, 1 };
    std::pair<int, int> polynomialValue = { 0, 1 };

    for (int i = 0; i < polynomial.size(); i++)
    {
        if (i > 0)
        {
            powers = multiplyFractions(powers, fraction);
        }

        std::pair<int, int> term = multiplyFractions(polynomial[i], powers);
        polynomialValue = addFractions(polynomialValue, term);
    }

    std::cout << "P(";
    printFraction(fraction);
    std::cout << ") = ";
    printFraction(polynomialValue);
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
    std::vector<std::pair<int, int>> secondPolynomial = readPolynomial('Q');

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

void displayVietasFormula()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');

    const int degree = polynomialP.size() - 1;

    if (degree < 1)
    {
        std::cout << "Vieta's formulas cannot be applied to a polynomial of degree less than 1." << std::endl;
        return;
    }

    std::cout << "Vieta's Formulas for polynomial: P(x) = ";
    printPolynomial('P', polynomialP);

    std::pair<int, int> leadingCoefficient = polynomialP[degree];

    if (leadingCoefficient.first == 0)
    {
        std::cout << "Invalid polynomial: Leading coefficient cannot be zero." << std::endl;
        return;
    }

    for (int i = 1; i <= degree; i++)
    {
        std::pair<int, int> coefficient = polynomialP[degree - i];

        std::pair<int, int> vietaTerm = divideFractions(coefficient, leadingCoefficient);

        if (i % 2 == 1)
        {
            vietaTerm.first = -vietaTerm.first;
        }

        std::cout << "sigma_" << i << " = ";
        printFraction(vietaTerm);
        std::cout << std::endl;
    }
}

void dividePolynomials()
{
    std::vector<std::pair<int, int>> polynomialA = readPolynomial('A');
    std::vector<std::pair<int, int>> polynomialB = readPolynomial('B');

    if (polynomialB.size() == 1 && polynomialB[0].first == 0)
    {
        std::cout << "Invalid input! Division by zero polynomial is not allowed. Try again>> " << std::endl;
        return;
    }

    int degreeA = polynomialA.size() - 1;
    int degreeB = polynomialB.size() - 1;

    if (degreeA < degreeB)
    {
        std::cout << "Invalid input! Division by zero polynomial is not allowed. Try again>> " << std::endl;

        return;
    }

    std::vector<std::pair<int, int>> polynomialQ((polynomialA.size() - 1 - degreeB) + 1, { 0, 1 });
    std::vector<std::pair<int, int>> polynomialR = polynomialA;

    while (!polynomialR.empty() && polynomialR.size() > polynomialB.size() - 1)
    {
        int degreeR = polynomialR.size() - 1;

        std::pair<int, int> leadingTermQ = divideFractions(polynomialR.back(), polynomialB.back());
        int termDegreeQ = degreeR - degreeB;

        polynomialQ[termDegreeQ] = leadingTermQ;

        std::vector<std::pair<int, int>> termProduct(polynomialR.size(), { 0, 1 });
        for (int i = 0; i < polynomialB.size(); i++)
        {
            termProduct[termDegreeQ + i] = multiplyFractions(polynomialB[i], leadingTermQ);
        }

        polynomialR = subtractPolynomials(polynomialR, termProduct);

        while (!polynomialR.empty() && polynomialR.back().first == 0)
        {
            polynomialR.pop_back();
        }
    }

    std::cout << "Quotient ";
    printPolynomial('Q', polynomialQ);
    std::cout << "Remainder ";
    printPolynomial('R', polynomialR);
}
