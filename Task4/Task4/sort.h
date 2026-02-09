#pragma once

/*
@brief сортировка пузырьком по возрастанию
@brief средняя сложность O(n2)
@param int arr[] массив элементов 
@param int size размер массива
@return void
*/
void bubbleSort(int arr[], int size);

/*
@brief слияние двух отсортированных массивов в один
@brief сложность O(n + m), где n и m - размеры массивов
@param const int arr1[] первый отсортированный массив
@param int size1 размер первого массива
@param const int arr2[] второй отсортированный массив
@param int size2 размер второго массива
@param int result_arr[] результирующий массив
@return void
*/
void merge(const int arr1[], int size1, const int arr2[], int size2, int result_arr[]);

/*
@brief сортировка слиянием
@brief средняя сложность O(n log n)
@param int arr[] массив элементов
@param int size размер массива
@return void
*/
void mergeSort(int arr[], int size);

/*
@brief быстрая сортировка (сортировка Хоара)
@brief средняя сложность O(n log n)
@param int a[] массив элементов
@param int left левая граница сортируемого участка
@param int right правая граница сортируемого участка
@return void
*/
void quickSort(int a[], int left, int right);

/*
@brief сортировка Шелла
@brief средняя сложность O(n^1.5)
@param int arr[] массив элементов
@param int size размер массива
@return void
*/
void shellSort(int arr[], int size);

/*
@brief заполнение массива случайными числами
@brief сложность O(n)
@param int arr[] массив для заполнения
@param int size размер массива
@return void
*/
void fillRandArray(int arr[], int size);

/*
@brief вывод массива на экран
@brief сложность O(n)
@param int arr[] массив для вывода
@param int size размер массива
@return void
*/
void printArray(int arr[], int size);

/*
@brief копирование элементов из одного массива в другой
@brief сложность O(n)
@param src[] исходный массив
@param dest[] массив назначения
@param size размер массивов
@return void
*/
void copyArray(int src[], int dest[], int size);