#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} listNode;

typedef struct list {
    listNode *head;
} list;

void initialize (list *l) {
    l->head = NULL;
}

bool isEmpty (list *l) {
    return l->head == NULL;
}
 
void addFirst (list *l, int x) {
    listNode *newNode = (listNode*)malloc(sizeof(listNode));

    newNode->data = x;
    newNode->next = l->head;
    l->head = newNode;   
}

void addEnd (list *l, int x) {
    listNode *newNode = (listNode*)malloc(sizeof(listNode));

    newNode->data = x;
    newNode->next = NULL;

    if(isEmpty(l)) {
        l->head = newNode;
        return;
    }

    listNode *temp = l->head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display (list *l) {

    if(isEmpty(l)) {
        printf("List is Empty\n");
        return;
    }

    listNode *temp = l->head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int length (list *l) {
    listNode *temp = l->head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int search (list *l, int x) {
    listNode *temp = l->head;

    while (temp != NULL) {
        if (temp->data == x)
            return 1;
        
        temp = temp->next;
    }

    return 0;
}

int main ()
{
    list l;
    int option;
    int a,b,c;

    initialize(&l);

    do {
        printf("\tMain Menu\n");
        printf("\n");

        printf("1. Add to the front\n");
        printf("2. Add to the end\n");
        printf("3. Display the list\n");
        printf("4. No of elements in the list\n");
        printf("5. Search an element\n");
        printf("6. Exit\n");
        printf("Enter your option: ");

        scanf("%d", &option);

        switch (option) {

            case 1:
                printf("Enter the number to add\n");
                scanf("%d", &a);
                addFirst(&l, a);
                break;

            case 2:
                printf("Enter the number to add\n");
                scanf("%d", &b);
                addEnd(&l, b);
                break;

            case 3:
                printf("The current list: \n");
                display(&l);
                break;

            case 4:
                printf("There is/are %d element/s in the list\n", length(&l));
                break;

            case 5:
                printf("Enter the number to search\n");
                scanf("%d", &c);

                if( search(&l, c)) {
                    printf("%d Found\n", c);
                }
                else {
                    printf("%d Not found\n", c);
                }

                break;

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Invalid option. Select between 1 to 6\n");
        }

    } while (option != 6);

    return 0;
}