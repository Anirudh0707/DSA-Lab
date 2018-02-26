#include<stdio.h>


// Making a Data structure called node

struct node{
int data;
struct node *next;
};


// Making a new function to append new elements to the end of the linked list

void append(struct node **head,int input)
{
    // Creating a new node and assigning it the required values
    struct node *temp, *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = input;
    new_node->next = NULL;

    //Check if the Input is the First Element for the Linked List
    if(*head == NULL)
    {
        //Assigning the new node as the first element to the head
        *head = new_node;
    }
    else
    {
        // Using a temporary variable to traverse to the end of the list
        temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        // Assigning the new node as the last element of the list
        temp->next = new_node;
    }
}


void printElements(struct node **head)
{
    struct node *temp;
    temp = *head;

    // Running the Loop to print all elements rill the last Element has been reached
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
}

void delete_node(struct node **head,int position)
{
    struct node *temp,*del;
    temp = *head;
    register int i;

    // If position is one assign the link pointer to the next else traverse to find the node
    if(position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    else
    {
        // Each increment lead to next element with the first time leading to the second element
        // Hence traverse till the previous to the required position
        for(i=2;i<=position-1;i++)
        {
            temp = temp->next;
        }
        // With del as the node to be deleted and temp as previous and reassigning the link
        del = temp->next;
        temp->next = del->next;
    }
    free(del);
}

void insert_node(struct node **head,int data,int position)
{
    register int i;
    struct node *temp,*new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    temp = *head;

    // If position is one assign the link pointer to the next else traverse to find the node
    if(position == 1)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        // Each increment lead to next element with the first time leading to the second element
        // Hence traverse till the previous to the required position
        for(i=2;i<=position-1;i++)
        {
            temp = temp->next;
        }
        // With new_node as the node to be inserted and temp as previous, the link is reassigned
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void main()
{
    struct node *high=NULL;
    register int i;
    int input,n,position;

    printf("Enter the Number of Values to be Entered ");
    scanf("%d",&n);
    printf("Enter the Elements ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input);
        append(&high,input);
    }
    printf("Enter the position to delete ");
    scanf("%d",&position);
    delete_node(&high,position);
    insert_node(&high,input,position);


    printf("\n\n");
    printf("Printing the Elements of the list\n");
    printElements(&high);
    printf("\n\n");
}
