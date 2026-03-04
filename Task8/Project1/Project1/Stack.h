#pragma once

template<typename T>
class Stack {
private:
	/**
	@brief Внутреннее хранилище элементов стека.
	 */
	List<T> list;
public:

	/**
	 @brief Добавляет элемент на вершину стека.
	 @param value Значение, которое нужно поместить в стек.
	 */
	void push(T value) {
		list.push_front(value);
	}
	
	/**
	 @brief Удаляет элемент с вершины стека.
	 */
	void pop() {
		list.pop_front();
	}

	/**
	 @brief Возвращает значение элемента на вершине стека без его удаления.
	 @return Значение верхнего элемента стека.
	 */
	T top() {
		return list[0];
	}

	/**
	 * @brief Возвращает текущее количество элементов в стеке.
	 * @return Размер стека.
	 */
	int size() {
		return list.get_size();
	}

	/**
	 * @brief Проверяет, пуст ли стек.
	 * @return true, если стек не содержит элементов, иначе false.
	 */
	bool empty() {
		return list.get_size() == 0;
	}

};