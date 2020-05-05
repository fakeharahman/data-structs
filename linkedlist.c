#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
} *first = NULL, *last1 = NULL, *second = NULL, *third = NULL;

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
void create2(int B[], int n)
{
    int i;
    struct list *last, *p;
    second = (struct list *)malloc(sizeof(struct list));
    second->data = B[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        p = (struct list *)malloc(sizeof(struct list));
        p->data = B[i];
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

void insertLast(int x)
{
    struct list *t, *p;

    t = (struct list *)malloc(sizeof(struct list));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last1 = t;
    }
    else if (last1 == NULL)
    {
        p = first;
        while (p != NULL)
        {
            last1 = p;
            p = p->next;
        }
        printf("%d", x);
        last1->next = t;
        last1 = t;
    }
    else
    {
        last1->next = t;
        last1 = t;
    }
}
void rev(struct list *q, struct list *p)
{
    if (p != NULL)
    {
        rev(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
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
        else if (x == p->data)
        {
            if (p == first)
            {
                first = first->next;
                free(p);
                break;
            }
            else
            {
                q->next = p->next;
                free(p);
                break;
            }
        }
    }
    if (p == NULL)
        printf("INVALID \t");
}

void merge(struct list *f, struct list *s)
{
    struct list *last = NULL;
    if (f->data < s->data)
    {
        third = f;
        f = f->next;
        last = third;
        last->next = NULL;
    }
    else if (s->data < f->data)
    {
        third = s;
        s = s->next;
        last = third;
        last->next = NULL;
    }

    while (f && s)
    {
        if (f->data < s->data)
        {
            last->next = f;
            last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            last->next = s;
            last = s;
            s = s->next;
            last->next = NULL;
        }
    }
    if (f)
    {
        last->next = f;
    }
    if (s)
    {
        last->next = s;
    }
}
void middle(struct list *p)
{
    struct list *q = first;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    printf("Middle element is %d\n", p->data);
}

int main()
{

    int A[] = {4, 6, 7, 8, 10, 11, 12};
    //int B[] = {5, 7, 9, 12};
    create(A, 7);
    middle(first);
    //create2(B, 4);
    //rev(NULL, first);
    //merge(first, second);
    //insertLast(15);
    //insert(first, 15, 4);
    //delete (first, 2);
    // printf("%d ", search(first, 6)->data);
    display(first);
    // display(second);
    //display(third);
}
