﻿/**
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

int min(int a, int b);

int max(int a, int b);

int abs(int a);

int gcd(int a, int b);

int lcm(int a, int b);

int arrToInteger(char* str);

std::pair<int, int> readFraction();

std::pair<int, int> addFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB);

std::pair<int, int> subtractFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB);

std::pair<int, int> multiplyFractions(const std::pair<int, int> fractionA, const std::pair<int, int> fractionB);

std::pair<int, int> simplifyFraction(int numerator, int denominator);

void printFraction(const std::pair<int, int>& fraction);

bool isValidInteger(char* str);

bool isValidDegree(char* degree);
