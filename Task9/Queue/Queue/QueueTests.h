#pragma once

#include <cassert>
#include "Queue.h"

/**
 * @brief Функция для тестирования очереди.
 */
void test_queue()
{
	Queue<int> q;

	// Новая очередь должна быть пустой
	assert(q.empty());
	assert(q.size() == 0);

	// Добавляем один элемент
	q.enqueue(42);
	assert(!q.empty());
	assert(q.size() == 1);
	assert(q.front() == 42);

	// Добавляем несколько элементов
	q.enqueue(100);
	q.enqueue(-5);
	assert(q.size() == 3);
	assert(q.front() == 42); // первый добавленный должен оставаться в начале

	// Удаляем элемент и проверяем порядок (FIFO)
	q.dequeue();
	assert(q.size() == 2);
	assert(q.front() == 100);

	q.dequeue();
	assert(q.size() == 1);
	assert(q.front() == -5);

	// Удаляем последний элемент
	q.dequeue();
	assert(q.size() == 0);
	assert(q.empty());
}

