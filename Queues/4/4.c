#include <stdio.h>
#include <string.h>
#define SIZE 5

typedef struct{
    char documentName[100];
    char userID[25];
    int numPages;
}Printjob;

typedef struct {
    int size;
    int front;
    int rear;
    Printjob data[SIZE];
}queue;

Printjob emptyPrintJob(){
    Printjob p;
    strcpy(p.documentName,"");
    strcpy(p.userID,"");
    p.numPages=0;

    return p;
}

typedef enum {
    TRUE,
    FALSE
}boolean;

//initialize
void init(queue*q){
    q->size=0;
    q->front=0;
    q->rear=-1;
}

//Empty
boolean isEmpty(queue*q){
    if(q->size==0)
        return TRUE;
    else
        return FALSE;
}

//Full
boolean isFull(queue*q){
    if(q->size==SIZE)
        return TRUE;
    else 
        return FALSE;
}

//increment
int increment(int x){
    if(++x==SIZE)
        x=0;
    return x;
}

//enqueue
void enqueue(queue *q, Printjob d){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->rear=increment(q->rear);
        q->data[q->rear]=d;
        q->size++;
    }
}

//dequeue
Printjob dequeue(queue*q){
    if(isEmpty(q)){
        return emptyPrintJob();
    }
    else{
        Printjob a=q->data[q->front];
        q->front=increment(q->front);
        q->size--;
        return a;
    }
    
}

//display
void display(queue*q){
    int i=q->front;

    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Queue elements: \n");

        while(i!=q->rear){
            printf("Document Name: %s \tUser ID: %s \tPages: %d\n", q->data[i].documentName, q->data[i].userID, q->data[i].numPages);
            i=increment(i);
        }
        printf("Document Name: %s \tUser ID: %s \tPages: %d\n", q->data[q->rear].documentName, q->data[q->rear].userID, q->data[q->rear].numPages);
        printf("\n");
    }
}

int main()
{
    queue q;

    init(&q);

    for(int j=0; j<SIZE; j++){
        Printjob job;

        printf("Enter Document name: ");
        scanf("%s", job.documentName);

        printf("Enter User ID: ");
        scanf("%s", job.userID);

        printf("Enter page number: ");
        scanf("%d", &job.numPages);

        enqueue(&q, job);
    }

    printf("=============Print Queue=============\n");
    display(&q);
    printf("=====================================\n");

    return 0;
}