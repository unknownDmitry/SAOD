#include <iostream>
#include "List.h"
#include "Stack.h"


int main()
{
   Stack<int> st;

   st.push(10);
   st.push(20);
   st.push(30);

   std::cout << st.top() << std::endl; // 30

   st.pop();

   std::cout << st.top() << std::endl; // 20
}