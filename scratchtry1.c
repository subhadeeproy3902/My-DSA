#include <stdio.h>
#include <stdlib.h>

int top = -1;
char stack[100];

int precedence(char ch)
{
  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '^')
    return 3;
  return -1;
}

void push(char ch)
{
  stack[++top] = ch;
}

char pop()
{
  if (top == -1)
    return -1;
  return stack[top--];
}

void infixToPostfix(char *exp)
{
  char *e;
  char x;
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
      while (precedence(stack[top]) >= precedence(*e))
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
