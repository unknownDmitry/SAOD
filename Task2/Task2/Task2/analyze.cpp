#include "analyze.h"

/**
 * @brief Подсчитывает количество строчных букв в текстовом файле.
 * @param file_name Ссылка на строку с именем файла.
 * @return Количество строчных букв в файле.
 * @throws std::invalid_argument Если файл не найден.
 */
int count_let(string& file_name)
{
	int count{};
	char tmp{};
	ifstream file_read(file_name);

	if (file_read.is_open())
	{
		while (file_read.get(tmp))
		{
			if (islower(tmp)) count++;
		}
	}
	else throw std::invalid_argument("No such file in directory");
	file_read.close();

	return count;
}

/**
 * @brief Запускает тесты функции count_let на файлах test1.txt, test2.txt, test3.txt.
 */
void test()
{
	string file_name("test1.txt");
	assert(count_let(file_name) == 4);  // "abcd" - 4 строчные буквы
	
	file_name = "test2.txt";
	assert(count_let(file_name) == 4);  // "ABcd ef" - 4 строчные буквы (c, d, e, f)
	
	file_name = "test3.txt";
	assert(count_let(file_name) == 4);  // "aa bb" - 4 строчные буквы (a, a, b, b)
}