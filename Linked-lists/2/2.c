#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char Data;
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
void push(stack *s, char d){   
    Node *newNode =(Node*)malloc(sizeof(Node));
    newNode->Data=d;
    newNode->Next=s->top;
    s->top=newNode;
}

//pop
char pop(stack*s){
    Node *temp;
    temp=s->top;

    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        char a = temp->Data;
        s->top=temp->Next;
        free(temp);
        return a;
    }

}

//display
void display(stack *s){
    Node *temp = s->top;

    printf("Displaying : \n");

    while(temp!=NULL){
        printf("%c ", temp->Data);
        temp=temp->Next;
    }
}

int main()
{
    stack s;
    char word[25];
    int i=0;
    int j=0;

    init(&s);

    printf("Enter the word: ");
    scanf("%s", word);

    int n = strlen(word);

    while(n>=i){
        push(&s,word[i]);
        i++;
    }

    printf("Reversed: \n");

    while(n>=j){
        printf("%c", pop(&s));
        j++;
    }

    printf("\n");

    return 0;
}