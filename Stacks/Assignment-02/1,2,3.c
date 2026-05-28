#include <stdio.h>
#define SIZE 5

typedef struct 
{
    int top;
    int data[SIZE];
}stack;

void init(stack*);
void push(stack*, int);
int pop(stack*);
int top(stack*);
int isEmpty(stack*);
int isFull(stack*);
void display(stack*);

int main()
{
    stack s;

    init(&s);

    printf("Stack empty =%d\n", isEmpty(&s));
    printf("Stack full =%d\n", isFull(&s));

    push(&s,1);

    printf("Stack empty =%d\n", isEmpty(&s));
    printf("Stack full =%d\n", isFull(&s));

    push(&s,2);
    push(&s,3);

    display(&s);

    pop(&s);

    display(&s);

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

int top(stack*s)
{
    return s->data[s->top];
}

void push(stack*s, int x)
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

int pop(stack*s)
{
    if(isEmpty(s))
    {
        printf("Stack empty\n");
        return -1;
    }
    else
    {
        int a=s->data[s->top];
        s->top--;
        return a;
    }
}

void display(stack*s)
{
    int i=s->top;
    printf("\nDisplay stack\n====================\n");

    while(i>=0)
    {
        printf("%d ", s->data[i]);
        i--;
    }

    printf("\n");
}