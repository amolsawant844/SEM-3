#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start);
struct node *addbeg(struct node *start);
struct node *addend(struct node *start);
struct node *addbefval(struct node *start);
struct node *addaftval(struct node *start);
struct node *delbeg(struct node *start);
struct node *delend(struct node *start);
struct node *delnodewithaval(struct node *start);
struct node *delnodeafter(struct node *start);
struct node *delcompl(struct node *start);
//struct node *sortthelist(struct node *start);
struct node *display(struct node *start);
void main()
{
    int num;
    do
    {
        printf("enter -1 to exit\n");
        printf("enter your choice\n");
        printf("1. create a linked list\n");
        printf("2. add a node at the beginning of a linked list\n");
        printf("3. add a node at the end of a linked list\n");
        printf("4. add a node before a value in a linked list\n");
        printf("5. add a node after a value in a linked list\n");
        printf("6. delete the node present at the beginning of a linked list\n");
        printf("7. delete the node present at the end of a linked list\n");
        printf("8. delete a node with a certain value present in the linked list\n");
        printf("9. delete a node after a certain value in a linked list\n");
        printf("10. delete the complete linked list\n");
        //printf("11. sort the  linked list\n");
        printf("12. display the linked list\n");
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            start=create(start);
            break;
        case 2:
            start=addbeg(start);
            break;
        case 3:
            start=addend(start);
            break;
        case 4:
            start=addbefval(start);
            break;
        case 5:
            start=addaftval(start);
            break;
        case 6:
            start=delbeg(start);
            break;
        case 7:
            start=delend(start);
            break;
        case 8:
            start=delnodewithaval(start);
            break;
        case 9:
            start=delnodeafter(start);
            break;
        case 10:
            start=delcompl(start);
            break;
        /*case 11:
            start=sortthelist(start);
            break;*/
        case 12:
            start=display(start);
            break;
        default:
            printf("invalid input\n");

        }
    }while(num!=-1);
}
struct node *create(struct node *start)
{
    int n;
    printf("enter -1 to exit\n ");
    printf("enter the data\n");
    scanf("%d\n",&n);
    struct node *ptr,*newnode;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=n;
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
    printf("enter -1 to exit\n ");
    printf("enter the data\n");
    scanf("%d \n",&n);
    }while(n!=-1);
    return start;
}
struct node *addbeg(struct node *start)
{
    int n;
    struct node *ptr,*newnode;
    printf("enter the data");
    scanf("%d",&n);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=start;
    start=newnode;
        return start;
}
struct node *addend(struct node *start)
{
    int n;
    struct node *ptr,*newnode;
    printf("enter the data");
    scanf("%d",&n);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    return start;
}
struct node *addbefval(struct node *start)
{
    int n,num;
    struct node *ptr,*preptr,*newnode;
    printf("enter the data\n");
    scanf("%d",&n);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    ptr=start;
    printf("enter the value to be entered before\n");
    scanf("%d",&num);
    while(ptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
struct node *addaftval(struct node *start)
{
    int n,num;
    struct node *ptr,*preptr,*newnode;
    printf("enter the data\n");
    scanf("%d",&n);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    ptr=start;
    printf("enter the value to be entered before\n");
    scanf("%d",&num);
    while(preptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
struct node *delbeg(struct node *start)
{
    struct node *ptr,*newnode;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node *delend(struct node *start)
{
    struct node *ptr,*preptr,*newnode;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}
struct node *delnodewithaval(struct node *start)
{
    struct node *ptr,*preptr,*newnode;
    ptr=start;
    int n;
    printf("enter the the value f node to be deleted\n");
    scanf("%d",&n);
    if(ptr->data==n)
    {
        start=delbeg(start);
    }
    else
    {
        while(ptr->data!=n)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}

struct node *delnodeafter(struct node *start)
{
    struct node *ptr,*preptr,*newnode;
    ptr=start;
    int n;
    printf("enter the the value f node to be deleted\n");
    scanf("%d",&n);
    if(preptr->data==n)
    {
        start=delbeg(start);
    }
    else
    {
        while(ptr->data!=n)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}
struct node *delcompl(struct node *start)
{
    struct node *ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            start=delbeg(ptr);
            ptr=start;
        }
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
