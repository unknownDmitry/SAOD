//Савин Дмитрий, ИВТ-22

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using std::string;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Заполняет массив случайными отсортированными по возрастанию значениями.
 * @param arr Массив для заполнения.
 * @param size Размер массива.
 * @param minValue Минимальное значение первого элемента (по умолчанию 0).
 * @param maxStep Максимальный шаг между соседними элементами (по умолчанию 10).
 */
template <typename T>
void fill_rand_arr(T arr[], long long size, T minValue = 0, T maxStep = 10) {

	if (size <= 0) return;


	// Первый элемент
	arr[0] = minValue + rand() % (maxStep + 1);

	// Заполняем остальные элементы
	for (long long i = 1; i < size; i++) {
		// Добавляем случайный положительный шаг к предыдущему элементу
		arr[i] = arr[i - 1] + 1 + rand() % maxStep;
	}
}

/**
 * @brief Сохраняет массив в бинарный файл.
 * @param arr Массив для сохранения.
 * @param size Размер массива.
 * @param filename Имя файла.
 * @throws std::runtime_error При ошибке открытия файла для записи.
 */
template <typename T>
void save_in_file(T arr[], long long size, const string& filename)
{
	ofstream outfile(filename, std::ios::binary);
	if (!outfile.is_open()) {
		throw std::runtime_error("Can't open file for recording");
	}
	outfile.write(reinterpret_cast<char*>(arr), static_cast<std::streamsize>(size) * sizeof(T));
	outfile.close();
}

/**
 * @brief Проверяет, отсортирован ли массив по возрастанию.
 * @param arr Массив для проверки.
 * @param size Размер массива.
 * @return true, если массив отсортирован по возрастанию, иначе false.
 */
template <typename T>
bool is_sorted(T arr[], long long size)
{
	for (long long i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

/**
 * @brief Линейный (последовательный) поиск элемента в массиве.
 * @brief Лучший случай: O(1), средний и худший: O(n).
 * @param arr Массив для поиска.
 * @param size Размер массива.
 * @param target Искомый элемент.
 * @return Индекс найденного элемента или -1, если не найден.
 */
template <typename T>
long long seek_run(T arr[], long long size, T target)
{
	for (long long i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

/**
 * @brief Бинарный (двоичный) поиск элемента в отсортированном массиве.
 * @brief Лучший случай: O(1), средний и худший: O(log n).
 * @param arr Отсортированный массив.
 * @param size Размер массива.
 * @param target Искомый элемент.
 * @return Индекс найденного элемента или -1, если не найден.
 */
template <typename T>
long long binary_seek(T arr[], long long size, T target)
{
	long long left = 0;
	long long right = size - 1;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

/**
 * @brief Интерполяционный поиск элемента в отсортированном массиве.
 * @brief Лучший случай: O(1), средний: O(log log n), худший: O(n).
 * @param arr Отсортированный массив.
 * @param size Размер массива.
 * @param target Искомый элемент.
 * @return Индекс найденного элемента или -1, если не найден.
 */
template <typename T>
long long interpol_seek(T arr[], long long size, T target)
{
	long long low = 0, high = size - 1;

	while (low <= high && target >= arr[low] && target <= arr[high]) {
		if (arr[high] == arr[low]) {
			if (arr[low] == target) return low;
			return -1;
		}

		long long pos = low + ((long long)(target - arr[low]) * (high - low)) /
			(arr[high] - arr[low]);

		if (pos < low) pos = low;
		if (pos > high) pos = high;

		if (arr[pos] == target) return pos;
		if (arr[pos] < target) low = pos + 1;
		else high = pos - 1;
	}
	return -1;
}