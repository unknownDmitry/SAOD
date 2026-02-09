#pragma once
#include <string>
#include <fstream>
#include <cassert>

using std::string;
using std::ifstream;

/**
 * @brief Подсчитывает количество строчных букв в текстовом файле.
 * @param file_name Ссылка на строку с именем файла.
 * @return Количество строчных букв в файле.
 * @throws std::invalid_argument Если файл не найден.
 */
int count_let(string& file_name);

/**
 * @brief Запускает тесты функции count_let на файлах test1.txt, test2.txt, test3.txt.
 */
void test();