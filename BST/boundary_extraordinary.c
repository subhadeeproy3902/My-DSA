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
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL)
    return createNode(data);
  else if (data <= root->data)
    root->left = insert(root->left, data);
  else if (data >= root->data)
    root->right = insert(root->right, data);
  return root;
}

void leftPrint(TreeNode *root)
{
  if (!root || (!root->left && !root->right)) // Skip leaf nodes
    return;
  printf("%d ", root->data);
  leftPrint(root->left);
}

void rightPrint(TreeNode *root)
{
  if (!root || (!root->left && !root->right)) // Skip leaf nodes
    return;
  rightPrint(root->right);
  printf("%d ", root->data);
}

void bottomPrint(TreeNode *root)
{
  if (!root)
    return;
  if (!root->left && !root->right)
    printf("%d ", root->data);
  bottomPrint(root->left);
  bottomPrint(root->right);
}

void printTree(TreeNode *root)
{
  leftPrint(root);
  bottomPrint(root);
  rightPrint(root);
}

int main()
{
  TreeNode *root = NULL;
  int choice, val;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Boundary Traversal\n");

  while (1)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &val);
      root = insert(root, val);
      break;
    case 2:
      printTree(root);
      break;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}