#include<stdio.h>

void radixsort(int a[],int n)
{
    int *bins[10];
    int count[10];
    int i,k,j,lsd,nop=0,passes,div=1;
    for(i=0;i<10;i++)
    {
        bins[i]=(int*)malloc(n*sizeof(int));
        //printf("%d ",i);
        count[i]=0;
    }
    int max=largest(a,n);
    printf("Largest is %d   ",max);
    while(max>0)
    {
        max/=10;
        nop++;
    }

    /* Distribution of the Elements */

    for(passes=0;passes<nop;passes++)
    {


        for(j=0;j<n;j++)
        {
            lsd= (a[j]/div)%10;
            bins[lsd][count[lsd]++] = a[j];
        }

        /* Retrieve Elements*/

        i=0;
        for(j=0;j<10;j++)
        {
            for(k=0;k<count[j];k++)
            {
                a[i++] = bins[j][k];
            }
        }
        div*=10;
        for(i=0;i<10;i++)
        {
            free(bins[i]);
            bins[i]=(int*)malloc(n*sizeof(int));
            count[i]=0;
        }
    }

}


int largest(int a[], int n)
{
    int large=a[0],i;
    for(i=0;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
        }
    }
    return large;
}

void main()
{
    int i,count=0;
    FILE *fptr;
    fptr=fopen("inp10.txt","r");
    if(fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&i);
        count++;
    }
    fseek(fptr,0, SEEK_SET);

    int *a=(int *)malloc(count*sizeof(int));
    if(a==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    for(i=0;i<count ;i++)
    {
        fscanf(fptr, "%d", a+i);
    }

    radixsort(a,count);

    fclose(fptr);
    fptr=fopen("radix.txt","w+");
    for(i=0;i<count;i++)
    {
        //fprintf(fptr,"%d  ",a[i]);
        fprintf(fptr,"%d  ",a[i]);
    }
    fclose(fptr);
}
