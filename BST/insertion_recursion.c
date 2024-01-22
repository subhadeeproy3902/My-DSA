#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *left;
  struct Node *right;
} TreeNode;

TreeNode *createNode (int data){
  TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}


TreeNode* insert(TreeNode* root, int data){
  if (root == NULL) return createNode(data);
  else if (data <= root->data) root->left = insert(root->left, data);
  else if (data >= root->data) root->right = insert(root->right, data);
  return root;
}


void printTree(TreeNode *root){
  if(root == NULL) return;
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}

int main()
{
  TreeNode *root = NULL;
  int choice, val;
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
      printTree(root);
      break;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}