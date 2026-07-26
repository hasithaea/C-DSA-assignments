#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int taxiID;
    char taxiNum[10];
}taxi;

typedef struct node{
    taxi data;
    struct node *next;
}node;

typedef struct {
    node *front;
    node *rear;
    int size;
}taxiQueue;

//initialzie
void init(taxiQueue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

//empty
bool isEmpty(taxiQueue *q) {
    return q->size==0;
}

//enqueue
void enqueue(taxiQueue *q, taxi d) {
    node *newNode = (node*)malloc(sizeof(node));

    newNode->data=d;
    newNode->next = NULL;

    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

taxi emptyTaxiQueue() {
    taxi t;
    strcpy(t.taxiNum, "");
    t.taxiID=0;

    return t;
}

//dequeue
taxi dequeue(taxiQueue *q) {
    taxi a;
    if(isEmpty(q)) {
        return emptyTaxiQueue();    // (taxi){0, ""} can use this instead of function.
    }

    node *temp = q->front;
    a = temp->data;
    q->front = temp->next;

    if(q->front==NULL)
        q->rear = NULL;

    free(temp);
    q->size--;

    return a;
}

//display
void display(taxiQueue *q) {
    if(isEmpty(q)) {
        printf("Taxi Queue is empty");
        return;
    }

    node *temp = q->front;

    while(temp!=NULL) {
        printf("Taxi ID: %d | Taxi Number: %s", temp->data.taxiID, temp->data.taxiNum);
        temp=temp->next;
        printf("\n");
    }
}

int numOfTaxis(taxiQueue *q) {
    return q->size;
}

int main()
{
    taxiQueue q;

    init(&q);

    //registed taxies 
    taxi t1 = {1, "CBD-8877"};
    taxi t2 = {2, "CBD-5563"};
    taxi t3 = {3, "CBD-4523"};
    taxi t4 = {4, "CBD-4589"};
    taxi t5 = {5, "CBD-2359"};

    //taxi coming
    enqueue(&q, t1);
    enqueue(&q, t2);
    enqueue(&q, t3);

    printf("Customer 1 taking a taxi\n");
    taxi x = dequeue(&q);
    printf("Details: %d | %s", x.taxiID, x.taxiNum);

    printf("\n\nCustomer 2 taking a taxi\n");
    taxi y = dequeue(&q);
    printf("Details: %d | %s", y.taxiID, y.taxiNum);

    //new taxi enters 
    enqueue(&q, t4);
    enqueue(&q, t5);

    printf("\n\nAvailable taxis in the queue\n");
    display(&q);
    printf("\n");

    printf("Number of taxies avavilable: %d", numOfTaxis(&q));

    return 0;
}
