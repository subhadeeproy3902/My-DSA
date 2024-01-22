#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
} TreeNode;

TreeNode *createNode(int data){
  TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int height(TreeNode *root){
  if(root == NULL)
    return 0;
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}


TreeNode *rightRotate(TreeNode *root){
  TreeNode *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  return newRoot;
}

TreeNode *leftRotate(TreeNode *root){
  TreeNode *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  return newRoot;
}

TreeNode *insert(TreeNode *root, int data){
  if(root == NULL)
    return createNode(data);
  if(data < root->data)
    root->left = insert(root->left, data);
  else if(data > root->data)
    root->right = insert(root->right, data);
  else
    return root;
  int balance = height(root->left) - height(root->right);
  if(balance > 1){
    if(data < root->left->data)
      return rightRotate(root);
    else{
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if(balance < -1){
    if(data > root->right->data)
      return leftRotate(root);
    else{
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

void inorder(TreeNode *root){
  if(root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(TreeNode *root){
  if(root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(TreeNode *root){
  if(root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}




int main(){
  TreeNode *root = NULL;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Inorder\n");
  printf("3. Preorder\n");
  printf("4. Postorder\n");

  int choice, data;
  while(1){
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 0:
        exit(0);
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Inorder: ");
        inorder(root);
        break;
      case 3:
        printf("Preorder: ");
        preorder(root);
        break;
      case 4:
        printf("Postorder: ");
        postorder(root);
        break;
      default:
        printf("Invalid choice\n");
    }
  }
}