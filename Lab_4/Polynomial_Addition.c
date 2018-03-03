#include<stdio.h>

struct node{
int data;
int exp;
struct node *next;
}*head[3];

void addElement(int i,int input,int degree)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    new_node->data = input;
    new_node->exp = degree;
    new_node->next = NULL;
    if(head[i]==NULL)
        head[i] = new_node;
    else
    {
        temp=head[i];
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next = new_node;
    }
}


void printElements(int i)
{
    struct node *temp;
    temp=head[i];
    while(temp!=NULL)
    {
        printf("%d\t", temp->data);
        printf("%d\n",temp->exp);
        temp=temp->next;
    }
}

void polyAdd()
{
    struct node *p1 = head[0], *p2 = head[1];
    struct node *p3 = head[2],*ptr;
    while(p1!=NULL && p2!=NULL)
    {
        if((p1->exp) > (p2->exp))
        {
            addElement(2,p1->data,p1->exp);
            p1 = p1->next;
        }
        else if((p1->exp) < (p2->exp))
        {
            addElement(2,p2->data,p2->exp);
            p2 = p2->next;
        }
        else
        {
            addElement(2,p2->data+p1->data,p2->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if(p1!=NULL)
        ptr=p1;
    if(p2!=NULL)
        ptr=p2;


    while(ptr!=NULL)
    {
        printf("^^^^^^^^^^^");
        addElement(2,ptr->data,ptr->exp);
        ptr = ptr->next;

    }
}


void main()
{
    struct node *high=NULL;
    int input,n,degree;

    printf("Second Polynomial");

    FILE *fptr;
    fptr=fopen("p1.txt","r");
    if(fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&input);
        fscanf(fptr,"%d",&degree);
        addElement(0,input,degree);
    }
    printElements(0);
    fclose(fptr);

    printf("Second Polynomial");

    fptr=fopen("p2.txt","r");
    if(fptr == NULL)
    {
        printf("error");
        exit(1);
    }
    while(!feof(fptr))
    {
        fscanf(fptr,"%d",&input);
        fscanf(fptr,"%d",&degree);
        addElement(1,input,degree);
    }
    printElements(1);
    fclose(fptr);



    fptr=fopen("p3.txt","w");

    polyAdd();

    printf("\n\n\n");
    printElements(2);


}
