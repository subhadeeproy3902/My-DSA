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

TreeNode * insert(TreeNode* root, int val){
  if(root == NULL) return createNode(val);
  TreeNode *curr = root;
  TreeNode *prev = NULL;
  while(curr != NULL){
    prev = curr;
    if(val <= curr->data) curr = curr->left;
    else curr = curr->right;
  }
  if(val <= prev->data) prev->left = createNode(val);
  else prev->right = createNode(val);
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