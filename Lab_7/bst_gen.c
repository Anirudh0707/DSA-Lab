#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
void bfs_print(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h+1; i++)
        currLev(root, i);
}

void currLev(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        currLev(root->left, level-1);
        currLev(root->right, level-1);
    }
}
int height(struct node* node)
{
    if (node==NULL)
        return -1;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
struct node* insert(struct node* node, int data)
{
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 27);
    insert(root, 35);
    insert(root, 15);
    insert(root, 10);
    insert(root, 18);
    insert(root, 40);
    insert(root, 30);
    insert(root, 20);
    insert(root, 12);
    insert(root, 16);
    insert(root, 5);
    insert(root, 17);
    insert(root, 45);
    printf("BFS : \n");
    bfs_print(root);
    printf("\nHeight = %d",height(root));
    return 0;
}
