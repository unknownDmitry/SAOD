#pragma once

#include "DList.h"

/**
 * @brief Шаблонный класс очереди (FIFO), реализованный на базе двусвязного списка DList.
 * @tparam T Тип элементов, хранимых в очереди.
 */
template<typename T>
class Queue {
private:
	/**
	 * @brief Внутреннее хранилище элементов очереди.
	 */
	DList<T> list;

public:

	/**
	 * @brief Добавляет элемент в конец очереди.
	 * @param value значение, которое нужно поместить в очередь.
	 */
	void enqueue(T value) {
		list.push_back(value);
	}

	/**
	 * @brief Удаляет элемент из начала очереди.
	 * 
	 * Предполагается, что очередь не пуста.
	 * Поведение при вызове для пустой очереди зависит от реализации DList::pop_front().
	 */
	void dequeue() {
		list.pop_front();
	}

	/**
	 * @brief Возвращает значение элемента в начале очереди без его удаления.
	 * @return Значение первого элемента очереди.
	 * 
	 * Предполагается, что очередь не пуста.
	 */
	T front() {
		return list.front();
	}

	/**
	 * @brief Возвращает текущее количество элементов в очереди.
	 * @return Размер очереди (число элементов).
	 */
	int size() const {
		return list.get_size();
	}

	/**
	 * @brief Проверяет, пуста ли очередь.
	 * @return true, если очередь не содержит элементов, иначе false.
	 */
	bool empty() const {
		return list.empty();
	}
};

