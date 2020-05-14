#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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
        printf("The left child is of %d:", p->data);
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
        printf("The right child of %d:", p->data);
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

void inorder(struct tree *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void inorderLoop(struct tree *t)
{
    struct stack s;
    createStack(&s, 100);
    while (t != NULL || !isEmptyS(s))
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            push(&s, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&s);
            t = t->rchild;
        }
    }
}

void lorder(struct tree *p)
{
    printf("%d ", p->data);
    enqueue(p);
    while (!isEmpty())
    {
        p = dequeue();
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(p->rchild);
        }
    }
}

int main()
{
    create();
    lorder(root);
    return 0;
}