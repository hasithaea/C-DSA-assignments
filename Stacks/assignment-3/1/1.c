#include <stdio.h>
#include <string.h>
#define SIZE 20

typedef struct 
{
    int top;
    char data[SIZE];
}stack;

void init(stack*);
void push(stack*, char);
char pop(stack*);
//char top(stack*);
int isEmpty(stack*);
int isFull(stack*);
//void display(stack*);

int main()
{
    stack s;
    char word[SIZE];
    char temp[SIZE];
    int j=0;
    int k=0;

    init(&s);

    printf("Stack empty =%d\n", isEmpty(&s));
    printf("Stack full =%d\n", isFull(&s));

    printf("Enter a word to check palindrome or not : ");
    scanf("%s", word);

    while(j<strlen(word))
    {
        push(&s,word[j]);
        j++;
    }
    
    while(k<strlen(word))
    {
        temp[k]=pop(&s);
        k++;
    }
    temp[k]='\0';

    if(strcmp(word,temp)==0)
    {
        printf("%s is a palindrome \n", word);
    }
    else
    {
        printf("%s is NOT a palindrome \n", word);
    }

    return 0;
}


void init(stack*s)
{
    s->top=-1;
}

int isEmpty(stack*s)
{
    return s->top==-1;
}

int isFull(stack*s)
{
    return s->top==SIZE-1;
}

/*
char top(stack*s)
{
    return s->data[s->top];
}
*/

void push(stack*s, char x)
{
    if(isFull(s))
    {
        printf("Stack full\n");
    }
    else
    {
        s->top++;
        s->data[s->top]=x;
    }
}

char pop(stack*s)
{
    if(isEmpty(s))
    {
        printf("Stack empty\n");
        return -1;
    }
    else
    {
        char a=s->data[s->top];
        s->top--;
        return a;
    }
}

/*
void display(stack*s)
{
    int i=s->top;
    printf("\nBackward\n");

    while(i>=0)
    {
        printf("%c", s->data[i]);
        i--;
    }

    printf("\n");
}
*/