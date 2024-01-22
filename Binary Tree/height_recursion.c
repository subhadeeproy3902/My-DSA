#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} TreeNode;

TreeNode *createNode(int data)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL)
  {
    root = createNode(data);
    return root;
  }

  TreeNode *temp;
  TreeNode *queue[100];
  int front = 0, rear = 0;
  queue[rear++] = root;

  while (front != rear)
  {
    temp = queue[front++];

    if (temp->left != NULL)
      queue[rear++] = temp->left;
    else
    {
      temp->left = createNode(data);
      return root;
    }

    if (temp->right != NULL)
      queue[rear++] = temp->right;
    else
    {
      temp->right = createNode(data);
      return root;
    }
  }
}

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  if (leftHeight > rightHeight)
    return leftHeight + 1;
  else
    return rightHeight + 1;
}

int main()
{
  TreeNode *root = NULL;
  int choice, val, a;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");

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
      a = height(root);
      printf("Height of tree is %d\n", a);
      break;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}