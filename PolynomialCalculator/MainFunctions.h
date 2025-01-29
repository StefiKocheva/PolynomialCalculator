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

#pragma once

#include <vector>

std::vector<std::pair<int, int>> readPolynomial(char name);

int readPolynomialDegree();

void addPolynomials();

void subtractPolynomials();

void multiplyPolynomialByScalar();

void multiplyPolynomials();

void evaluatePolynomial();

void printPolynomial(char name, const std::vector<std::pair<int, int>>& polynomial);
