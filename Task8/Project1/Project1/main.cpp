#include <iostream>
#include "List.h"
#include "Stack.h"
#include "StackTests.h"

int main()
{
    // Запускаем тесты стека (assert завершит программу при неуспехе)
    test_stack();

    std::cout << "All Stack tests passed!" << std::endl;

    return 0;
}