#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int Data;
    struct ListNode *Next;
}ListNode;

typedef struct 
{
    ListNode *top;
}stack;

void init(stack*);
void push(stack*s, int d);
int pop(stack*s);

int main()
{
    stack s;

}

void init(stack*s)
{
    s->top=NULL;
}

void push(stack*s, int d)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    
    if(newNode==NULL)
    {
        printf("Memory allocation faild\n");
        return;
    }
    newNode->Data=d;
    newNode->Next=s->top;
    s->top=newNode;
}

int pop(stack*s)
{
    int a=s->data[s->top];

}