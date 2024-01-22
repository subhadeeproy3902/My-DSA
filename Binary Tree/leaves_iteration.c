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

int countNodes(TreeNode *node)
{
  if (node == NULL) return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL) return createNode(data);
  if (root->left == NULL) root->left = createNode(data);
  else if (root->right == NULL) root->right = createNode(data);
  else {
    if (countNodes(root->left) <= countNodes(root->right)) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
  }
  return root;
}


void leaves(TreeNode* root){
  if (root == NULL) return;
  TreeNode* stack[100];
  int top = -1;
  stack[++top] = root;
  while (top != -1){
    TreeNode* node = stack[top--];
    if (node->left == NULL && node->right == NULL) printf("%d ", node->data);
    else {
      if (node->right != NULL) stack[++top] = node->right;
      if (node->left != NULL) stack[++top] = node->left;
    }
  }
}



void print(TreeNode *root)
{
  if (root == NULL)
    return;
  print(root->left);
  printf("%d ", root->data);
  print(root->right);
}

int main()
{
  TreeNode *root = NULL;
  int choice, val;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");
  printf("3. Leaves\n");
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
      print(root);
      break;
    case 3:
      leaves(root);
      break;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}