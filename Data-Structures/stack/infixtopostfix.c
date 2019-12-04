#include<stdio.h>
#include<math.h>
#include<string.h>
//#define Blank ' '
//#define Tab '\t'
#define MAX 50

 int pop();
/*long int eval_post();*/
char  infix[MAX],postfix[MAX];
 char stack[MAX];
int top;
 //int  white_space(char symbol);

 void main()
{
	long int value;
    top=0;
    printf("Enter infix: ");
    //fflush(stdin);
    scanf("%s",infix);
    infix_to_postfix();
    printf("Postfix: %s\n",postfix);
    //value=eval_post();
//printf("Value of expression: %ld\n",value);


}


 int prec(char symbol)
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
    case '$':
			return 3;
	}
}

push( char symbol)//only transfers symbols into stack
{
			if(top>MAX)
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

char pop()//gives you what is present on the top of stack
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

/*int  white_space(char symbol)
{
		if(symbol==Blank||symbol==Tab||symbol=='\0')
			return 1;
		else
			return 0;
}*/

void infix_to_postfix()
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
            case '$':
					precedence=prec(infix[i]);
					while(stack[top]!='#' && precedence<=prec(stack[top]))
						{postfix[p++]=pop();}
					push(infix[i]);
					break;
			default:
				postfix[p++]=infix[i];
			}

			/*for(i=0;i<top;i++)
            {
                printf("%c",stack[i]);
            }*/
		//}
	}
	while(stack[top]!='#')
			{postfix[p++]=pop();}
	postfix[p]='\0';
}

/*long int eval_post()
{
	long int a,b,temp,result,len;
	int i;
	len=strlen(postfix);
	postfix[len]='#';
	for(i=0;postfix[i]='#';i++)
	{
		if(postfix[i]<='9' && postfix[i]>='0')
			push(postfix[i]-48);
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
}*/




