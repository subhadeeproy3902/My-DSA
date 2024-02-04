#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isOperator(char c)
{
  return (!(isalpha(c) || isdigit(c)));
}

int getPriority(char C)
{
  if (C == '-' || C == '+')
    return 1;
  else if (C == '*' || C == '/')
    return 2;
  else if (C == '^')
    return 3;
  return 0;
}

char *infixToPostfix(char *infix)
{
  int l = strlen(infix);
  char *output = (char *)malloc((l + 1) * sizeof(char));
  strcpy(output, "");

  strcat(output, "(");
  strcat(output, infix);
  strcat(output, ")");

  int i, j = 0;
  char char_stack[l + 2];
  int top = -1;

  for (i = 0; i <= l; i++)
  {
    if (isalpha(output[i]) || isdigit(output[i]))
      output[j++] = output[i];

    else if (output[i] == '(')
      char_stack[++top] = '(';

    else if (output[i] == ')')
    {
      while (char_stack[top] != '(')
      {
        output[j++] = char_stack[top--];
      }
      top--; // Remove '(' from the stack
    }

    else
    {
      if (isOperator(char_stack[top]))
      {
        if (output[i] == '^')
        {
          while (getPriority(output[i]) <= getPriority(char_stack[top]))
          {
            output[j++] = char_stack[top--];
          }
        }
        else
        {
          while (getPriority(output[i]) < getPriority(char_stack[top]))
          {
            output[j++] = char_stack[top--];
          }
        }
        char_stack[++top] = output[i];
      }
    }
  }

  while (top != -1)
  {
    output[j++] = char_stack[top--];
  }

  output[j] = '\0';
  return output;
}

char *infixToPrefix(char *infix)
{
  int l = strlen(infix);
  strrev(infix);

  for (int i = 0; i < l; i++)
  {
    if (infix[i] == '(')
    {
      infix[i] = ')';
    }
    else if (infix[i] == ')')
    {
      infix[i] = '(';
    }
  }

  char *prefix = infixToPostfix(infix);
  strrev(prefix);

  return prefix;
}

int main()
{
  char s[] = "x+y*z/w+u";
  printf("%s\n", infixToPrefix(s));
  return 0;
}
