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

void addEnd(list *l, int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->Data = x;
    newNode->Next = NULL;

    if(isEmpty(l)) {
        l->head = newNode;
        return;
    }

    Node *temp = l->head;

    while(temp->Next != NULL) {
        temp = temp->Next;
    }

    temp->Next = newNode;

}

//search 
bool search(list *l, int x) {
    Node *temp = l->head;

    while(temp != NULL) {
        
        if(temp->Data == x) {
            return true;
        }

        temp = temp->Next; 
    }

    return false;
}

//length 
int length(list *l) {
    int count = 0;
    Node *temp = l->head;

    while(temp != NULL) {
        count++;
        temp = temp->Next;
    }

    return count;
}

//add @ location 
void addAt(list *l, int x, int loc) {
    int size = length(l);

    if(loc < 1 || loc > size+1) {
        printf("Invalid Location\n");
    }
    else if(loc == 1) {
        addFirst(l, x);
    }
    else if(loc == size+1) {
        addEnd(l, x);
    }
    else {
        Node *newNode = (Node*)malloc(sizeof(Node));

        newNode->Data = x;

        Node *temp = l->head;

        for(int i=1; i < loc -1; i++) {
            temp = temp->Next;
        }

        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

//display 
void display(list *l) {

    if(isEmpty(l)) {
        printf("List is Empty\n");
        return;
    }

    Node *temp = l->head;

    while(temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
}

int main()
{
    int n;
    list l;

    init(&l);

    printf("Adding at front\n");
    addFirst(&l, 10);
    addFirst(&l, 20);
    addFirst(&l, 30);

    display(&l);

    printf("\nAdding at the end\n");
    addEnd(&l, 40);
    addEnd(&l, 50);
    addEnd(&l, 60);

    display(&l);

    printf("\nEnter element to search\n");
    printf("Enter any other character to exit\n");

    while( scanf("%d", &n) == 1) {

        if(search(&l, n))
            printf("%d Found", n);
        else
            printf("%d Not found", n);

        printf("\nEnter element to search\n");
    }

    printf("Adding at given location\n");

    addAt(&l, 88, 1);
    addAt(&l, 88, 4);
    addAt(&l, 88, 20);

    printf("Final List\n");
    display(&l);

    return 0;
}