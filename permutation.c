#include <stdio.h>
void perm(char S[], int k)
{
    //printf("%d", 1);
    int i;
    static char A[10] = {0};
    static char res[10];
    if (S[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\t", res);
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                res[k] = S[i];
                A[i] = 1;

                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    char S[] = "ABDC";
    perm(S, 0);
    //printf("%d", 4);
    return 0;
}
