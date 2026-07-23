#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char Data;
    struct Node *Next;
}Node;

typedef struct {
    Node *top;
}stack;

//initialize 
void init(stack *s) {
    s->top=NULL;
}

//Empty
int isEmpty(stack *s) {
    return s->top==NULL;
}

//push
void push(stack *s, char d) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=d;
    newNode->Next=s->top;
    s->top=newNode;
}

//pop
char pop(stack *s) {
    Node *temp;
    temp=s->top;

    if(isEmpty(s)) {
        printf("Stack is Empty\n");
        return -1;
    }
    else {
        char a = temp->Data;
        s->top = temp->Next;
        free(temp);
        return a;
    }
}

//display
void display(stack *s) {
    Node *temp = s->top;
    
    if(isEmpty(s)) {
        printf("Stack is empty\n");
    }
    else {
        printf("Displaying stack\n");

        while(temp!=NULL) {
            printf("%c\t", temp->Data);
            temp=temp->Next;
        }
    }
}

//symbol check
int check(char front, char rear) {
    if(front='(' && rear=')' ) 
        return 1;
    if (front='[' && rear=']') 
        return 1;
    if (front='{' && rear='}')
        return 1;
    else 
        return -1;
}

//main
int main()
{
    char word[10];
    char front,rear;

    init(&s);

    printf("Enter the line: \n");
    scanf("%s", word);

    for(int i=0; i<strlen(word); i++) {
        if(word[i]='(' || word[i]='[' || word[i]='{') {
            push(&s, word[i]);
        }
        else if(word[i]=')' || word[i]=']' || word[i]='}') {
            rear=pop(&s);
        }

        if(check)
    }

    

}