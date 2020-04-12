#include <stdio.h>

int ty(int n, int x)
{
    static int p = 1, q = 1;
    int r;
    if (n == 0)
    {
        return 1;
    }
    r = ty(n - 1, x);
    p = p * x;
    q = q * n;
    return r + p / q;
}

void main()
{
    int n = 5;
    int x = ty(5, 7);
    printf("%d", x);
}