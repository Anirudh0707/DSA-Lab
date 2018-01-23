#include<stdio.h>
void bubble(int *a,int count)
{
    int i,temp,j;
    for(i=0;i<count;i++)
    {
        for(j=0;j<count-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

int main()
{
    int i,count=0;
    FILE *fptr,*out;
    fptr=fopen("inp1m.txt","r");
    out=fopen("bubsort.txt","w+");

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
bubble(array,count);
    for(i=0;i<count;i++)
    {
        fprintf(out,"%d ",array[i]);
    }
fclose(fptr);
fclose(out);
return 0;
}
