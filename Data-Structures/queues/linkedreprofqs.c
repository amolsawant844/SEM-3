#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;

};
struct node *f=NULL;
struct node *r=NULL;
void insert();
void del();
void peek();
void disp();
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
    struct node *ptr;
    int num;
    printf("enter a number\n");
    scanf("%d",&num);
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=num;
    if(f==NULL && r==NULL)
    {
        f=ptr;
        r=ptr;
        f->next=NULL;
        r->next=NULL;

    }
    else
    {
        r->next=ptr;
        r=ptr;
        r->next=NULL;
    }
}
void del()
{
    struct node *ptr;
    if(f==NULL)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        ptr=f;
        f=f->next;
        free(ptr);
    }
}
void disp()
{
    struct node *ptr;
    ptr=f;
    if(f==NULL)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
    }
}
void peek()
{
    if(f==NULL)
    {
        printf("underflow\n");
        return;
    }
    else
    {
        printf("%d->",f->data);
    }


}
