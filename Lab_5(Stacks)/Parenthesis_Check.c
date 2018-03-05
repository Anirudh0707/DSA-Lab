#include<stdio.h>
#include<string.h>

// Making a Data structure called stack

struct stack{
char data;
struct node *next;
};

// A Function to Pop the top element and return
char pop(struct stack **head)
{
    struct stack *temp = *head;

    // Assigning the data to the return variable
    char ret = temp->data;

    // Assigning the head to the next element so we can remove the top element
    *head = temp->next;

    // Freeing the memory location to erase the element
    free(temp);
    return ret;
}

// A Function to return the top element
char top(struct stack **head)
{
    struct stack *temp = *head;
    return temp->data;
}



void push(struct stack **head,char data)
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


int validate(struct stack **head,char exp[],int n)
{
    struct stack *temp = *head;
    int ret,i;

    for(i=0;i<n;i++)
    {
        // If opening parenthesis then push to stack
        if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
            push(head,exp[i]);
        else if((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}'))
        {
            // If the current closing parenthesis corresponds to the top of the start(respective opening parenthesis then pop the top element
            // Else if invalid return -1 and quit the function
                if((isStackEmpty(head)))
                   return -1;
                if( ((exp[i] == ')')&&(top(head) == '(')) || ((exp[i] == ']')&&(top(head) == '[')) ||((exp[i] == '}')&&(top(head) == '{')) )
                    pop(head);
                else
                    return -1;
        }
    }
    // After the loop is stack is empty then not redundant parenthesis so the expression is correct else the expression is invalid
    if((isStackEmpty(head)))
        return 0;
    else
        return -1;
}


void main()
{
    struct node *braces=NULL;
    register int i;
    int input,n,position;
    char exp[100];

    printf("Enter the String ");
    scanf("%[^\n]s",exp);
    n = strlen(exp);

    int ret;

    // Validating the String, Returns 0 if Correct and -1 if the expression is invalid(parenthesis is unbalanced)
    ret = validate(&braces, exp, n);

    if(ret==0)
        printf("\n\nCorrect\n\n");
    else
        printf("\n\nInvalid\n\n");
}
