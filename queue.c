#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int rear;
    int front;
    int *q;
};
void create(struct queue *que, int sz)
{
    que->size = sz;
    que->q = (int *)malloc(que->size * sizeof(int));
    que->front = que->rear = -1;
}

void enqueue(struct queue *que, int x)
{
    if ((que->rear + 1) % que->size == que->front)
    {
        printf("Queue Overflow");
    }
    else
    {
        que->rear = (que->rear + 1) % que->size;
        que->q[que->rear] = x;
    }
}
int dequeue(struct queue *que)
{
    int x = -1;
    if (que->front == que->rear)
    {
        printf("Queue empty");
    }
    else
    {
        que->front = (que->front + 1) % que->size;
        ;
        x = que->q[que->front];
    }
    return x;
}
void display(struct queue q)
{
    int i = q.front + 1;

    do
    {

        printf("%d ", q.q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}
int main()
{
    struct queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);

    printf("%d ", dequeue(&q));
    return 0;
}