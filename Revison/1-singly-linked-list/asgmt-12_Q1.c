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

void addAt (list *l, int x, int loc) {
    int size = length(l);

    if(loc < 1 || loc > size+1) {
        printf("Invalid Location.\n");
    }
    else if (loc == 1) {
        addFirst(l, x);
    }
    else if (loc == size+1) {
        addEnd(l, x);
    }
    else {
        listNode *newNode = (listNode*)malloc(sizeof(listNode));

        newNode->data = x;

        listNode *temp = l->head;

        for(int i=1; i < loc -1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
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
    int a,b,c1,c2,d;

    initialize(&l);

    do {
        printf("\tMain Menu\n");
        printf("\n");

        printf("1. Add to the front\n");
        printf("2. Add to the end\n");
        printf("3. Add at location\n");
        printf("4. Display the list\n");
        printf("5. No of elements in the list\n");
        printf("6. Search an element\n");
        printf("7. Exit\n");
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
                printf("Enter number: ");
                scanf("%d", &c1);
                printf("Enter location: ");
                scanf("%d", &c2);
                addAt(&l, c1, c2);
                break;

            case 4:
                printf("The current list: \n");
                display(&l);
                break;

            case 5:
                printf("There is/are %d element/s in the list\n", length(&l));
                break;

            case 6:
                printf("Enter the number to search\n");
                scanf("%d", &d);

                if( search(&l, d)) {
                    printf("%d Found !\n", d);
                }
                else {
                    printf("%d Not found !\n", d);
                }

                break;

            case 7:
                printf("Exiting...");
                break;

            default:
                printf("Invalid option. Select between 1 to 6\n");
        }

    } while (option != 6);

    return 0;
}