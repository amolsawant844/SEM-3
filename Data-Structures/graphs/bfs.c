#include<stdio.h>
#include<stdbool.h>
#define MAX 10

int Q[MAX];
 int front = -1,rear = -1;


bool isEmpty()
{
if(front == -1 && rear ==-1)
        return true;
        return false;
}

bool isFull()
{
    if (rear == MAX-1)
    return true;
    return false;
}


void EnQueue(int x)
{

    if(isFull())
    {
        printf("Elements Cannot be Added Queue is full\n");return;
    }
    else if (isEmpty())
    {

        front++;rear++;
    }
    else
    {

        rear++;
    }
    Q[rear] = x;

}
void DeQueue()
{
    if(isEmpty())
    {
    printf("Elements cannot be deleted as Queue is Empty\n");
    return ;
    }

    else if(front == rear) {front = -1 ; rear =-1 ;}
    else front++;


}




//start = starting node (0)
void BFS(int adj[][MAX],int visited[],int start,int m)
{

  EnQueue(start); //Added the first element in the queue
visited[start] = 1;

    while(!isEmpty())
    {

    start = Q[front];
     printf("%c ",start + 65);
    for(int i = 0 ; i< m ;i++)
    {
        if(adj[start][i] == 1 && visited[i] == 0)
        {
            EnQueue(i);
            visited[i] = 1;
        }
    }
    DeQueue();

    }

}


void main()
{

int visited[MAX] = {0};
int start = 0;
int adj[MAX][MAX],i,j,m,n;

printf("Enter number of rows and columns for Adjacency matrix\n");
scanf("%d",&m);
printf("Enter the Adjacency Matrix \n");
for(i = 0 ; i< m ;i++)
{
    for(j = 0;j< m; j++)
    {
        scanf("%d",&adj[i][j]);

    }

}
BFS(adj,visited,0,m);

}
