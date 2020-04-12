#include <stdio.h>
#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int len;

public:
    Array()
    {
        size = 20;
        A = new int[size];
        len = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new int[size];

        len = 0;
    }
    ~Array()
    {
        delete[] A;
    }
    void missingele();
    void init();
};
void Array::init()
{
    A[0] = 5;
    A[1] = 7;
    A[2] = 10;

    len = 3;
}
void Array::missingele()
{
    int i, diff = A[0];
    for (i = 0; i < len; i++)
    {
        if (A[i] - i != diff)
        {
            while (A[i] - i > diff)
            {
                cout << i + diff;
                diff++;
            }
        }
    }
}

int main()
{
    Array *arr1;
    arr1 = new Array(20);
    arr1->init();
    arr1->missingele();
    return 0;
}
