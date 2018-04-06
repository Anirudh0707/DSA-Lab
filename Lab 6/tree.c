// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{

    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


int main()
{

    struct node *root = NULL;
    root=insert(root,27);
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

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 35\n");
    root = deleteNode(root, 35);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 18\n");
    root = deleteNode(root, 18);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}

