#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

main()
{
    int n=5;
    int i,j,d[5]={0},pp[5]={0},v[5]={0},NC=0;
    int p[5][5]={0};
    printf("S:0 , A:1, B:2, C:3, D:4\n");
    //Input cost array
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter weight from %d to %d\nZero if no direct path\n",i,j);
            scanf("%d",&c[i][j]);
            if(i==j)
                c[i][j]=INT_MIN;
            else if(c[i][j]==0)
                c[i][j]=INT_MAX;

        }
    }
    */
    int c[5][5]={0,10,0,5,0,0,0,1,2,0,0,0,0,0,4,0,3,9,0,2,7,0,6,0,0};
    printf("\nCost array: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);

            if(i==j)
                c[i][j]=0;
            else if(c[i][j]==0)
                c[i][j]=INT_MAX;
        }
        printf("\n");
    }
    //Initialize
    for(i=0;i<n;i++)
    {
        d[i]=c[0][i];
        p[i][pp[i]++]= 0;
    }
    d[0]=0;
    v[0]=1;
    NC++;

    //Greedy algo
    int minD,next;
    int flag=0;
    while(NC<n)
    {
        minD=INT_MAX;
        for(i=1;i<n;i++)
        {
            if(d[i]<minD && v[i]==0)
            {
                minD = d[i];
                next = i;
                flag = 1;
            }
        }
        v[next]=1;

        for(i=0;i<n;i++)
        {
            if(v[i]==0 && minD+c[next][i] < d[i] && c[next][i] != INT_MAX)
            {
                d[i] = minD+c[next][i];
                p[i][pp[i]++] = next;

            }

        }
        //if(flag == 1)
            NC++;
        //else

    }

    for(i=0;i<n;i++)
    {
        printf("\nDistance from source to node %d = %d",i,d[i]);
        printf("\nPath : ");
        for(j=0;j<pp[i];j++)
            printf("%d ",p[i][j]);
        printf("%d \n",i);
    }
}
