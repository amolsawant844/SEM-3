#include<stdio.h>
#include<stdbool.h>
#define MAX 10
int stack[MAX];
int top = -1;

void push(int x)
{
        if(top == MAX - 1)
        {
        printf("Stack overflow\n");
        return;
        }
        stack[++top] = x;

}
void pop()
{
    if(top == -1)
    {
    printf("Stack Underflow\n");
    return ;
    }
    top--;
}

bool isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

void DFS(int adj[][MAX],int visited[],int start,int m)
{
    push(start);
 visited[start] = 1;
    while(!isEmpty())
    {
        start = stack[top];
        printf("%c -> ",65+start);
        pop();
        for(int i=0 ; i<m ;i++)
        {
            if(adj[start][i] == 1 && visited[i] == 0)
            {
                push(i);
                visited[i] = 1;
            }
        }


    }

}

int main()
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
DFS(adj,visited,0,m);

    return 0;
}
