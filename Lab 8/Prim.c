#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

main()
{
    int n=6;
    int i,j,d[6]={0},pp[6]={0},visited[6]={0},NC=0,from[6]={0};
    int span[6][6]={0};
    //printf("S:0 , A:1, B:2, C:3, D:4\n");

    //Input cost array

    int c[6][6]={0,7,9,0,0,14,7,0,10,15,0,0,9,10,0,11,0,2,0,15,11,0,6,0,0,0,0,6,0,9,14,0,2,0,9,0};
    printf("\nCost array: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
            span[i][j]=0;
            if(i==j)
                c[i][j]=0;
            else if(c[i][j]==0)
                c[i][j]=INT_MAX;
        }
        printf("\n");
    }
    int s = 0;
    //Initialize
    for(i=0;i<n;i++)
    {
        d[i]=c[s][i];

    }
    d[0] = 0;
    visited[s] = 1;
    int minCost = 0,numEdge = n-1;
    int v,u;
    while(numEdge>0)
    {
        int minDist = INT_MAX;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0 && d[i]<minDist)
            {
                v=i;
                minDist = d[i];
            }
        }
        u = from[v];
        span[u][v] = d[v];
        span[v][u] = d[v];

        --numEdge;
        visited[v] = 1;

        for(i=1;i<n;i++)
        {
            if(visited[i]==0 && c[i][v]<d[i])
            {
                d[i] = c[i][v];
                from[i] = v;
            }
        }

        minCost+=c[u][v];

    }



    printf("\n\n\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",span[i][j]);
        printf("\n");
    }
    printf("%d",minCost);

}
