#include <stdio.h>

int top1 = -1, top2 = -1;
int stack1[100], stack2[100];

void enqueue(int item)
{
  stack1[++top1] = item;
}

int dequeue()
{
  if (top1 == -1 && top2 == -1)
  {
    printf("Queue is empty\n");
    return -1;
  }

  if (top2 == -1)
  {
    while (top1 != -1)
    {
      stack2[++top2] = stack1[top1--];
    }
  }

  return stack2[top2--];
}

void display()
{
  if (top1 == -1 && top2 == -1)
  {
    printf("Queue is empty\n");
    return;
  }

  if (top2 == -1)
  {
    while (top1 != -1)
    {
      stack2[++top2] = stack1[top1--];
    }
  }
  for (int i = top2; i >= 0; i--)
  {
    printf("%d ", stack2[i]);
  }
  printf("\n");
  while (top2 != -1)
  {
    stack1[++top1] = stack2[top2--];
  }
}

int main()
{
  printf("0. Exit\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Display\n");

  int choice, item;

  while (1)
  {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      return 0;
    case 1:
      printf("Enter the item: ");
      scanf("%d", &item);
      enqueue(item);
      break;
    case 2:
      item = dequeue();
      if (item != -1)
        printf("Dequeued item: %d\n", item);
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
