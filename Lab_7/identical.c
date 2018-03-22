#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                             malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}
int identicalTrees(struct node* a, struct node* b)
{
    if (a==NULL && b==NULL)
        return 1;
     if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }

    return 0;
}
 int main()
{
    struct node *root = newNode(27);
  root->left        = newNode(35);
  root->right       = newNode(15);
  root->left->left  = newNode(10);
  root->left->right = newNode(18);
  root->right->left = newNode(30);
  root->right->right= newNode(40);
  root->left->left->left= newNode(5);
  root->left->left->right= newNode(12);
  root->left->right->left = newNode(16);
  root->left->right->right = newNode(20);

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

    if(identicalTrees(root, root1))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");

    getchar();
  return 0;
}

