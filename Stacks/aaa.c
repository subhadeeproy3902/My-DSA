#include <stdio.h>

int main()
{
  char postfix[100];
  printf("Enter postfix expression: ");
  scanf("%s", postfix);
  int stack[100], top = -1;
  for (int i = 0; postfix[i]; i++) {
    if (postfix[i] >= '0' && postfix[i] <= '9') stack[++top] = postfix[i] - '0';
    else {
      int operand2 = stack[top--];
      int operand1 = stack[top--];
      switch (postfix[i]) {
      case '+':
        stack[++top] = operand1 + operand2;
        break;
      case '-':
        stack[++top] = operand1 - operand2;
        break;
      case '*':
        stack[++top] = operand1 * operand2;
        break;
      case '/':
        stack[++top] = operand1 / operand2;
        break;
      }
    }
  }
  printf("Result: %d\n", stack[0]);
  return 0;
}
