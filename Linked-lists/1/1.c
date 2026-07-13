#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Data;
    struct Node *Next;
}Node;

typedef struct{
    Node *top;
}stack;

//initialize 
void init(stack *s){
    s->top=NULL;
}

//Empty
int isEmpty(stack *s){
    return s->top==NULL;
}

//push
void push(stack *s, int d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Data=d;
    newNode->Next=s->top;
    s->top = newNode;
}

//pop
int pop(stack *s){
    Node *temp;
    temp=s->top;

    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        int a = temp->Data;
        s->top = temp->Next;
        free(temp);
        return a;
    }
}

//display
void display(stack *s){
    Node *temp = s->top;

    printf("Displaying stack\n");

    while(temp!=NULL){
        printf("%d\t", temp->Data);
        temp=temp->Next;
    }
}

int main()
{
    stack s;

    init(&s);

    push(&s,1);
    push(&s,2);
    push(&s,3);

    printf("%d\t", pop(&s));
    printf("%d\t", pop(&s));
    printf("%d\n", pop(&s));

    return 0;

}

