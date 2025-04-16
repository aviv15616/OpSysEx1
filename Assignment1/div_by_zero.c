// This program demonstrates a division by zero error.
#include <stdio.h>
void foo(int i)
{
    printf("%d\n",5/i);
}

int main()
{
    for(int j = 3; j >=0; j--){
        foo(j);
}
    return 0;
}
