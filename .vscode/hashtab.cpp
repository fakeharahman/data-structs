#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int A[10] = {1, 3, 4, 5, 6, 8, 10};
    int l = 1;
    int h = 10;
    int H[h] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0, 0, 0, 0};
    for (int i = 0; i < h; i++)
    {
        H[A[i]]++;
    }
    for (int i = 1; i <= h; i++)
    {
        if (H[i] == 0)
            cout << i;
    }
}