#include<stdio.h>
#define MAX 10
int top=-1;
char stk[MAX];
char postfix[MAX];

void main()
{
    int i;char c;
    int a,b,temp;
    printf("enter postfix exp\n");
    scanf("%s",postfix);
    int l=strlen(postfix);
    for(i=0;i<l;i++)
    {
        c=postfix[i];
        if(c>='0'&& c<='9')
        {
            push(c-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(c)
            {
            case '+':
                temp=b+a;
                break;
            case '-':
                temp=b-a;
                break;
            case '*':
                temp=b*a;
                break;
            case '/':
                temp=b/a;
                break;
            case '%':
                temp=b%a;
                break;
            }
            push(temp);
        }

    }
    printf("result:%d",pop());
}
void push(char b)
{
    if(top==MAX-1)
    {
        printf("overflow\n");
        exit(0);
    }
    else
    {
        top++;
        stk[top]=b;
    }
}
int pop()
{
    int c;
    if(top==-1)
    {
        printf("underflow\n");
        exit(1);
    }
    else
    {
        c=stk[top];
        top--;
        return c;
    }
}

