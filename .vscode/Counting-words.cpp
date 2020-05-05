#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int word = 1;
    char A[] = "Hello how  are you?";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
            word++;
    }
    cout << word;
}