#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *A;
};
void create(struct stack *st)
{
    printf("Enter size of stack");
    scanf("%d ", st->size);
    st->A = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.A[i]);
    printf("\n");
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("stack Overflow");
    else
    {
        st->top++;
        st->A[st->top] = x;
    }
}
int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("stack underflow");
    else
    {
        x = st->A[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("invalid index \n");
    else
    {
        x = st.A[st.top - index + 1];
    }
    return x;
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    return st.top == st.size - 1;
}

int stackTop(struct stack st)
{
    if (!isEmpty(st))
    {
        return st.A[st.top];
    }
    return -1;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    printf("removed element: %d \n", pop(&st));

    printf("%d \n", peek(st, 2));

    display(st);

    return 0;
}