#include<stdio.h>


// Making a Data structure called stack

struct stack{
int data;
struct node *next;
};

// A Function to Pop the top element and return
int pop(struct stack **head)
{
    struct stack *temp = *head;

    // Assigning the data to the return variable
    int ret = temp->data;

    // Assigning the head to the next element so we can remove the top element
    *head = temp->next;

    // Freeing the memory location to erase the element
    free(temp);
    return ret;
}

// A Function to return the top element
int top(struct stack **head)
{
    struct stack *temp = *head;
    return temp->data;
}



void push(struct stack **head,int data)
{
    struct stack *new_node = (struct stack*)malloc(sizeof(struct stack));

    // Assigning the new_node its values

    new_node->data = data;
    new_node->next = *head;

    // Assigning the head to the new node so it becomes the top element
    *head = new_node;
}

// A Function to Check if the stack is Empty
int isStackEmpty(struct stack **head)
{
    // Check if the head is pointing to a NULL pointer. If true then stack is empty
    if(*head == NULL)
        return 1;
    else
        return 0;

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
        push(&high,input);
    }

    printf("\n\n");
    printf("Printing the Elements of the list\n");

    while(1)
    {
        if(isStackEmpty(&high))
            break;
        printf("%d\t",pop(&high));
    }

    printf("\n\n");
}
