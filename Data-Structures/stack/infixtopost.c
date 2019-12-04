#include<stdio.h>
#define MAX 10
int top=-1;
void push(char b);
char pop();
int prec(char b);
char exp[MAX];
char stk[MAX];
char postfix[MAX];
void main()
{
    int p=0,i,l;
    char t,temp;
    top++;
    stk[top]='#';
    printf("enter an exp\n");
    scanf("%s",exp);
    int len=strlen(exp);
    for(i=0;i<len;i++)
    {
        t=exp[i];
       switch(t)
       {
       case '(':
        push(t);
        break;
       case ')':
        temp=pop();
        while(temp!='(')
        {
            postfix[p++]=temp;
            temp=pop();
        }
        break;
       case '+':
       case '-':
       case '/':
       case '*':
       case '%':
       case '^':
           l=prec(t);
           while(stk[top]!='#'&& l<=prec(stk[top]))
           {
               postfix[p++]=pop();
           }
           push(t);
           break;

       default:
        postfix[p++]=t;

       }
    }
    while(stk[top]!='#')
    {
        postfix[p++]=pop();
    }
    postfix[p]='\0';
    printf("postfix: %s",postfix);
}
void push(char b)
{
    if(top==MAX-1)
    {
        printf("overflow\n");
    }
    else
    {
        top++;
        stk[top]=b;
    }
}
char pop()
{
    char c;
    if(top==-1)
    {
        printf("underflow\n");
        return ;
    }
    else
    {
        c=stk[top];
        top--;
        return c;
    }
}
int prec(char b)
{
    switch(b)
    {
        case '(':
               return 0;
               break;
        case '-':
        case '+':
            return 1;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        case '^':
            return 3;
            break;
    }
}
