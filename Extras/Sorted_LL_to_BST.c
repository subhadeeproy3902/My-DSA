#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

Node *insert(Node *head, int data)
{
  if (!head)
    return createNode(data);
  head->next = insert(head->next, data);
  return head;
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%d-> ", head->data);
  display(head->next);
}

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createNode2(int data)
{
  TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int height(TreeNode *root)
{
  if (!root)
    return 0;
  int leftheight = height(root->left);
  int rightheight = height(root->right);
  return 1 + (leftheight > rightheight ? leftheight : rightheight);
}

TreeNode *rightRotate(TreeNode *root)
{
  TreeNode *newroot = root->left;
  root->left = newroot->right;
  newroot->right = root;
  return newroot;
}

TreeNode *leftRotate(TreeNode *root)
{
  TreeNode *newroot = root->right;
  root->right = newroot->left;
  newroot->left = root;
  return newroot;
}

TreeNode *insertinBST(TreeNode *root, int data)
{
  if (!root)
    return createNode2(data);
  if (data < root->data)
    root->left = insertinBST(root->left, data);
  else if (data > root->data)
    root->right = insertinBST(root->right, data);
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

void preorder(TreeNode *root)
{
  if (!root)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}



int main()
{
  Node *head = NULL;
  printf("Enter the number of nodes: ");
  int n;
  scanf("%d", &n);
  printf("Enter the nodes: ");
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x);
    head = insert(head, x);
  }

  printf("The Linked list is: ");
  display(head);
  printf("\n");

  Node* curr = head;
  TreeNode* root = NULL;

  while (curr){
    root = insertinBST(root, curr->data);
    curr = curr->next;
  }

  printf("The BST is: ");
  preorder(root);

  return 0;
}