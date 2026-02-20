//Савин Дмитрий, ИВТ-22

#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

/*
@brief Шаблонный класс динамический массив
*/
template<typename T>
class VECTOR {

private:

	T* data; // Указатель на динамический массив
	size_t size; // Количество элементов в массиве 
	size_t capacity; // Размер выделенной памяти под массив

	/*
	@brief Изменение памяти под массив
	@param new_capacity новый размер памяти
	*/
	void resize(size_t new_capacity) {
		T* new_data = new T[new_capacity];
		for (size_t i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}


public:

	/*
	@brief Конструктор по умолчанию
	*/
	VECTOR() {
		this->data = nullptr;
		this->size = 0;
		this->capacity = 0;
	};

	/*
	@brief Деструктор. Освобождает память, занятую массивом
	*/
	~VECTOR() {
		delete[] data;
	}


	/*
	@brief Добавляет элемент в конец массива
	@brief Если вместимость недостаточна, увеличивает её на 2
	@param const T& value - значение элемента для вставки 
	*/
	void push_back(const T& value){
		if(size == capacity){
			size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
			resize(new_capacity);
		}
		data[size] = value;
		size++;
	}

	/*
	@brief Удаляет последний элемент массива
	*/
	void pop_back(){
		if(size > 0){
			size--;
		}
	}

	/*
	@brief Очищает массив
	@brief Устанавливает количество элементов в 0, вместимость массива не изменяется
	*/
	void clear() {
		size = 0;
	}

	/*
	@brief Возвращает текущий размер массива
	@return size_t: Количество элементов в массиве
	*/
	size_t get_size() const{
		return size;
	}

	/*
	@brief Возвращает текущую вместимость массива
	@return size_t: Размер выделенной памяти под массив
	*/
	size_t get_capacity() const{
		return capacity;
	}

	/*
	@brief Проверяет, пуст ли вектор
	@return true: Если вектор не содержит элементов
	@return false: Если вектор содержит хотя бы один элемент
	*/
	bool empty() const{
		return size == 0;
	}

	/*
	@brief Выводит содержимое вектора в консоль
	*/
	void print() const {
		for (size_t i = 0; i < size; i++) {
			std::cout << data[i];
			if (i < size - 1) {
				std::cout << " ";
			}
		}
	}


	/*
	@brief Сортировка пузырьком по возрастанию
	@brief Сложность O(n^2)
	*/
	void bubble_sort() {
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size - i - 1; j++) {
				if (data[j] > data[j + 1]) {
					std::swap(data[j], data[j + 1]);
				}
			}
		}
	}

};