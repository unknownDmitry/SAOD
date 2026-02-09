#pragma once

#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief Вычисляет наибольший общий делитель (НОД) двух целых чисел
 * @param x Первое целое число
 * @param y Второе целое число
 * @return Наибольший общий делитель чисел x и y
 */
int gcd(int x, int y);

/**
 * @brief Выполняет набор тестов для функции gcd
 * Проверяет корректность работы алгоритма на различных входных данных
 */
void tests();