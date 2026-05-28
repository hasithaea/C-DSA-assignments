#include <stdio.h>
#define SIZE 32

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
    int num=0;
    int rem=0;
    int temp=0;

    init(&s);

    printf("Stack empty =%d\n", isEmpty(&s));
    printf("Stack full =%d\n", isFull(&s));

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    temp=num;

    while(num!=0)
    {
        rem=num%2;
        push(&s,rem);
        num=num/2;
    }
    

    printf("Stack empty =%d\n", isEmpty(&s));
    printf("Stack full =%d\n", isFull(&s));

    printf("\nBinary Number of %d is\n",temp);
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

    while(i>=0)
    {
        printf("%d", s->data[i]);
        i--;
    }

    printf("\n");
}