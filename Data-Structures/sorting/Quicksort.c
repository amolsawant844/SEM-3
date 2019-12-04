#include<stdio.h>
void main()
{
    int n,i;
    int a[100];
    printf("enter no. of elements\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("array before sorting:\n");
    displ(a,n);
    quick_sort(a,0,n-1);
    printf("array after sorting:\n");
    displ(a,n);

}
void displ(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void quick_sort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}
int partition(int a[],int p,int r)
{
    int i,j,x,temp;
    x=a[r];//setting pivot element to be the last element of the array
    i=p-1;
    for(j=p;j<r;j++)//makes an array with all elements less than pivot
    {
        if(a[j]<x)
        {
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }//now process of transferring and placing the pivot element
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;//returning the position of pivot element
}
