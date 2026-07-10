#include <stdio.h>
#include <string.h>
#define SIZE 10

typedef struct{
    int busID;
    char busRegNum[10];
}bus;

typedef struct{
    int front;
    int rear;
    int size;
    bus data[SIZE];
}busQueue;

typedef enum{
    FALSE,
    TRUE
}boolean;

//initialize
void init(busQueue *q){
    q->front=0;
    q->rear=-1;
    q->size=0;
}

//empty
boolean isEmpty(busQueue *q){
    if(q->size==0)
        return TRUE;
    else
        return FALSE;
}

//Full
boolean isFull(busQueue *q){
    if(q->size==SIZE)
        return TRUE;
    else
        return FALSE;
}

//empty queue
bus emptyBusQueue(){
    bus b;

    strcpy(b.busRegNum, "");
    b.busID=0;

    return b;   
}

//increment
int increment(int x){
    if(++x==SIZE)
        x=0;
    return x;
}

//enqueue
void enqueue(busQueue *q, bus d){
    if(isFull(q)){
        printf("Bus Queue is full\n");
        return;
    }
    else{
        q->rear=increment(q->rear);
        q->data[q->rear]=d;
        q->size++;
    }
}

//dequeue
bus dequeue(busQueue *q){
    bus a;

    if(isEmpty(q)){
        return emptyBusQueue();
    }
    else{
        a=q->data[q->front];
        q->front=increment(q->front);
        q->size--;
        return a;
    }
}

//display
void display(busQueue *q){
    int i=q->front;
    int count=0;

    if(isEmpty(q)){
        printf("Bus Queue is empty\n");
        return;
    }
    else{
        while(count<q->size){
            printf("(%d) %s is waiting\n", q->data[i].busID, q->data[i].busRegNum);
            i=increment(i);
            count++;
        }
    }
}

int busCount(busQueue *q){
    return q->size;
}

int main()
{
    busQueue q;
    init(&q);

    bus b1 = {1, "NA7892"};
    bus b2 = {2, "NB5678"};
    bus b3 = {3, "NE7777"};
    bus b4 = {4, "NE9999"};
    bus b5 = {5, "NB8978"};
    bus b6 = {6, "NE9977"};

    //Buses Arriving
    enqueue(&q, b1);
    enqueue(&q, b2);
    enqueue(&q, b3);

    printf("\n====Waiting buses====\n");
    display(&q);

    printf("\n====Total buses waiting====\n");
    printf("%d\n", busCount(&q));

    printf("\n====Bus Departing====\n");
    bus left = dequeue(&q);
    if(left.busID != 0){
        printf("Bus Left: (%d) %s\n", left.busID, left.busRegNum);
    }

    //Newly joined
    enqueue(&q, b4);
    enqueue(&q, b5);
    enqueue(&q, b6);

    printf("\n====Waiting Bueses====\n");
    display(&q);
    printf("Total buses waiting: %d\n", busCount(&q));

    return 0;
}
