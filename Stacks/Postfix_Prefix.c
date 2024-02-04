#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;
char stack[100][100];

void push(char *x)
{
  strcpy(stack[++top], x);
}

char *pop()
{
  if (top == -1)
    return NULL;
  else
    return stack[top--];
}

void postfixToPrefix(char *exp)
{
  char *e;
  char x[100]; // Change x to an array to hold strings
  e = exp;
  while (*e != '\0')
  {
    if (isalnum(*e))
    {
      x[0] = *e;
      x[1] = '\0';
      push(x);
    }
    else
    {
      char *op1 = pop();
      char *op2 = pop();
      x[0] = *e;
      x[1] = '\0';
      strcat(x, op2);
      strcat(x, op1);
      push(x);
    }
    e++;
  }
  printf("Prefix expression: %s\n", stack[0]);
}

int main()
{
  char exp[100];
  printf("Enter the postfix expression: ");
  scanf("%s", exp);
  postfixToPrefix(exp);
  return 0;
}
