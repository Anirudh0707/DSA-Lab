#include<stdio.h>

struct node{
int data;
struct node *next;
} *head = NULL;

void addElement(int input)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    new_node->data = input;
    new_node->next = NULL;
    if(head==NULL)
        head = new_node;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = new_node;
    }
}

void rev()
{
    struct node *prev,*cur,*next;
    cur=head;
    prev=NULL;
    while(cur!=NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
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
    register int i;
    int input,n;
    printf("Enter the number of values ");
    scanf("%d",&n);
    printf("Enetr Value ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input);
        addElement(input);
    }
    printf("Printing The Elements As Entered \t");
    printElements();
    printf("\n\n");

    rev();
    printf("Printing Elements In Reverse \t");
    printElements();

}
