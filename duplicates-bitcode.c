#include <stdio.h>

int main()
{

    long int x = 0, h = 0;
    int i;
    char A[] = "piinating";
    for (i = 0; A[i] != '\0'; i++)
    {
        //printf("%c", A[i]);
        x = 1;
        x = x << A[i] - 97;
        //printf("%d\t", h);
        //printf("%d\t", x & h);
        if ((x & h) != 0)
        {
            printf("%c is duplicate \n", A[i]);
        }
        else
        {
            h = (x | h);
            //printf("%d", i);
        }
    }
    return 0;
}