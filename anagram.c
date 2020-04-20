#include <stdio.h>
#include <stdlib.h>
int main()
{
    int H[26] = {0};

    char A[] = "verbose";
    char B[] = "observe";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        //printf("%d\t", H[i]);
        H[A[i] - 97]++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            printf("this is not an anagram");
            break;
        }
    }
    if (i == 26)
        printf("this anagram lol");
}