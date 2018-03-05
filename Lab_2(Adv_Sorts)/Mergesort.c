#include<stdio.h>

void mergesort(int a[],int left,int right)
{
    if(left<right)
    {
       int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,right,mid);
    }
}
void merge(int a[],int left,int right,int mid)
{
    int i;
    int l1=mid-left+1;
    int l2=right-mid;
    int *leftarr=(int *)malloc(l1*sizeof(int));
    int *rightarr=(int *)malloc(l2*sizeof(int));
    for(i=0;i<l1;i++)
    {
        leftarr[i]=a[left+i];
    }
    for(i=0;i<l2;i++)
    {
        rightarr[i]=a[mid+i+1];
    }

    i=0;
    int j=0;
    int k=left;
    while(i<l1 && j<l2)
    {
        if(leftarr[i]<=rightarr[j])
            a[k++]=leftarr[i++];
        else
            a[k++]=rightarr[j++];
    }

    while(i<l1)
    {
        a[k++]=leftarr[i++];
    }
    while(j<l2)
    {
        a[k++]=rightarr[j++];
    }
    free(leftarr);
    free(rightarr);
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
    mergesort(a,0,count-1);

    fclose(fptr);

    fptr=fopen("merge.txt","w+");
    for(i=0;i<count;i++)
    {
        fprintf(fptr,"%d  ",a[i]);
        //printf("%d  ",a[i]);
    }
    fclose(fptr);
}
