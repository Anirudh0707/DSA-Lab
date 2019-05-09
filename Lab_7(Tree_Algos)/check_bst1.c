#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

static struct node *prev = NULL;
 int is_bst(struct node* root)
{
    if (root)
    {
        if (!is_bst(root->left))
            return 0;
        if (prev != NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return is_bst(root->right);
    }
    return 1;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{

      struct node *root = newNode(27);
  root->left        = newNode(15);
  root->right       = newNode(35);
  root->left->left  = newNode(10);
  root->left->right = newNode(18);
  root->right->left = newNode(30);
  root->right->right= newNode(40);
  root->left->left->left= newNode(5);
  root->left->left->right= newNode(12);
  root->left->right->left = newNode(16);
  root->left->right->right = newNode(20);
    if (is_bst(root))
        printf("A is a valid BST\n");
    else
        printf("A is not a valid BST\n");
    prev = NULL;
      struct node *root1 = newNode(27);
  root1->left        = newNode(15);
  root1->right       = newNode(35);
  root1->left->left  = newNode(10);
  root1->left->right = newNode(18);
  root1->right->left = newNode(30);
  root1->right->right= newNode(5);
  root1->left->left->left= newNode(12);
  root1->left->left->right= newNode(16);
  root1->left->right->left = newNode(20);
  root1->left->right->right = newNode(17);
  root1->right->left->left = newNode(45);
    if (is_bst(root1))
        printf("B is a valid BST");
    else
        printf("B is not a valid BST");
    return 0;
}
