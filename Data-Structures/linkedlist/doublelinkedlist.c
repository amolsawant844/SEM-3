#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL;
struct node *create(struct node * start);
struct node *displ(struct node * start);
struct node *addnodeinbeg(struct node * start);
struct node *addnodeinend(struct node * start);
struct node *delnodefrombeg(struct node * start);
struct node *delnodefromend(struct node * start);
struct node *delnodeaftergivennode(struct node * start);
struct node *addnodebeforeanode(struct node * start);
struct node *addnodeafteranode(struct node * start);
struct node *delnodebeforegivennode(struct node * start);
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
    printf("5. add node before a val\n");
    printf("6. add node after a val\n");
    printf("7. del node from beg\n");
    printf("8. del node from end\n");
    printf("9. del node before a given node\n");
     printf("10. del node after a given node\n");
    printf("enter 11 to exit\n");
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
        start=addnodebeforeanode(start);
        break;
    case 6:
        start=addnodeafteranode(start);
        break;
    case 7:
        start=delnodefrombeg(start);
        break;
    case 8:
        start=delnodefromend(start);
        break;
    case 9:
        start=delnodebeforegivennode(start);
        break;
    case 10:
        start=delnodeaftergivennode(start);
        break;

    }
    }
    while(c!=11);
}
struct node *create(struct node*start)
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
        nn->next=NULL;
        nn->prev=NULL;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=nn;
        nn->prev=ptr;
        nn->next=NULL;

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
    while(ptr->next!=NULL)
    {
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
    printf("% d",ptr->data);
    return start;
}
struct node *addnodeinbeg(struct node * start)
{
    struct node *nn,*ptr;
    int num;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("enter a val\n");
    scanf("%d",&num);
    nn->data=num;
    nn->next=start;
    nn->prev=NULL;
    start->prev=nn;
    start=nn;
    return start;

}
struct node *addnodeinend(struct node * start)
{
    struct node *nn,*ptr;
    int num;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("enter a val\n");
    scanf("%d",&num);
    nn->data=num;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=nn;
    nn->prev=ptr;
    nn->next=NULL;
    return start;
}
struct node *addnodebeforeanode(struct node * start)
{
 struct node *nn,*ptr,*preptr;
    int num,val;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("enter a val\n");
    scanf("%d",&num);
    printf("enter the node\n");
    scanf("%d",&val);
    nn->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=nn;
    nn->prev=preptr;
    nn->next=ptr;
    ptr->prev=nn;
    return start;
}
struct node *addnodeafteranode(struct node * start)
{
    struct node *nn,*ptr,*preptr;
    int num,val;
    nn=(struct node *)malloc(sizeof(struct node));
    printf("enter a val\n");
    scanf("%d",&num);
    printf("enter the node\n");
    scanf("%d",&val);
    nn->data=num;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=nn;
    nn->prev=preptr;
    nn->next=ptr;
    ptr->prev=nn;
    return start;

}
struct node *delnodefrombeg(struct node * start)
{
 struct node *ptr;
 ptr=start->next;
 ptr->prev=NULL;
 free(start);
 start=ptr;
 return start;
}
struct node *delnodefromend(struct node * start)
{
    struct node *ptr,*preptr;
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
struct node *delnodebeforegivennode(struct node * start)
{
        struct node *ptr,*preptr;
        ptr=start;
        int num;
        printf("enter a val\n");
        scanf("%d",&num);
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->prev->next=ptr;
        ptr->prev=preptr->prev;
        free(preptr);
        return start;
}
struct node *delnodeaftergivennode(struct node * start)
{
    struct node *ptr,*preptr;
        ptr=start;
        int num;
        printf("enter a val\n");
        scanf("%d",&num);
        while(preptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        ptr->next->prev=preptr;
        free(ptr);

        return start;

}
