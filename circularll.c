#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;

void create(int A[], int n)
{
    struct node *t, *last;
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    static int t = 0;
    if (p != head || t == 0)
    {
        t = 1;
        printf("%d ", p->data);
        display(p->next);
    }
    t = 0;
}
int main()
{
    int A[] = {2, 5, 7, 9, 18};
    create(A, 5);
    display(head);
}