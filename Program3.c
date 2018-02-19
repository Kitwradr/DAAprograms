#include <stdio.h>
#include <stdlib.h>
int count=0;

void dfs(int a[10][10], int n , int v[10] , int source)
{
    int j;
    v[source] = 1;
    if(count == 1)
       printf("%d " , source);
    for(j=0; j<n; j++)
        if(a[source][j] == 1 && v[j] == 0)
            dfs(a,n,v,j);
}


//void dfs1(int a[][])
void bfs(int a[10][10], int n , int v[10] , int source)
{
    int q[10] , front =0 , rear =-1;
    int node , i;
    v[source] = 1;
    q[++rear] = source;
    while(front<=rear)
    {

        node = q[front++];
        printf("%d " , node);
        for(i=0;i<n;i++)
            if(a[node][i]==1 && v[i]==0)
            {
                v[i] = 1;
                q[++rear] = i;
            }

    }
}


int main()
{
    int n , ch , flag = 0;
    int a[10][10];
    int v[10] , source;
    int i,j;
    printf("Enter the number of nodes :\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter source\n");
    scanf("%d",&source);
    for(i=0; i<n; i++)
        v[i]=0;
    printf("Enter the choice\n1: DFS\n2: BFS\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1 :
    printf("Result: ");
        for(i=0; i<n; i++)
        {
        if(v[i]==0)
        {
        count ++;

        dfs(a,n,v,i);

            }
        }


    if(count==1)
        printf("Graph is connected\n");
    else
        printf("Graph is disconnected with %d components\n",count);
    break;
//Breasdth First seacrch
    case 2 :
    printf("Result: ");
        for(i=0; i<n; i++)
        {
        if(v[i]==0)
        {
            bfs(a,n,v,i);
            count++;
            }
        }


    if(count==1)
        printf("Graph is connected\n");
    else
        printf("Graph is disconnected with %d components\n",count);
    break;

}
    return 0;
}
