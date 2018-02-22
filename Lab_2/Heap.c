#include<stdio.h>
#include<math.h>

void CreateMaxHeap(int a[],int n)
{

}

void main()
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


}
