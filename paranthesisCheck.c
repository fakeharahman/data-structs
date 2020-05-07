
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *A;
};
void create(struct stack *st)
{
    printf("Enter size of stack");
    scanf("%d ", st->size);
    st->A = (char *)malloc(st->size * sizeof(char));
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
char pop(struct stack *st)
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

int isBalanced(char *c)
{
    int i;
    struct stack *st;
    st->size = strlen(c);
    st->A = (char *)malloc(st->size * sizeof(char));
    st->top = -1;
    for (i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == '(')
            push(st, c[i]);
        else if (c[i] == ')')
        {
            if (isEmpty(*st) == 1)
            {
                printf("not balanced hehe");
                return 0;
            }
            else
                pop(st);
        }
    }
    if (isEmpty(*st) == 1)
    {
        printf("Its balanced hehe");
        return 1;
    }
    printf("not balanced hehe");
    return 0;
}

int main()
{
    char *s;
    s = "((4*u(&)))";
    //printf("%d ", isBalanced(s));
    isBalanced(s);
}