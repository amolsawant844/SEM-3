#include<stdio.h>
#define MAX 10
int f,r=-1;
int q[MAX];
void main()
{
    int c;
    do{
    printf("enter an option\n");
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.peek\n");
    printf("4.display\n");
    printf("5.exit\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        insert();
        break;
    case 2:
        del();
        break;
    case 3:
        peek();
        break;
    case 4:
        disp();
        break;

    }
    }while(c!=5);
}
void insert()
{
    int x;
    printf("enter a number to be inserted\n");
    scanf("%d",&x);

    if(f==-1 && r==-1)
    {
        f=r=0;
        q[r]=x;
    }
    else if(f==0 && r==MAX-1)
    {
        printf("overflow\n");
        return ;
    }
    else if(f!=0 && r==MAX-1)
    {
        r=0;
        q[r]=x;
    }
    else if(f==0 && r!=MAX-1)
    {
        r++;
        q[r]=x;
    }
}
void del()
{
    if(f!=0 && r==MAX-1)
    {
        f++;
    }
    else if(f==-1 && r==-1)
    {
        printf("underflow\n ");
        return;
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else if(f==MAX-1)
    {
        f=0;
    }
}
void peek()
{
    if(f==-1 && r==-1)
    {
        printf("underflow\n ");
        return;
    }
    else
    {
        printf(":%d",q[f]);
    }
}
void disp()
{
    int i;
    if(f==-1 && r==-1)
    {
        printf("underflow\n ");
        return;
    }
    else
    {
        if(f<r)
        {
            for(i=f;i<=r;i++)
            {
                printf("\t %d",q[i]);
            }

        }
        else
        {
            for(i=f;i<=MAX-1;i++)
            {
                printf("\t %d",q[i]);
            }
            for(i=0;i<=r;i++)
            {
                printf("\t %d",q[i]);
            }
        }
    }
}
