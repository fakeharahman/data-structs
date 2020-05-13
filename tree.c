#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct tree *data;
    struct Node *next;

} *front = NULL, *rear = NULL;

struct tree
{
    int data;
    struct tree *lchild;
    struct tree *rchild;
} *root = NULL;

void enqueue(struct tree *x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
struct tree *dequeue()
{
    struct tree *x = NULL;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    if (front == NULL)
        return 1;
    return 0;
}

void create()
{
    struct tree *p, *t;
    int x;
    root = (struct tree *)malloc(sizeof(struct tree));
    root->lchild = NULL;
    root->rchild = NULL;
    printf("Type the root element: ");
    scanf("%d", &x);
    root->data = x;
    enqueue(root);
    while (!isEmpty())
    {
        p = dequeue();
        printf("The left child is:");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct tree *)malloc(sizeof(struct tree));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        printf("The right child is:");
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct tree *)malloc(sizeof(struct tree));
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

int main()
{
    create();
    return 0;
}