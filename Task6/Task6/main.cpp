//Савин Дмитрий, ИВТ-22

#include <iostream>
#include "VECTOR.h"

int main() {

	VECTOR<int> vect;
	vect.push_back(5);
	vect.push_back(2);
	vect.push_back(8);
	vect.push_back(1);
	vect.push_back(9);
	vect.push_back(3);

	std::cout << "До сортировки: ";
	vect.print();
	std::cout << std::endl;

	vect.bubble_sort();

	std::cout << "После сортировки: ";
	vect.print();
	std::cout << std::endl;

	return 0;
}