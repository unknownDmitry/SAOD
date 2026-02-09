#include "sort.h"
#include <iostream>
#include <ctime>

void bubbleSort(int arr[], int size)
{
	// Проходим по массиву size-1 раз
	for (int i = 0; i < size - 1; i++)
	{
		// На каждом проходе "всплывает" максимальный элемент в конец
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				//std::swap(arr[j], arr[j + 1]);
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void merge(const int arr1[], int size1, const int arr2[], int size2, int result_arr[])
{
	int i = 0, j = 0, k = 0;

	// Сравниваем элементы двух массивов и записываем меньший
	while (i < size1 && j < size2)
	{
		if (arr1[i] <= arr2[j])
		{
			result_arr[k] = arr1[i];
			i++;
		}
		else
		{
			result_arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	// Дописываем оставшиеся элементы
	while (i < size1)
		result_arr[k++] = arr1[i++];

	while (j < size2)
		result_arr[k++] = arr2[j++];
}

void mergeSort(int arr[], int size)
{
	if (size <= 1)
		return; 
	int mid = size / 2;

	// Разделяем массив на две половины
	int* left = new int[mid];
	int* right = new int[size];
	
	// Заполняем левый подмассив 
	for (int i = 0; i < mid; i++) {
		left[i] = arr[i];
	}
	// Заполняем правый подмассив
	for (int i = mid; i < size; i++) {
		right[i-mid] = arr[i];
	}

	// Рекурсивно сортируем обе половины
	mergeSort(left, mid);
	mergeSort(right, size-mid);

	// Сливаем отсортированные половины
	merge(left, mid, right, size-mid, arr);

	delete[] left;
	delete[] right;
}

void quickSort(int a[], int left, int right)
{
	if (left > right) return;
	
	int pivot = a[(left + right) / 2];  // Опорный элемент - средний
	int i = left;
	int j = right;
	
	// Разделение: элементы < pivot слева, > pivot справа
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	
	// Рекурсивно сортируем левую и правую части
	quickSort(a, left, j);
	quickSort(a, i, right);
}

void shellSort(int arr[], int size)
{
	// Начинаем с большого шага, постепенно уменьшаем вдвое
	for (int gap = size/2; gap > 0; gap/=2)
	{
		// Сортировка вставками с шагом gap
		for (int i = gap; i < size; i++)
		{
			int temp = arr[i];
			int j;

			// Сдвигаем элементы, пока не найдём место для temp
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void fillRandArray(int arr[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Копирование массива
void copyArray(int src[], int dest[], int size) {
	for (int i = 0; i < size; i++) {
		dest[i] = src[i];
	}
}