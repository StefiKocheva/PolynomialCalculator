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
* Header: Declares functions for fraction operations, mathematical utilities, and input validation.
*
*/

#pragma once

std::pair<int, int> readFraction();

std::pair<int, int> addFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB);

std::pair<int, int> subtractFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB);

std::pair<int, int> multiplyFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB);

std::pair<int, int> divideFractions(std::pair<int, int> fractionA, std::pair<int, int> fractionB);

std::pair<int, int> simplifyFraction(int numerator, int denominator);

void printFraction(const std::pair<int, int>& fraction);

int min(int a, int b);

int max(int a, int b);

int absolute(int a);

int gcd(int a, int b);

int lcm(int a, int b);

const char* skipWhitespace(const char* str);

int arrToInteger(const char* str);

int readInteger(bool nonNegativeOnly);

int readNonNegativeInteger();

bool isValidNumber(const char* str, bool nonNegativeOnly);
