#include "recursion.h"

// Реализация алгоритма Евклида для вычисления НОД
int gcd(int x, int y)
{
	if (y == 0) return x;
	return abs(gcd(y, x % y));
}

// Выполнение тестовых проверок функции gcd
void tests() {
	assert(gcd(16, 4) == 4);
	assert(gcd(-3, 7) == 1);
	assert(gcd(7, 7) == 7);
	assert(gcd(65345700, 1240085685) == 15);
	assert(gcd(19, 31) == 1);
	cout << "All tests passed" << endl;
}