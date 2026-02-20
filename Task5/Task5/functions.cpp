#include "functions.h"

//  Вычисление значений треугольника Паскаля снизу вверх
void comp_pascal(int arr[MAX_SIZE][MAX_SIZE], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		arr[i][0] = 1;	//	левый край
		arr[i][i] = 1;	//	правый край
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];  //	формула для нового элемента
		}
	}
}

//  Вывод треугольника Паскаля в консоль
void print_array(int arr[MAX_SIZE][MAX_SIZE], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//  Сохранение треугольника Паскаля в файл
void save_to_file(int arr[MAX_SIZE][MAX_SIZE], int SIZE, std::string& path) {
	std::ofstream out(path);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			out << arr[i][j] << " ";
		}
		out << std::endl;
	}

	out.close();
}

//  Чтение размера массива из файла для треугольника Паскаля
int read_from_file(std::string& path) {
	std::ifstream in(path);
	int size;
	in >> size;
	return size;
}