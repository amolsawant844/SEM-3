#include<stdio.h>
#define MAX 10
int top=-1;
int a[MAX];
void main()
{
    int c,val;
do{
    printf("What action d u want to perform\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            printf("enter a value\n");
            scanf("%d",&val);
            push(a,val);
            break;
        case 2:
            pop(a);
            break;
        case 3:
            peek(a);
            break;
    }
}while(c!=4);
}
void push(int a[],int val)
{
    if(top==MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top=top+1;
        a[top]=val;
    }
}
void pop(int a[])
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("element %d has been popped\n",a[top]);
        top--;
    }
}
void peek(int a[])
{
    if(top==-1)
    {
        printf("stack is empty\n");

    }
    else
    {
        printf("%d",a[top]);
    }
}
