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
* Header: Declares functions for polynomial arithmetic, evaluation, differentiation, and GCD computation.
*
*/

#pragma once

#include <vector>

std::vector<std::pair<int, int>> readPolynomial(char name);

int readPolynomialDegree();

void addPolynomials();

void subtractPolynomials();

std::vector<std::pair<int, int>> subtractPolynomials(std::vector<std::pair<int, int>>& polynomialP, std::vector<std::pair<int, int>>& polynomialQ);

void multiplyPolynomials();

void dividePolynomials();

bool isDivisionPossible(const std::vector<std::pair<int, int>>& polynomialB, int degreeA, int degreeB);

//std::pair<int, int> computeLeadingTermQuotient(std::pair<int, int>& remainderTerm, std::pair<int, int>& divisorTerm);

//std::vector<std::pair<int, int>> computeTermProduct(std::vector<std::pair<int, int>>& polynomialB, std::pair<int, int>& leadingTermQ, int termDegreeQ);

//std::vector<std::pair<int, int>> updateRemainder(std::vector<std::pair<int, int>>& remainder, std::vector<std::pair<int, int>>& termProduct);

void multiplyPolynomialByScalar();

void displayVietasFormulas();

void findKthDerivative();

std::vector<std::pair<int, int>> computeKthDerivative(std::vector<std::pair<int, int>> polynomialP, int k);

void evaluatePolynomial();

void printPolynomial(char name, const std::vector<std::pair<int, int>>& polynomial);

void printTerm(int numerator, int denominator, int exponent);
