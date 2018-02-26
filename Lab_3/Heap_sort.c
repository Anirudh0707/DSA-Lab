#include<stdio.h>

void createmaxheap(int a[], int n, int i)
{
    int parent = i, left = 2*i+1, right = 2*i+2;
    if(left<n && a[left]>a[parent])
        parent = left ;
    if(right<n && a[right]>a[parent])
        parent = right ;

    if(parent!=i)
    {
        a[parent] = a[parent] ^ a[i];
        a[i] = a[parent] ^ a[i];
        a[parent] = a[parent] ^ a[i];

        createmaxheap(a,n,parent);
    }
}

void heapsort(int a[], int n)
{
    int i,temp;
    // Build a Max Heap
    for(i=n/2-1;i>=0;i--)
    {
       // printf("2");
        createmaxheap(a,n,i);
    }

    // Remove last element at the root and swap with the last element
    for(i=n-1;i>0;i--)
    {
        //printf("3");
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        createmaxheap(a,i,0);
    }
}



int main()
{
    register int i,count=0;
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
   // printf("stage 1");
    heapsort(a,count);

    fclose(fptr);
    fptr = fopen("heap.txt","w+");
    for(i=0;i<count;i++)
    {
        fprintf(fptr,"%d  ",a[i]);
       // printf("%d   ",a[i]);
    }
    fclose(fptr);
}
