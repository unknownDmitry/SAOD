//Савин Дмитрий, ИВТ-22

#include <iostream>
#include "recursion.h"


int main()
{
	tests();
	int x, y;
	
	do {
		cout << "Enter two values: ";
		cin >> x >> y;
		if (x == 0 || y == 0) {
			cout << "Values can't equal to zero" << endl << endl;
		}
	} while (x == 0 || y == 0);

	cout << "\nThe greatest common divisor is: " << gcd(x, y) << endl;

	return 0;
}