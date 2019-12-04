//when array is half sorted
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
    msort(a,n);
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
void msort(int a[],int n)
{
    int i,j,temp,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
