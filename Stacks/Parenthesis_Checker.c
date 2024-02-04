#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
  char stack[100];
  int top = -1;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack[++top] = s[i];
    else if (top == -1 || (s[i] == '}' && stack[top] != '{') || (s[i] == ']' && stack[top] != '[') || (s[i] == ')' && stack[top] != '(')) return false;
    else top--;
  }
  return top == -1;
}

int main()
{
  char s[100];
  printf("Enter the string: ");
  scanf("%s", s);
  if (isValid(s)) printf("Valid");
  else printf("Invalid");
  return 0;
}
