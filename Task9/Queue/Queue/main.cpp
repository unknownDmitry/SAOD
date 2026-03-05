#include <iostream>
#include "Queue.h"
#include "QueueTests.h"

int main()
{
    // Запускаем тесты очереди
    test_queue();

    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << q.front() << std::endl; // 10

    q.dequeue();

    std::cout << q.front() << std::endl; // 20

    return 0;
}