#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10

typedef struct {
    char title[100];
    int wCount;
} msgData;

typedef struct {
    int front;
    int rear;
    int size;
    msgData data[SIZE];
} msgBufferQ;

msgData emptyMsgData () {
    msgData m;
    strcpy(m.title, "");
    m.wCount = 0;

    return m;
}

void init (msgBufferQ *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty (msgBufferQ *q) {
    return q->size == 0;
}

bool isFull (msgBufferQ *q) {
    return q->size == SIZE;
}

int increment (int x) {
    if(++x==SIZE)
        x=0;
    return x;
}
 
void enqueue (msgBufferQ *q, msgData d) {
    if(isFull(q)) {
        printf("Queue is full");
        return;
    }

    q->rear =  increment(q->rear);
    q->data[q->rear]=d;
    q->size++;
}

msgData dequeue (msgBufferQ *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return emptyMsgData();
    }

    msgData a;

    a = q->data[q->front];
    q->front = increment(q->front);
    q->size--;

    return a;
}

void display (msgBufferQ *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    int count = 0;

    while(count < q->size) {
        printf("Message: %s | word count: %d\n", q->data[i].title, q->data[i].wCount);
        i = increment(i);
        count++;
    }
}

void firstDisplay (msgBufferQ *q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;

    printf("First Message\n");
    printf("Message: %s | word count: %d\n", q->data[i].title, q->data[i].wCount);
}

int numOfMsg (msgBufferQ *q) {
    return q->size;
}

int main()
{
    msgBufferQ q;
    
    init(&q);

    msgData m1 = {"message 1", 1};
    msgData m2 = {"message 2", 2};
    msgData m3 = {"message 3", 3};
    msgData m4 = {"message 4", 4};

    enqueue(&q, m1);
    enqueue(&q, m2);
    enqueue(&q, m3);
    enqueue(&q, m4);

    printf("Displaying queue\n");
    display(&q);

    printf("Number of msg in queue : %d\n", numOfMsg(&q));

    msgData delivered = dequeue(&q);
    printf("Displaying 1st msg\n");
    printf("Message: %s | Word count: %d\n", delivered.title, delivered.wCount);

    printf("Displaying queue\n");
    display(&q);

    int j=0;
    int totalCount=0;
    int i = q.front;

    while(j < q.size) {
        totalCount += q.data[i].wCount;
        i = increment(i);
        j++;
    }

    printf("Total word count: %d\n", totalCount);

    return 0;
}