#include<stdio.h>

void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int pivot=partition(a,left,right);

        quicksort(a,left,pivot-1);
        quicksort(a,pivot+1,right);
    }
}
int partition(int a[],int left,int right)
{
    int pivot=a[right];
    int temp=0,j;
    int i=(left);
    for(j=left;j<=right-1;j++)
    {
        if(a[j]<=pivot)
        {
            temp=a[j];
            a[j]=a[i];
            a[i++]=temp;
        }
    }
    //temp=0;
    temp=a[right];
    a[right]=a[i];
    a[i]=temp;
    return(i);
}


int main()
{
    int i,count=0;
    FILE *fptr;
    fptr=fopen("inp1m.txt","r");
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
    quicksort(a,0,count-1);

    fclose(fptr);
    fptr = fopen("quick.txt","w+");
    for(i=0;i<count;i++)
    {
        fprintf(fptr,"%d  ",a[i]);
       // printf("%d   ",a[i]);
    }
    fclose(fptr);
}
