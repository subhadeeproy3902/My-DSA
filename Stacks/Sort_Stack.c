#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
int stack[100];

void push(int item)
{
  stack[++top] = item;
}

int pop()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[top--];
}

int peek()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[top];
}

void display()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return;
  }
  for (int i = top; i >= 0; i--)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

void sort()
{
  int tempStack[100];
  int tempTop = -1;
  while (top != -1)
  {
    int temp = pop();
    while (tempTop != -1 && tempStack[tempTop] > temp)
    {
      push(tempStack[tempTop--]);
    }
    tempStack[++tempTop] = temp;
  }
  while (tempTop != -1)
  {
    push(tempStack[tempTop--]);
  }
}

int main()
{
  printf("0. Exit\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  printf("5. Sort\n");
  while (1)
  {
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter item: ");
      int item;
      scanf("%d", &item);
      push(item);
      break;
    case 2:
      printf("Popped: %d\n", pop());
      break;
    case 3:
      printf("Peek: %d\n", peek());
      break;
    case 4:
      display();
      break;
    case 5:
      sort();
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
