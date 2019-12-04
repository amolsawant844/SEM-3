#include<stdio.h>
#include<string.h>
#define MAX 10
void push(char s);
char pop();
int top=-1;
char exp[MAX];
char stk[MAX];
void main()
{
    int i,flag=1;
    char c,temp;
    printf("enter expression\n");
    scanf("%s",exp);
    int len=strlen(exp);
    for(i=0;i<len;i++)
    {
        c=exp[i];
        if(c=='{'||c=='('||c=='[')
        {
                push(c);
        }
        else if(c=='}'||c==')'||c==']')
        {
                temp=pop();
                if((c=='}')&&(temp=='['||temp=='('))
                    {
                        flag=0;break;
                    }
                else if((c==']')&&(temp=='{'||temp=='('))
                    {
                        flag=0;break;
                    }
                else if((c==')')&&(temp=='['||temp=='{'))
                    {
                        flag=0;break;
                    }

        }
    }
    if(flag==1)
    {
        printf("valid exp");
    }
    else if(flag==0)
    {
        printf("invalid exp");
    }
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
        return 0;
    }
    else
    {
        c=stk[top];
        top--;
        return c;
    }
}
