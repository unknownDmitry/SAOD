#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include "sort.h"


int main()
{
	int sizes[] = { 1000, 2000, 3000, 4000, 5000, 7000, 10000 };
	int numSizes = sizeof(sizes) / sizeof(sizes[0]);

	std::ofstream file("../Graph/results.csv");
	file << "size,bubble,merge,quick,shell\n";

	srand(42);

	for (int s = 0; s < numSizes; s++) {
		int size = sizes[s];
		std::cout << "Размер: " << size << std::endl;

		int* arr = new int[size];
		int* temp = new int[size];

		// Заполняем случайными числами
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100000;
		}

		file << size;

		// Bubble Sort
		copyArray(arr, temp, size);
		auto start = std::chrono::high_resolution_clock::now();
		bubbleSort(temp, size);
		auto end = std::chrono::high_resolution_clock::now();
		double bubbleTime = std::chrono::duration<double>(end - start).count();
		file << "," << bubbleTime;
		std::cout << "  Bubble: " << bubbleTime << " сек" << std::endl;

		// Merge Sort
		copyArray(arr, temp, size);
		start = std::chrono::high_resolution_clock::now();
		mergeSort(temp, size);
		end = std::chrono::high_resolution_clock::now();
		double mergeTime = std::chrono::duration<double>(end - start).count();
		file << "," << mergeTime;
		std::cout << "  Merge: " << mergeTime << " сек" << std::endl;

		// Quick Sort
		copyArray(arr, temp, size);
		start = std::chrono::high_resolution_clock::now();
		quickSort(temp, 0, size - 1);
		end = std::chrono::high_resolution_clock::now();
		double quickTime = std::chrono::duration<double>(end - start).count();
		file << "," << quickTime;
		std::cout << "  Quick: " << quickTime << " сек" << std::endl;

		// Shell Sort
		copyArray(arr, temp, size);
		start = std::chrono::high_resolution_clock::now();
		shellSort(temp, size);
		end = std::chrono::high_resolution_clock::now();
		double shellTime = std::chrono::duration<double>(end - start).count();
		file << "," << shellTime;
		std::cout << "  Shell: " << shellTime << " сек" << std::endl;

		file << "\n";

		delete[] arr;
		delete[] temp;
	}

	file.close();
	std::cout << "\nРезультаты сохранены в Graph/results.csv" << std::endl;

	return 0;
}
