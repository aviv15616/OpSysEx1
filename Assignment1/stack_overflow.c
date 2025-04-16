// This program demonstrates a stack overflow by using recursion
#include <stdio.h>
void foo(int i)
{
    printf("%d\n",5/i);
    foo(i);
    // This will cause a stack overflow
}

int main()
{
  int i=3;
  foo(i);
  // This will cause a stack overflow
    return 0;
}
