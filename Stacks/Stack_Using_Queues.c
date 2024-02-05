#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int queue[100];

void push(int item)
{
  if (front == -1)
  {
    front = 0;
  }
  queue[++rear] = item;
}

int pop()
{
  if (front == -1 || front > rear)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return queue[front++];
}

void display()
{
  if (front == -1 || front > rear)
  {
    printf("Stack is empty\n");
    return;
  }
  for (int i = front; i <= rear; i++)
  {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main()
{
  printf("0. Exit\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Display\n");
  int choice, item;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      push(item);
      break;
    case 2:
      printf("Popped item: %d\n", pop());
      break;
    case 3:
      display();
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}