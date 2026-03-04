#include <iostream>
#include "List.h"
#include "Stack.h"
#include "StackTests.h"

int main()
{
   test_stack();

   Stack<int> st;

   st.push(10);
   st.push(20);
   st.push(30);

   std::cout << st.top() << std::endl; // 30

   st.pop();

   std::cout << st.top() << std::endl; // 20

}