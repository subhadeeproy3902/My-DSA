#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
} TreeNode;

TreeNode *createNode(int data)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

int height(TreeNode *root)
{
  if (root == NULL)
    return 0;
  return root->height;
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

TreeNode *rightRotate(TreeNode *root)
{
  TreeNode *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  root->height = max(height(root->left), height(root->right)) + 1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
  return newRoot;
}

TreeNode *leftRotate(TreeNode *root)
{
  TreeNode *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  root->height = max(height(root->left), height(root->right)) + 1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
  return newRoot;
}

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL)
    return createNode(data);
  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  else
    return root;
  root->height = max(height(root->left), height(root->right)) + 1;
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

TreeNode *minValueNode(TreeNode *root)
{
  TreeNode *current = root;
  while (current->left != NULL)
    current = current->left;
  return current;
}


TreeNode* balance1(TreeNode *root, int balance)
{
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


TreeNode *delete(TreeNode *root, int data)
{
  if (root == NULL)
    return root;
  if (data < root->data)
    root->left = delete (root->left, data);
  else if (data > root->data)
    root->right = delete (root->right, data);
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
      TreeNode *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = delete (root->right, temp->data);
    }
  }
  if (root == NULL)
    return root;
  root->height = max(height(root->left), height(root->right)) + 1;
  int balance = height(root->left) - height(root->right);
  if (balance > 1 || balance < -1)
    return balance1(root, balance);
  return root;
}

void inorder(TreeNode *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(TreeNode *root)
{
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(TreeNode *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main()
{
  TreeNode *root = NULL;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Inorder\n");
  printf("4. Preorder\n");
  printf("5. Postorder\n");
  int choice, data;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      root = delete (root, data);
      break;
    case 3:
      inorder(root);
      printf("\n");
      break;
    case 4:
      preorder(root);
      printf("\n");
      break;
    case 5:
      postorder(root);
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}