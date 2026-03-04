#pragma once

#include <cassert>
#include "Stack.h"

/**
 * @brief Функция для тестирования стека
 */
void test_stack()
{
	Stack<int> st;

	// Новый стек должен быть пустым
	assert(st.empty());
	assert(st.size() == 0);

	// Добавляем один элемент
	st.push(42);
	assert(!st.empty());
	assert(st.size() == 1);
	assert(st.top() == 42);

	// Добавляем несколько элементов
	st.push(100);
	st.push(-5);
	assert(st.size() == 3);
	assert(st.top() == -5); // последний добавленный должен быть на вершине

	// Проверяем pop и корректность top
	st.pop();
	assert(st.size() == 2);
	assert(st.top() == 100);

	st.pop();
	assert(st.size() == 1);
	assert(st.top() == 42);

	// Удаляем последний элемент
	st.pop();
	assert(st.size() == 0);
	assert(st.empty());
}

