#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int top = -1;
char stack[100][100];

void push(char *x) { strcpy(stack[++top], x); }

char *pop() { return (top == -1) ? NULL : stack[top--]; }

bool isOperand(char x) { return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'); }

char *postfixToInfix(char *exp)
{
  char *e;
  char x1[100], x2[100];
  e = exp;
  while (*e)
  {
    if (isOperand(*e))
    {
      push((char[]){*e, '\0'});
    }
    else
    {
      strcpy(x2, pop());
      strcpy(x1, pop());
      char temp[100];
      sprintf(temp, "(%s%c%s)", x1, *e, x2);
      push(temp);
    }
    e++;
  }
  return strdup(stack[0]);
}

int main()
{
  char *exp = "12345**+*";
  printf("Infix: %s", postfixToInfix(exp));

  return 0;
}
