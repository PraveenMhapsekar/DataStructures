#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int capacity;
    int *data;
 } queue_t;

queue_t *createQ(int);
void enQueue(queue_t *q, int data);
int deQueue(queue_t *q);
int front(queue_t *q);
int isFull(queue_t *q);
int isEmpty(queue_t *q);

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
    if (q->rear == q->front)
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
    if (q->front == -1) {
         q->front = q->rear;
    }
}

int
deQueue(queue_t *q)
{
    int data;
    if (isEmpty(q)) {
        fprintf(stderr, "Q -> full\n");
        return;
    }

    data = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    return data;
}

void
print(queue_t *q) 
{
    int front;

    if (!q)
        return;

    printf("Q -> ");

    for (front = q->front;
         front != q->rear;
         front = ((front + 1) % q->capacity)) {
        printf("%02d ", q->data[front]);
    } 

    printf("%02d\n", q->data[front]);
}

int
main(int argc, char **argv, char **envp)
{
    queue_t *q;
    int  e;

    q = createQ(4);

    enQueue(q, 11);
    enQueue(q, 12);
    enQueue(q, 13);
    enQueue(q, 14);
    print(q);

    printf("deQueued A %d\n", deQueue(q));
    print(q);

    enQueue(q, 15);
    enQueue(q, 16);
    enQueue(q, 17);
    print(q);

    return 0;
}

