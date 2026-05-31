#include <stdio.h>
#define SIZE 10

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
boolean isEmpty(queue*);
boolean isFull(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
int getFront(queue*);
void display(queue*);

int main()
{
    queue q;
    int noRemove=0;
    int j=1;
    int k=1;
    int num;

    init(&q);

    printf("Queue empty =%d\n", isEmpty(&q));
    printf("Queue full =%d\n", isFull(&q));

    printf("Enter 6 numbers to insert : ");

    while(j<=6)
    {
        printf("Enter the number %d: ", j);
        scanf("%d", &num);
        j++;

        enqueue(&q,num);
    }

    display(&q);

    printf("3 numbers will be removed\n");

    while(k<=3)
    {
        dequeue(&q);
        k++;
    }

    display(&q);

    printf("Enter 5 number to insert : ");

    j=1;

    while(j<=5)
    {
        printf("Enter the number %d: ", j);
        scanf("%d", &num);
        j++;

        enqueue(&q,num);
    }

    display(&q);

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
    if(q->rear==SIZE-1)
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