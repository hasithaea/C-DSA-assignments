#include <stdio.h>
#define SIZE

typedef struct 
{
    int data[SIZE];
    int top;
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

    return 0;
}


void init(stack*s)
{
    s->top=-1;
}

void push(stack*s, int d)
{
    if(isFull)
}

int isEmpty(stack*s)
{
    return s->top==-1;
}

int isFull(stack*s)
{
    return s->top==SIZE-1;
}

void push(stack*s, int x)
{
    if(isFull(s))
    {
        printf("Stack full");
    }
    else
    {
        s->top++;
        s->items[s->top]=x;
    }
}

int pop(stack*s)
{
    if(isEmpty(s))
    {
        printf("Stack empty");
        return -1;
    }
    else
    {
        int a=s->itms[s->top];
        s->top--;
        return a;
    }
}

void display(stack*s)
{
    int i=s->top;
    printf("Display stack\n====================");

    while(i>=0)
    {
        printf("%d", s->items[i]);
        i--;
    }
}