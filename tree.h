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

struct stack
{
    int top;
    int size;
    struct tree **A;
};
void createStack(struct stack *st, int x)
{
    st->size = x;
    st->A = (struct tree **)malloc(st->size * sizeof(struct tree));
    st->top = -1;
}
int isEmptyS(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
void push(struct stack *st, struct tree *x)
{
    if (st->top == st->size - 1)
        printf("stack Overflow");
    else
    {
        st->top++;
        st->A[st->top] = x;
    }
}
struct tree *pop(struct stack *st)
{
    struct tree *x = NULL;
    if (st->top == -1)
        printf("stack underflow");
    else
    {
        x = st->A[st->top];
        st->top--;
    }
    return x;
}

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
