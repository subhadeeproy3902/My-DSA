#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data, priority;
  struct Node *next;
} Node;

Node *createNode(int data, int priority)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->priority = priority;
  n->next = NULL;
  return n;
}

Node *insert(Node *head, int data, int priority)
{
  if (!head || head->priority > priority)
  {
    Node *n = createNode(data, priority);
    n->next = head;
    return n;
  }
  head->next = insert(head->next, data, priority);
  return head;
}

void delete(Node **head)
{
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void peek(Node *head)
{
  if (!head)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Data: %d  Priority: %d", head->data, head->priority);
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%d ", head->data);
  display(head->next);
}

int main()
{
  int choice, data, priority;
  printf("0. Exit\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  Node *head = NULL;

  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      exit(1);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter priority: ");
      scanf("%d", &priority);
      head = insert(head, data, priority);
      break;
    case 2:
      delete (&head);
      break;
    case 3:
      peek(head);
      break;
    case 4:
      display(head);
      break;
    default:
      printf("Invalid choice...\n");
    }
  }
  return 0;
}