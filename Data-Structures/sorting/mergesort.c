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
    merge_sort(a,0,n-1);
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
void merge_sort(int a[],int beg,int end)//divides the array into sub parts
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void merge(int a[],int beg,int mid,int end)//handles the merging part
{
    int i,index,j,k;//index is the control to store data in temp array
    int temp[100];
    i=beg;//i->will compare first half
    j=mid+1;//j->will compare second half
    index=beg;
    while(i<=mid&&j<=end)//stores elements upto a certain part
    {
        if(a[i]<=a[j])//compares first elements of both parts and stores it in the temp array
        {
            temp[index]=a[i];
            i++;
        }
        else
        {
            temp[index]=a[j];
            j++;
        }
        index++;
    }
    if(i>mid)//stores the remaining part
    {
        while(j<=end)
        {
            temp[index]=a[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index]=a[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)//storing it in array a
    {
        a[k]=temp[k];
    }
}
