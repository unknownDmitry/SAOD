//Савин Дмитрий, ИВТ-22

#include <iostream>
#include <chrono>
#include "Task1.h"

using namespace std::chrono;
using std::cout;

int main()
{

	// Инициализация генератора случайных чисел(лучше инициализировать один раз)
	srand(static_cast<unsigned int>(time(nullptr)));

	// Создание и заполнение массива
	long long size = 100'000'000;
	long long* arr = new long long[size];
	
	auto t_fill_start = steady_clock::now();
	fill_rand_arr(arr, size);
	auto t_fill_end = steady_clock::now();
	auto delta_arr = duration_cast<seconds>(t_fill_end - t_fill_start);
	cout << "Array creation " << delta_arr.count() << "s" << endl << endl;

	// Проверка сортировки массива
	auto t_sorted_start = steady_clock::now();
	int sorted = is_sorted(arr, size);
	auto t_sorted_end = steady_clock::now();
	auto delta_sorted = duration_cast<seconds>(t_sorted_end - t_sorted_start);
	if (sorted == 0) {
		cout << "Array isn't sorted " << delta_sorted.count() << "s" << endl;
	}
	else if(sorted == -1){
		cout << "Array is sorted " << delta_sorted.count() << "s" << endl;
	}
	else {
		cout << "Array is sorted " << delta_sorted.count() << "s" << endl;
	}
	
	// Выбор целевого элемента из 3/3 массива для поиска
	long long target = arr[2 * size / 3];
	long long found;

	// Замер времени линейного поиска
	auto t_seek_start = steady_clock::now();
	found = seek_run(arr, size, target);
	auto t_seek_end = steady_clock::now();

	// Замер времени бинарного поиска
	auto t_bin_start = steady_clock::now();
	found = binary_seek(arr, size, target);
	auto t_bin_end = steady_clock::now();

	// Замер времени интерполяционного поиска
	auto t_interpol_start = steady_clock::now();
	found = interpol_seek(arr, size, target);
	auto t_interpol_end = steady_clock::now();

	// Вывод результатов поиска и времени выполнения
	if (found != -1) {
		cout << "\nNumber " << target << " was found on position: " << found << endl;
		auto delta_seek = duration_cast<nanoseconds>(t_seek_end - t_seek_start);
		cout << "\nseek_run function: " << delta_seek.count()<< " nanoseconds" << endl;
		auto delta_binary = duration_cast<nanoseconds>(t_bin_end - t_bin_start);
		cout << "binary_seek function: " << delta_binary.count() << " nanoseconds" << endl;
		auto delta_interpol = duration_cast<nanoseconds>(t_interpol_end - t_interpol_start);
		cout << "interpol_seek function: " << delta_interpol.count() << " nanoseconds" << endl;
	}
	else {
		cout << "Number " << target << " was not found" << endl;
	}

	// Сохранение массива в файл
	auto t_save_start = steady_clock::now();
	save_in_file(arr, size, "ARRAY.txt");
	auto t_save_end = steady_clock::now();
	auto delta_save = duration_cast<seconds>(t_save_end - t_save_start);
	cout << "\nArray saved in file " << delta_save.count() << "s" << endl;

	// Освобождение памяти
	delete[] arr;
	return 0;
} 