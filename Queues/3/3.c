#include <stdio.h>
#define SIZE 10

typedef struct{
    int size;
    int front;
    int rear;
    int data[SIZE];
}queue;

typedef enum{
    FALSE,
    TRUE
}boolean;

void init(queue*q){
    q->size=0;
    q->front=0;
    q->rear=-1;
}

boolean isEmpty(queue*q){
    if(q->size==0)
        return TRUE;
    else
        return FALSE;
}

boolean isFull(queue*q){
    if(q->size==SIZE)
        return TRUE;
    else
        return FALSE;
}

int increment(int x)
{
    if(++x==SIZE)
        x=0;
    return x;
}

void enqueue(queue*q, data d){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else{
        q->rear= increment(q->rear);
        q->data[q->rear]=d;
        q->size++;
    }
}

int dequeue(queue*q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        int a=q->data[q->front];
        q->front=increment(q->front);
        q->size--;
        return a;
    }
}

int getFront(queue*q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        return q->data[q->front];
    }  
}

void display(queue*q){
    int i=q->front;

    printf("Queue: \n");

    while(i!=q->rear){
        printf("%d", q->data[i]);
        i=increment(i);
    }
    printf("%d", q->data[q->rear]);
    printf("\n");
}

int main()
{
    queue q;
    int i,n;

    init(&q);

    for(i=0; i<SIZE; i++)
    {
		printf("Enter element %d\n", i+1);
		scanf("%d", &n);
		enqueue(&q, n);
	}

    display(&q);

    printf("\nDeleted Element: %d\n", dequeue(&q));
	printf("\nDeleted Element: %d\n", dequeue(&q));
	printf("\nDeleted Element: %d\n", dequeue(&q));

    display(&q);

    printf("\n");

    for(i=0; i<SIZE;i++)
    {
	    printf("Enter element %d\n", i+1);
		scanf("%d", &n);
		enqueue(&q, n);
	}

    display(&q);

    return 0;
}