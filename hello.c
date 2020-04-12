#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int fun1(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;

        return fun1(n - 1) + x;
    }
}

void main()
{
    int n, k;
    k = fun1(5);
    printf("%d", k);
    k = fun1(5);
    printf("%d", k);
}