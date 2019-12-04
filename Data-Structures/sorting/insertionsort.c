/*
1) store the variable to be shifted in the another variable (temp=a[i];)
2) now keep on comparing the temp variable with its previous variable if less then shift
and if not then fix a[j+1]=temp;

*/
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
    insort(a,n);
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
void insort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(temp<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
