#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
char stack[100];

void push(char x)
{
  stack[++top] = x;
}

char pop()
{
  if (top == -1)
    return -1;
  else
    return stack[top--];
}

int priority(char x)
{
  if (x == '(')
    return 0;
  if (x == '+' || x == '-')
    return 1;
  if (x == '*' || x == '/')
    return 2;
  return 0;
}

void infixToPostfix(char *exp)
{
  char *e, x;
  e = exp;
  while (*e != '\0')
  {
    if (isalnum(*e))
      printf("%c", *e);
    else if (*e == '(')
      push(*e);
    else if (*e == ')')
    {
      while ((x = pop()) != '(')
        printf("%c", x);
    }
    else
    {
      while (priority(stack[top]) >= priority(*e))
        printf("%c", pop());
      push(*e);
    }
    e++;
  }
  while (top != -1)
  {
    printf("%c", pop());
  }
}

int main()
{
  char exp[100];
  printf("Enter the expression: ");
  scanf("%s", exp);
  printf("Postfix Expression: ");
  infixToPostfix(exp);
  return 0;
}
