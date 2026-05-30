#include <stdio.h>
#define SIZE 10

typedef int data;

typedef struct 
{
    int size;
    int front;
    int rear;
    int data[SIZE]; 
}queue;

typedef enum
{
    FALSE,
    TRUE
}boolean;

void init(queue*);
int isEmpty(queue*);
int isFull(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
int getFront(queue*);
void display(queue*);

int main()
{

}

void init(queue*q)
{
    q->size=0;
    q->front=0;
    q->rear=-1;
}

boolean isEmpty(queue*q)
{
    if(q->size==0)
        return TRUE;
    else
        return FALSE;
}

boolean isFull(queue*q)
{
    if(q->size==SIZE)
        return TRUE;
    else
        return FALSE;
}

void enqueue(queue*q, int d)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear++;
        q->data[q->rear]=d;
        q->size++;
    }
}

int dequeue(queue*q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int a=q->data[q->front];
        q->front++;
        q->size--;
        return a;
    }
}

int getFront(queue*q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return q->data[q->front];
}

void display(queue*q)
{
    int i=q->front;

    printf("Queue: \n");

    while(i<=q->rear)
    {
        printf("%d ",q->data[i]);
        i++;
    }
    printf("\n");

}