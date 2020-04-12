#include <stdio.h>
#include <iostream>
using namespace std;

struct array
{
    int A[20];
    int size;
    int length;
};

void append(struct array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void insert(struct array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

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

int main()
{
    struct array arr = {{1, 2, 3, 4, 5, 7}, 20, 6};
    append(&arr, 10);
    insert(&arr, 4, 25);

    display(arr);
    return 0;
}