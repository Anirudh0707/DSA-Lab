#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct node{
int data;
struct node *rc,*lc;
};

struct node* CreateNode(int input)
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    NewNode->data = input;
    NewNode->lc = NULL;
    NewNode->rc = NULL;
    return NewNode;
}

void Insert(struct node**root,int input)
{
    if(*root==NULL)
        *root = CreateNode(input);
    else if(input <= (*root)->data)
        Insert(&((*root)->lc),input);
    else
        Insert(&((*root)->rc),input);
}

void Inorder(struct node *root)
{
    if(root == NULL)
        return;
    Inorder(root->lc);
    printf("%d      ",root->data);
    Inorder(root->rc);
}

struct node* FindNode(struct node *root,int input)
{
    if(root->data == input)
        return root;
    else if(input < root->data)
        return FindNode(root->lc,input);
    else
        return FindNode(root->rc,input);
}

int bstMin(struct node *root)
{
    if(root == NULL)
        return -1;
    else if(root->lc == NULL)
        return root->data;

    return bstMin(root->lc);

}

void del(struct node *root, int input)
{
    struct node *temp = FindNode(root,input);
    if(temp->lc != NULL && temp->rc != NULL);
}

void main()
{
    struct node *temp,*r=NULL;

    Insert(&r,27);
    Insert(&r,35);
    Insert(&r,15);
    Insert(&r,10);
    Insert(&r,18);
    Insert(&r,40);
    Insert(&r,30);
    Insert(&r,20);
    Insert(&r,12);
    Insert(&r,16);
    Insert(&r,5);
    Inorder(r);

    int i;
    i = bstMin(r);
    printf("   ///  %d /// ",i);



}
