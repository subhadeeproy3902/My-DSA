#include <stdio.h>
#include <stdlib.h>

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
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode *constructTree(char postfix[])
{
  TreeNode *t, *t1, *t2;
  for (int i = 0; postfix[i] != '\0'; i++)
  {
    if (!isOperator(postfix[i]))
    {
      push(createNode(postfix[i]));
    }
    else
    {
      t = createNode(postfix[i]);
      t1 = pop();
      t2 = pop();
      t->right = t1;
      t->left = t2;
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

int main()
{
  char postfix[] = "1234***";
  TreeNode *r = constructTree(postfix);
  printf("Infix expression is: ");
  inorder(r);
  printf("\n");
  return 0;
}
