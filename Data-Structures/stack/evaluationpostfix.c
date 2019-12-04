
/*None selected

Skip to content
Using Gmail with screen readers

Conversations
2.8 GB (18%) of 15 GB used
Manage
Terms · Privacy · Program Policies
Last account activity: 5 minutes ago
Details
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
//#define Blank ' '
//#define Tab '\t'
#define MAX 50

 int pop();
long int eval_post();
char  infix[MAX],postfix[MAX];
char stack[MAX];
int top;
 //int  white_space(char symbol);

 void main()
{
	long int value;
    top=0;
    printf("Enter postfix: ");
    //fflush(stdin);
    scanf("%s",postfix);
    //infix_to_postfix();
    //printf("Postfix: %s\n",postfix);
    value=eval_post();
    printf("Value of expression: %ld\n",value);


}

push(char symbol)
{
			if(top==MAX-1)
			{
				printf("Stack overflow\n");
				exit(1);
			}
			else
			{
				top=top+1;
				stack[top]=symbol;
			}
}

int pop()
{
			if(top==-1)
			{
				printf("Stack underflow\n");
				exit(2);
			}
			else
			{
				return(stack[top--]);
			}
}

long int eval_post()
{
	long int a,b,temp,result,len;
	int i;
	len=strlen(postfix);

	for(i=0;i<len;i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push(postfix[i]-'0');
		else
		{
			a=pop();
			b=pop();

			switch(postfix[i])
			{
			case '+':
					temp=b+a;break;
			case '-':
					temp=b-a;break;
			case '*':
					temp=b*a;break;
			case '/':
					temp=b/a;break;
			case '%':
					temp=b%a;break;
			case '^':
					temp=pow(b,a);
			}
			push(temp);
		}
	}
	result=pop();
	return result;
}

/*int  white_space(char symbol)
{
		if(symbol==Blank||symbol==Tab||symbol=='\0')
			return 1;
		else
			return 0;
}*/

/*void infix_to_postfix()
{
	int i,p=0,type,precedence,len;
	char temp;
	stack[top]='#';
	len=strlen(infix);
	//infix[len]='#';

	for(i=0;i<len;i++)
	{
		//if(!white_space(infix[i]))
		//{
			switch(infix[i])
			{

			case '(':
					push(infix[i]);
					break;
			case ')':
                    temp=pop();
                    while(temp!='(')
                    {
                        postfix[p]=temp;
                        p++;
                        temp=pop();
                    }
                    break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
					precedence=prec(infix[i]);
					while(stack[top]!='#' && precedence<=prec(stack[top]))
						postfix[p++]=pop();
					push(infix[i]);
					break;
			default:
				postfix[p++]=infix[i];
			}

			for(i=0;i<top;i++)
            {
                printf("%c",stack[i]);
            }
		//}
	}
	while(stack[top]!='#')
			postfix[p++]=pop();
	postfix[p]='\0';
} */

/* int prec(char symbol)
{
	switch(symbol)
	{
	case '(':
			return 0;
	case '+':
	case '-':
			return 1;
	case '*':
	case '/':
	case '%':
			return 2;
	case '^':
			return 3;
	}
}*/



/*
EvalofPostfix.c
Displaying EvalofPostfix.c.
*/
