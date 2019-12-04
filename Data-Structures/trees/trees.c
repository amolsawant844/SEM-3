#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create(struct node*tree);
struct node *insert(struct node *tree,int num);
void pre(struct node *tree);
void in(struct node *tree);
void post(struct node *tree);
struct node *findsmall(struct node *tree);
struct node *findlarge(struct node *tree);
struct node *del(struct node *tree,int val);
void main()
{
    struct node *ptr;
    int c,val,num;
    create(tree);
    do
    {
        printf("\n1.insert\n");
        printf("2.preorder\n");
        printf("3.inorder\n");
        printf("4.postorder\n");
        printf("5.findsmall\n");
        printf("6.findlarge\n");
        printf("7.delete\n");
        printf("enter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter a number\n");
            scanf("%d",&num);
            tree=insert(tree,num);
            break;

        case 2:
            pre(tree);
            break;
        case 3:
            in(tree);
            break;
        case 4:
            post(tree);
            break;
        case 5:
            ptr=findsmall(tree);
            printf("smallest value is %d",ptr->data);
            break;
        case 6:
            ptr=findlarge(tree);
            printf("largest value is %d",ptr->data);
            break;
        case 7:
            printf("enter a value");
            scanf("%d",&val);
            del(tree,val);
            break;
        }
    }while(c!=8);
}
void create(struct node *tree)
{
    tree=NULL;
}
struct node *insert(struct node*tree,int num)
{
    struct node *nptr,*nn,*pptr;

    nn=(struct node *)malloc(sizeof(struct node));

    nn->data=num;
    nn->left=NULL;
    nn->right=NULL;

    if(tree==NULL)
    {
        tree=nn;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        nptr=tree;
        pptr=NULL;
        while(nptr!=NULL)
        {
            pptr=nptr;
            if(num>nptr->data)
                nptr=nptr->right;
            else
                nptr=nptr->left;
        }
        if(num>pptr->data)
            pptr->right=nn;
        else
            pptr->left=nn;
    }
    return tree;
}
void pre(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d \n",tree->data);
        pre(tree->left);
        pre(tree->right);
    }


}
void in(struct node*tree)
{
    if(tree!=NULL)
    {
        in(tree->left);
        printf("%d \n",tree->data);
        in(tree->right);
    }
}
void post(struct node*tree)
{
    if(tree!=NULL)
    {

        post(tree->left);
        post(tree->right);
        printf("%d \n",tree->data);
    }
}
struct node *findsmall(struct node*tree)
{
    if(tree==NULL||tree->left==NULL)
        return tree;
    else
        return findsmall(tree->left);
}
struct node *findlarge(struct node*tree)
{
    if(tree==NULL||tree->right==NULL)
        return tree;
    else
        return findlarge(tree->right);
}
struct node *del(struct node*tree,int data)
{
    if (tree == NULL) {
     return NULL;
  }
  if (data < tree->data) {  // data is in the left sub tree.
      tree->left = del(tree->left, data);
  } else if (data > tree->data) { // data is in the right sub tree.
      tree->right = del(tree->right, data);
  } else {
     // case 1: no children
     if (tree->left == NULL && tree->right == NULL) {
        free(tree); // wipe out the memory, in C, use free function
        tree = NULL;
     }
     // case 2: one child (right)
     else if (tree->left == NULL) {
        struct node *temp = tree; // save current node as a backup
        tree = tree->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (tree->right == NULL) {
        struct node *temp = tree; // save current node as a backup
        tree = tree->left;
        free(temp);
     }
     // case 4: two children
     else {
        struct node *temp = findsmall(tree->right); // find minimal value of right sub tree
        tree->data = temp->data; // duplicate the node
        tree->right = del(tree->right, temp->data); // delete the duplicate node
     }
  }
  return tree; // parent node can update reference
}
