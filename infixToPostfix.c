
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char x;
    struct node *next;

} *top = NULL;

void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("stack overflow");
    }
    else
    {
        t->x = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct node *p;
    char x = -1;
    if (top == NULL)
        printf("Empty");
    else
    {
        p = top;
        x = top->x;
        top = top->next;
        free(p);
    }
    return x;
}
char stackTop()
{
    return top->x;
}
int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
void display()
{
    struct node *p = top;
    while (p)
    {
        printf("%d ", p->x);
        p = p->next;
    }
    printf("\n");
}

int pre(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int isOperand(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return 0;
    else
        return 1;
}

char *convert(char *infix)
{
    int j = 0;
    int i = 0;
    char *postfix;
    postfix = (char *)malloc((strlen(infix) + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (isEmpty())
                push(infix[i++]);
            else if (pre(infix[i]) > pre(stackTop()))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int eval(char *postfix)
{
    int x1, x2, i;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                push(x1 + x2);
                break;
            case '-':
                push(x1 - x2);
                break;
            case '*':
                push(x1 * x2);
                break;
            case '/':
                push(x1 / x2);
                break;
            }
        }
    }
    return pop();
}

int main()
{
    char *infix = "3+2*2-6/2";
    //push('#');

    char *postfix = convert(infix);

    printf("%s ", postfix);
    int x = eval(postfix);
    printf(" %d ", x);

    return 0;
}
