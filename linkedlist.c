#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
} * first;

void create(int A[], int n)
{
    int i;
    struct list *last, *p;
    first = (struct list *)malloc(sizeof(struct list));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        p = (struct list *)malloc(sizeof(struct list));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void display(struct list *p)
{
    struct list *n;
    n = p;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    int A[] = {2, 4, 6, 8, 3, 1};
    create(A, 6);
    display(first);
}