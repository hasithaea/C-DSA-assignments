#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node *Next;
} Node;

typedef struct {
    Node *head;
} list;

//initialize 
void init(list *l) {
    l->head = NULL;
}

//empty 
bool isEmpty(list *l) {
    return l->head == NULL;
}

//insert @ begining 
void addFirst(list *l, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->Data = x;
    newNode->Next = l->head;
    l->head = newNode;
}

//display 
void display(list *l) {
    Node *temp = l->head;

    while(temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
}

int main()
{
    list l;

    init(&l);

    addFirst(&l, 10);
    addFirst(&l, 20);
    addFirst(&l, 30);

    display(&l);

    return 0;
}