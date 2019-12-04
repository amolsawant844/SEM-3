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

    }
    else if(r==MAX-1)
    {
        printf("overflow\n");
        return;
    }
    else
    {
        r++;
    }
    q[r]=x;
}
void del()
{
    if(f>r || f==-1)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        printf("element %d has been deleted",q[f]);
        f++;

    }
}
void peek()
{
    if(f>r || f==-1)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        printf("element %d ",q[f]);


    }
}
void disp()
{
    int i;
    if(f>r || f==-1)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        for(i=f;i<=r;i++){
        printf("%d ",q[i]);}


    }
}
