#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

void insert(int key)
{
    struct node *p = root, *t, *r;
    if (root == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t;
        return;
    }
    while (p != NULL)
    {
        if (p->data == key)
            return;
        if (p->data > key)
        {
            r = p;
            p = p->lchild;
        }
        else
        {
            r = p;
            p = p->rchild;
        }
    }

    t = (struct node *)malloc(sizeof(struct node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (key > r->data)
        r->rchild = t;
    else
    {
        r->lchild = t;
    }
}
struct node *search(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
    {
        printf("found\n");
        return p;
    }
    if (p->data > key)
        return search(p->lchild, key);
    else
    {
        return search(p->rchild, key);
    }
}
void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
int main()
{
    struct node *p;

    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    p = search(root, 20);
    inorder(root);
    printf("\n");
}