#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;

} * first;
void create(int A[], int n)
{
    struct node *t, *p;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->prev = NULL;
    first->next = NULL;
    first->data = A[0];
    p = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->prev = p;
        t->next = p->next;
        t->data = A[i];
        p->next = t;
        p = t;
    }
}

void display(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int len(struct node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void insert(struct node *p, int x, int n)
{
    struct node *t;
    int i;
    t = (struct node *)malloc(sizeof(struct node));
    if (n < 0 || n > len(first))
    {
        return;
    }
    if (n == 0)
    {
        if (first != NULL)
        {
            t->data = x;
            t->next = first;
            t->prev = NULL;
            first->prev = t;
            first = t;
        }
        else
        {
            t->data = x;
            t->next = t->prev = NULL;
            first = t;
        }
    }
    else
    {
        t->data = x;
        for (i = 0; i < n - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;

        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void delete (struct node *p, int index)
{
    int i;
    if (index < 0 || index > len(first))
    {
        return;
    }
    if (index == 0)
    {

        first = first->next;
        free(p);
        if (first)
        {
            first->prev = NULL;
        }
    }
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
    }

    p->prev->next = p->next;
    if (p->next)
        p->next->prev = p->prev;
    free(p);
}
int main()
{
    int A[] = {5, 7, 6, 9, 4};
    create(A, 5);
    insert(first, 40, 5);
    delete (first, 4);
    display(first);
}