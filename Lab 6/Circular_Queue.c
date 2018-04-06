#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int front=-1,rear=-1,n=10;
int cq[10];

// Check if the Queue is Empty
int IsEmptyQueue()
{
    // If the front and rear have -ve co-efficients then the queue is Empty
    if(front==-1 && rear ==-1)
        return 1;
    else
        return 0;
}

int IsFullQueue()
{
    // If the front and rear are one behind the other in a circular method, then Queue is Full
    if(rear == (front+9)%10)
        return 1;
    else
        return 0;
}

void Enqueue(int input)
{
    if(IsFullQueue())
        return;
    else if(IsEmptyQueue())
    {
        front=rear=6;
        cq[rear]=input;
    }
    else
    {
        rear = (rear+1)%n;
        cq[rear] = input;
    }
}

int Dequeue()
{
    int ret;
    if(IsEmptyQueue())
        return;
    else if(front == rear)
    {
        ret = cq[front];
        front=rear=-1;
        return ret;
    }
    else
    {
        ret = cq[front];
        front = (front+1)%n;
        return ret;
    }
}

int QueueFront()
{
    return cq[front];
}

void main()
{
    int i,j;
    Enqueue(10);
    Enqueue(12);
    Enqueue(15);
    Enqueue(20);
    Enqueue(27);
    Enqueue(36);
    Enqueue(45);

    for(i=front; i != (rear+1)%n; i = (i+1)%n)
    {
        printf("%d     ",cq[i]);
    }
    printf("\n  %d     %d",front,rear);
    Dequeue();
    Dequeue();
    printf("\n\n\n\n\n");
    for(i=front; i != (rear+1)%n; i = (i+1)%n)
    {
        printf("%d     ",cq[i]);
    }
    printf("\n  %d     %d",front,rear);
}
