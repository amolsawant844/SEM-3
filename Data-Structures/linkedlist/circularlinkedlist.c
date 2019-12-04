#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node * start);
struct node *displ(struct node * start);
struct node *addnodeinbeg(struct node * start);
struct node *addnodeinend(struct node * start);
struct node *delnodefrombeg(struct node * start);
struct node *delnodefromend(struct node * start);
struct node *delnodeaftergivennode(struct node * start);
void main()
{
int c;
    do
    {

    printf("Enter your choice\n");
    printf("1. create a cll\n");
    printf("2. display\n");
    printf("3. add node in beg\n");
    printf("4. add node in end\n");
    printf("5. del node from beg\n");
    printf("6. del node from end\n");
    printf("7. del node after a given node\n");
    printf("enter 8 to exit\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        start=create(start);
        break;
    case 2:
        start=displ(start);
        break;
    case 3:
        start=addnodeinbeg(start);
        break;
    case 4:
        start=addnodeinend(start);
        break;
    case 5:
        start=delnodefrombeg(start);
        break;
    case 6:
        start=delnodefromend(start);
        break;
    case 7:
        start=delnodeaftergivennode(start);
        break;

    }
    }
    while(c!=8);
}
struct node *create(struct node * start)
{
    int num;
    struct node *nn,*ptr;
    printf("enter a number\n");
    printf("enter -1 to stop.\n");
    scanf("%d",&num);
    do
    {
    nn=(struct node*)malloc(sizeof(struct node));

    nn->data=num;
    if(start==NULL)
    {
        start=nn;
        nn->next=start;
    }
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=nn;
        nn->next=start;

    }
     printf("enter a number\n");
        scanf("%d",&num);

    }while(num!=-1);
    return start;
}
struct node *displ(struct node * start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }
    return start;

}
struct node *addnodeinbeg(struct node * start)
{
    struct node *nn,*ptr;
    int num;
    printf("enter a number\n");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    nn->next=start;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    start=nn;
    return start;
}
struct node *addnodeinend(struct node * start)
{
    struct node *nn,*ptr;
    int num;
    printf("enter a number\n");
    scanf("%d",&num);
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=num;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->next=start;
    return start;
}
struct node *delnodefrombeg(struct node * start)
{

    struct node *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
    start=ptr->next;
return start;
}
struct node *delnodefromend(struct node * start)
{
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=start;
    free(ptr);
    return start;
}
struct node *delnodeaftergivennode(struct node * start)
{
    struct node *ptr,*preptr;
    int num;
    ptr=start;
    preptr=ptr;
    printf("enter a value\n");
    scanf("%d",&num);
    while(ptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
