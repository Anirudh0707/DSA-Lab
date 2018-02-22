#include<stdio.h>

struct node{
int data;
struct node *next;
} *head = NULL;

void addElement(int input)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = input;
    temp->next = NULL;
    if(head==NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}

void printElements()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
}


void main()
{
    int input,i;
    for(i=0;i<10;i++)
    {
        printf("Enetr Value ");
        scanf("%d",&input);
        addElement(input);
    }
    printf("Printing the elements\t");
    printElements();
}
