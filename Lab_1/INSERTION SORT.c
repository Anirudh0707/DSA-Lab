#include<stdio.h>

void insertion(int *a,int count)
{
    int i,hole,temp;
    for(i=1;i<=count-1;i++)
    {
        hole=i;
        temp=a[i];
        while(hole>0&&a[hole-1]>temp)
        {
                a[hole]=a[hole-1];
                hole=hole-1;
        }
        a[hole]=temp;
     }
}
int main()
{
    int i,count=0;
    FILE *fptr,*out;
    fptr=fopen("inp1m.txt","r");
    out=fopen("inssort.txt","w+");

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

insertion(array,count);
printf("The sorted elements: ");
for(i=0;i<count;i++)
{
    fprintf(out,"%d ",array[i]);
}
    fclose(fptr);
    fclose(out);
}
