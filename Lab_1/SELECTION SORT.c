#include<stdio.h>

void sel(int *a,int count)
{
    int i,temp,temp2,j;
    for(i=0;i<count;i++)
    {
        temp=i;
        for(j=i+1;j<count;j++)
        {
            if(a[j]<a[temp])
                temp=j;
        }
        temp2=a[temp];
        a[temp]=a[i];
        a[i]=temp2;
    }
}

int main()
{
    int i,j,temp,temp2,count=0;
    FILE *fptr,*out;
    fptr=fopen("inp1m.txt","r");
    out=fopen("selsort.txt","w+");

    if(fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    if(out == NULL)
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

    int *array=(int *)malloc(count*sizeof(int));
    if(array==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    for(i=0;i<count ;i++)
    {
        fscanf(fptr, "%d", array+i);
    }
    sel(array,count);
    for(i=0;i<count;i++)
    {
        fprintf(out,"%d ",array[i]);
    }
    printf("Sorted in file");
    fclose(fptr);
    fclose(out);
}

