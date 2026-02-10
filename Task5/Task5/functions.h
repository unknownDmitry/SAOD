//Савин Дмитрий

#pragma once
#include <iostream>
#include <fstream>

const int MAX_SIZE = 31;

/*
@brief Вычисление значений треугольника Паскаля снизу вверх
@param int arr - массив чисел
@param int SIZE - количество элементов массива
*/
void comp_pascal(int arr[MAX_SIZE][MAX_SIZE], int SIZE);
/*
@brief Вывод треугольника Паскаля в консоль
@param int arr - массив чисел
@param int SIZE - количество элементов массива
*/
void print_array(int arr[MAX_SIZE][MAX_SIZE], int SIZE);
/*
@brief Сохранение треугольника Паскаля в файл
@param int arr - массив чисел
@param int SIZE - количество элементов массива
@param string path - путь в файлу
*/
void save_to_file(int arr[MAX_SIZE][MAX_SIZE], int SIZE, std::string& path);
/*
@brief Чтение размера массива из файла для треугольника Паскаля
@param string path - путь в файлу
@return int size - количество элементов массива
*/
int read_from_file(std::string& path);