#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;
struct node *push(struct node *top,int num);
struct node *pop(struct node *top);
struct node *peek(struct node *top);
struct node *display(struct node *top);
void main()
{
    int c,num;
    do{
    printf("enter your choice\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.display\n");
    printf("5.exit\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        printf("enter a number\n");
        scanf("%d",&num);
        top=push(top, num);
        break;
    case 2:
        top=pop(top);
        break;
    case 3:
        peek(top);
        break;
    case 4:
        top=display(top);
        break;

    }
    }while(c!=5);


}
struct node *push(struct node *top,int num)
{
    struct node*ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=num;
    if(top==NULL)
    {
        top=ptr;
        top->next=NULL;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;

}
struct node *pop(struct node *top)
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("underflow\n");

    }
    else
    {
        top=top->next;
        free(ptr);
    }
    return top;
}
struct node *peek(struct node *top)
{
    printf("element at the top:%d",top->data);
}
struct node *display(struct node *top)
{
    struct node *ptr;
    ptr=top;
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    return top;
}
