#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

typedef struct {
    ListNode *front;
    ListNode *rear;
    int size;
}queue;

//initialize
void init(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

//empty
bool isEmpty(queue *q) {
    return q->size==0;
}

//enqueue
void enQueue(queue *q, int d) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->data = d;
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

int deQueue(queue *q) {

    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    
    ListNode *temp = q->front;
    int a = temp->data;
    q->front = q->front->next;

    if(q->front==NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
        
    return a;
    
}

void displayQueue(queue *q) {
    
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    ListNode *temp = q->front;

    printf("=======Displaying Queue======== \n");

    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main ()
{
    queue q;

    init(&q);

    //Inserting 5 elements
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);


    //display elements
    displayQueue(&q);

    printf("Size of the queue: %d\n", q.size);


    //delete 2 elements
    int x = deQueue(&q);
    int y= deQueue(&q);
    printf("Deleted %d %d\n", x, y);

    //display elements again
    displayQueue(&q);

    printf("Size of the queue: %d\n", q.size);

    //Inserting 6 more elements
    enQueue(&q, 6);
    enQueue(&q, 7);
    enQueue(&q, 8);
    enQueue(&q, 9);
    enQueue(&q, 10);
    enQueue(&q, 11);

    //display elements again (end)
    displayQueue(&q);

    printf("Size of the queue: %d\n", q.size);

    return 0;
}