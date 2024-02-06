#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
  char data;
  struct Node *left, *right;
} TreeNode;

TreeNode *createNode(char data)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

TreeNode *stack[100];
int top = -1;

void push(TreeNode *item)
{
  stack[++top] = item;
}

TreeNode *pop()
{
  return stack[top--];
}

int isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

TreeNode *constructTree(char prefix[])
{
  TreeNode *t, *t1, *t2;
  int length = strlen(prefix);
  
  for (int i = length - 1; i >= 0; i--)
  {
    if (!isOperator(prefix[i]))
    {
      push(createNode(prefix[i]));
    }
    else
    {
      t = createNode(prefix[i]);
      t1 = pop();
      t2 = pop();
      t->left = t1;
      t->right = t2;
      push(t);
    }
  }
  return pop();
}

void inorder(TreeNode *t)
{
  if (t != NULL)
  {
    inorder(t->left);
    printf("%c ", t->data);
    inorder(t->right);
  }
}

void preorder(TreeNode *root)
{
  if (root)
  {
    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(TreeNode *root)
{
  if (root)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
  }
}

int main()
{
  char prefix[100];
  printf("Enter the prefix expression: ");
  scanf("%s", prefix);

  TreeNode *root = constructTree(prefix);
  printf("The Infix exp is: ");
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
  return 0;
}


