#include <stdio.h>
#include <stdlib.h>
#include "03-Queue.h"


queue_t *
createQ(int capacity)
{
    queue_t *q = malloc(sizeof(queue_t));
    q->front  = -1;
    q->rear   = -1;    
    q->capacity = capacity;
    q->data   = malloc(sizeof(int) * capacity);
    return q;
}

int
isFull(queue_t *q) 
{
    if (((q->rear + 1) % q->capacity) == q->front) 
        return 1;
    return 0;      
}

int
isEmpty(queue_t *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

void
enQueue(queue_t *q, int data)
{
    if (isFull(q)) {
        fprintf(stderr, "Q -> full, %d enque failed\n", data);
        return;
    }
    
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = data;
    if (q->front == -1) { /* First entry */
        q->front = q->rear;
    }
}

int
deQueue(queue_t *q)
{
    int data;
    if (isEmpty(q)) {
        fprintf(stderr, "Q -> empty\n");
        return -1;
    }

    data = q->data[q->front];
    if (q->front ==  q->rear)
        q->front = -1;
    else
        q->front = (q->front + 1) % q->capacity;

    return data;
}

void
print(queue_t *q) 
{
    int front;

    if (!q)
        return;

    if (isEmpty(q))
        return;

    printf("Q -> ");

    for (front = q->front;
         front != q->rear;
         front = ((front + 1) % q->capacity)) {
        printf("%02d ", q->data[front]);
    } 

    printf("%02d\n", q->data[front]);
}
//#define QTEST
#ifdef QTEST
int
main(int argc, char **argv, char **envp)
{
    queue_t *q;
    int  e;

    q = createQ(8);

    enQueue(q, 10);
    enQueue(q, 11);
    enQueue(q, 12);
    enQueue(q, 13);
    enQueue(q, 14);
    print(q);

    printf("deQueued  %d\n", deQueue(q));
    print(q);

    enQueue(q, 15);
    enQueue(q, 16);
    enQueue(q, 17);
    print(q);
    enQueue(q, 22);
    print(q);
    enQueue(q, 23);
    print(q);
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));
    printf("deQueued  %d\n", deQueue(q));

    print(q);
    printf("deQueued  %d\n", deQueue(q));

    print(q);
    return 0;
}
#endif
