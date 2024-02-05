#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} TreeNode;

TreeNode *createNode(int data)
{
  TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
  n->data = data;
  n->left = n->right = NULL;
  return n;
}

int height(TreeNode *root)
{
  if (!root)
    return 0;
  int lh = height(root->left);
  int rh = height(root->right);
  return (lh > rh ? lh : rh) + 1;
}

TreeNode *rightRotate(TreeNode *root)
{
  TreeNode *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

TreeNode *leftRotate(TreeNode *root)
{
  TreeNode *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

TreeNode *insert(TreeNode *root, int data)
{
  if (!root)
    return createNode(data);
  else if (root->data > data)
    root->left = insert(root->left, data);
  else if (root->data < data)
    root->right = insert(root->right, data);
  else
    return root;

  int balance = height(root->left) - height(root->right);
  if (balance > 1)
  {
    if (data < root->left->data)
      return rightRotate(root);
    else
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balance < -1)
  {
    if (data > root->right->data)
      return leftRotate(root);
    else
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

void display(TreeNode *root)
{
  if (!root)
    return;
  printf("%d ", root->data);
  display(root->left);
  display(root->right);
}

TreeNode* min(TreeNode* root)
{
  TreeNode* current = root;
  while (current->left != NULL)
    current = current->left;
  return current;
}

TreeNode *delete(TreeNode *root, int data)
{
  if (!root)
    return root;
  if (data < root->data)
    root->left = delete(root->left, data);
  else if (data > root->data)
    root->right = delete(root->right, data);
  else
  {
    if (root->left == NULL || root->right == NULL)
    {
      TreeNode *temp = root->left ? root->left : root->right;
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else
        *root = *temp;
      free(temp);
    }
    else
    {
      TreeNode *temp = min(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  if (root == NULL)
    return root;
  int balance = height(root->left) - height(root->right);
  if (balance > 1)
  {
    if (height(root->left->left) >= height(root->left->right))
      return rightRotate(root);
    else
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balance < -1)
  {
    if (height(root->right->right) >= height(root->right->left))
      return leftRotate(root);
    else
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

int main()
{
  printf("0. Exit\n1. Insert\n2. Display\n3. Delete\n");
  TreeNode *root = NULL;
  int ch, data;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      display(root);
      printf("\n");
      break;
    case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      root = delete(root, data);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}