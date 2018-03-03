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
    struct node *p;
    p=head;
    revRec(p);
}
void revRec(struct node *p)
{
    if(p->next == NULL)
    {
        head=p;
        return;
    }
    revRec(p->next);
    p->next->next=p;       // Reversing the link by saying that next of next it itself
    p->next=NULL;
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
