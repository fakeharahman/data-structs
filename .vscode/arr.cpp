#include <stdio.h>
#include <iostream>
using namespace std;
struct array
{
    int A[20];
    int size;
    int length;
};
void display(struct array arr)
{
    int i;
    printf("the elements are \t");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d", arr.A[i]);
    }
    cout << "\n hahaha";
}

void arraay(struct array arr)
{
    int temp;
    temp = arr.A[0];
    for (int i = 0; i < arr.length - 1; i++)
    {
        arr.A[i] = arr.A[i + 1];
    }

    arr.A[arr.length - 1] = temp;

    cout << temp;
    cout << arr.A[arr.length];
    display(arr);
}

int main()
{
    struct array arr = {{1, 2, 3, 4, 5, 7}, 10, 6};
    arraay(arr);

    //display(arr);
    return 0;
}