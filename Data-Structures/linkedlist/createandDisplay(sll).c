#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start);
struct node *display(struct node *start);
int main()
{
    start=create(start);
    start=display(start);
}
struct node *create(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\n enter -1 to end");
    printf("\n enter the data:");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));//creates a new node with empty data and empty next
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("\n enter the data:");
        scanf("%d",&num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
