#include <stdio.h>

int main()
{
    char *A = "ullu";
    char B[10];
    int i, j, pal;
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    //printf("%d %d", i, j);
    for (i = 0; A[i] != '\0' && B[i] != '\0'; i++)
    {
        if (A[i] != B[i])
        {
            printf("not a palindrome. sikee");
            break;
            pal = 1;
        }
    }
    if (pal != 1)
        printf("palindrome babyy!");
}