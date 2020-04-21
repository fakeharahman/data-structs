#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
} *first = NULL, *last = NULL;

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

struct list *search(struct list *p, int x)
{
    struct list *q = NULL;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

void display(struct list *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert(struct list *p, int x, int pos)
{
    struct list *t;
    t = (struct list *)malloc(sizeof(struct list));
    if (pos == 0)
    {
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
void delete (struct list *p, int x)
{
    struct list *q = NULL;
    while (p != NULL)
    {
        if (x != p->data)
        {
            q = p;
            p = p->next;
        }
        else
        {
            q->next = p->next;
            break;
        }
    }
    if (p == NULL)
        printf("INVALID \t");
}

void insertLast(int x)
{
    struct list *t, *p;

    t = (struct list *)malloc(sizeof(struct list));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else if (last == NULL)
    {
        p = first;
        while (p != NULL)
        {
            last = p;
            p = p->next;
        }
        printf("%d", x);
        last->next = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

int main()
{

    int A[] = {2, 4, 6, 8, 3, 1};

    create(A, 6);

    insertLast(15);
    //insert(first, 15, 4);
    //delete (first, 61);
    // printf("%d ", search(first, 6)->data);
    display(first);
}