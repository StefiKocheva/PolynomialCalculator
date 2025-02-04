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
* Source: Implements polynomial operations, including arithmetic, evaluation, differentiation, and GCD computation.
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

    char degree[MAX_INTEGER_SIZE];
    std::cin >> degree;

    if (!isValidNumber(degree, true))
    {
        std::cout << "Error: Invalid degree! Try again... " << std::endl;

        return readPolynomialDegree();
    }

    return arrToInteger(degree);
}

void addPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    std::vector<std::pair<int, int>> polynomialQ = readPolynomial('Q');

    const int maxDegree = max(polynomialP.size() - 1, polynomialQ.size() - 1);
    const std::pair<int, int> defaultFrac = { 0, 1 };
    std::vector<std::pair<int, int>> polynomialS(maxDegree + 1, defaultFrac);

    for (int i = 0; i <= maxDegree; i++)
    {
        std::pair<int, int> termP = (i < polynomialP.size()) ? polynomialP[i] : defaultFrac;
        std::pair<int, int> termQ = (i < polynomialQ.size()) ? polynomialQ[i] : defaultFrac;

        polynomialS[i] = addFractions(termP, termQ);
    }

    std::cout << "P(x)+Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, polynomialS);
}

void subtractPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    std::vector<std::pair<int, int>> polynomialQ = readPolynomial('Q');

    std::vector<std::pair<int, int>> polynomialD = subtractPolynomials(polynomialP, polynomialQ);

    std::cout << "P(x)-Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, polynomialD);
}

std::vector<std::pair<int, int>> subtractPolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>>& polynomialQ)
{
    const int maxDegree = max(polynomialP.size() - 1, polynomialQ.size() - 1);
    const std::pair<int, int> defaultFrac = { 0, 1 };
    std::vector<std::pair<int, int>> polynomialD(maxDegree + 1, defaultFrac);

    for (int i = 0; i <= maxDegree; i++)
    {
        std::pair<int, int> termP = (i < polynomialP.size()) ? polynomialP[i] : defaultFrac;
        std::pair<int, int> termQ = (i < polynomialQ.size()) ? polynomialQ[i] : defaultFrac;

        polynomialD[i] = subtractFractions(termP, termQ);
    }

    return polynomialD;
}

void multiplyPolynomials()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    std::vector<std::pair<int, int>> polynomialQ = readPolynomial('Q');

    int degreeResult = (polynomialP.size() - 1) + (polynomialQ.size() - 1);
    std::vector<std::pair<int, int>> result(degreeResult + 1, { 0, 1 });

    for (int i = 0; i < polynomialP.size(); i++)
    {
        for (int j = 0; j < polynomialQ.size(); j++)
        {
            std::pair<int, int> fractionProfuct = multiplyFractions(polynomialP[i], polynomialQ[j]);

            result[i + j] = addFractions(result[i + j], fractionProfuct);
        }
    }

    std::cout << "P(x)*Q(x) = ";
    printPolynomial(TERMINATE_SYMBOL, result);
}

void dividePolynomials()
{
    std::vector<std::pair<int, int>> polynomialA = readPolynomial('A');
    std::vector<std::pair<int, int>> polynomialB = readPolynomial('B');

    int degreeA = polynomialA.size() - 1;
    int degreeB = polynomialB.size() - 1;

    if (!isDivisionPossible(polynomialB, degreeA, degreeB))
    {
        return dividePolynomials();
    }

    std::vector<std::pair<int, int>> polynomialQ((degreeA - degreeB) + 1, { 0, 1 });
    std::vector<std::pair<int, int>> polynomialR = polynomialA;

    while (!polynomialR.empty() && polynomialR.size() > degreeB)
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

bool isDivisionPossible(const std::vector<std::pair<int, int>>& polynomialB, int degreeA, int degreeB)
{
    if (polynomialB.size() == 1 && polynomialB[0].first == 0)
    {
        std::cout << "Error: Division by zero! Try again..." << std::endl;

        return false;
    }

    if (degreeA < degreeB)
    {
        std::cout << "Error: Degree of A(x) < Degree of B(x)! Try again..." << std::endl;

        return false;
    }

    return true;
}

void multiplyPolynomialByScalar()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');

    std::cout << "Enter rational number>> ";
    const std::pair<int, int> fractionB = readFraction();

    for (int i = 0; i < polynomialP.size(); i++)
    {
        polynomialP[i] = multiplyFractions(polynomialP[i], fractionB);
    }

    std::cout << "Result: ";
    printPolynomial(TERMINATE_SYMBOL, polynomialP);
}

void evaluatePolynomial()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');

    std::cout << "Enter rational number>> ";
    const std::pair<int, int> fraction = readFraction();

    std::pair<int, int> currentMultiplier = { 1, 1 };
    std::pair<int, int> valuePolynomialP = { 0, 1 };

    for (int i = 0; i < polynomialP.size(); i++)
    {
        if (i > 0)
        {
            currentMultiplier = multiplyFractions(currentMultiplier, fraction);
        }

        std::pair<int, int> term = multiplyFractions(polynomialP[i], currentMultiplier);

        valuePolynomialP = addFractions(valuePolynomialP, term);
    }

    std::cout << "P(";
    printFraction(fraction);
    std::cout << ") = ";
    printFraction(valuePolynomialP);
    std::cout << std::endl;
}

void displayVietasFormulas()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');
    const int degreeP = polynomialP.size() - 1;

    if (degreeP < 1)
    {
        std::cout << "Error: Degree of P(x) < 1! Try again..." << std::endl;

        return displayVietasFormulas();
    }

    std::cout << "Vieta's Formulas for polynomial: ";
    printPolynomial('P', polynomialP);

    std::pair<int, int> leadingCoefficient = polynomialP[degreeP];

    for (int i = 1; i <= degreeP; i++)
    {
        std::pair<int, int> currentCoeff = polynomialP[degreeP - i];
        std::pair<int, int> currentRoot = divideFractions(currentCoeff, leadingCoefficient);

        if (i % 2 == 1)
        {
            currentRoot.first = -currentRoot.first;
        }

        std::cout << "s_" << i << " = ";
        printFraction(currentRoot);
        std::cout << std::endl;
    }
}

void findKthDerivative()
{
    std::vector<std::pair<int, int>> polynomialP = readPolynomial('P');

    std::cout << "Enter k>> ";
    const int k = readInteger(true);

    if (k != 0)
    {
        polynomialP = computeKthDerivative(polynomialP, k);

    }

    std::cout << "P^("<< k <<")(x) = ";
    printPolynomial(TERMINATE_SYMBOL, polynomialP);
}

std::vector<std::pair<int, int>> computeKthDerivative(std::vector<std::pair<int, int>> polynomialP, const int k)
{
    int degreeP = polynomialP.size() - 1;

    if (k > degreeP)
    {
        return {{ 0, 1 }};
    }

    for (int d = 1; d <= k; d++)
    {
        std::vector<std::pair<int, int>> derivative(degreeP, { 0, 1 });

        for (int i = 1; i <= degreeP; i++)
        {
            std::pair<int, int> coef = polynomialP[i];
            std::pair<int, int> multiplier = { i, 1 };

            derivative[i - 1] = multiplyFractions(coef, multiplier);
        }

        polynomialP = derivative;
        degreeP--;
    }

    return polynomialP;
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

        if (numerator < 0)
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
