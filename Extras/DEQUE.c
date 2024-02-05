#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

Node *enqueueStart(Node *head, int data)
{
  if (!head)
    return createNode(data);
  Node *node = createNode(data);
  node->next = head;
  head = node;
  return head;
}

Node *enqueueEnd(Node *head, int data)
{
  if (!head)
    return createNode(data);
  head->next = enqueueEnd(head->next, data);
  return head;
}

void deleteStart(Node **head)
{
  if (!*head)
    return;
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteEnd(Node **head)
{
  if (!*head)
    return;
  if (!(*head)->next)
  {
    free(*head);
    *head = NULL;
    return;
  }
  deleteEnd(&((*head)->next));
}

void peek(Node *head)
{
  if (!head)
    return;
  printf("%d\n", head->data);
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
  Node *head = NULL;
  int choice, data;

  printf("0. Exit\n");
  printf("1. Enqueue At Fornt\n");
  printf("2. Enqueue At End\n");
  printf("3. Dequeue At Front\n");
  printf("4. Dequeue At End\n");
  printf("5. Peek\n");
  printf("6. Display\n");

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
      head = enqueueStart(head, data);
      break;
    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      head = enqueueEnd(head, data);
      break;
    case 3:
      deleteStart(&head);
      break;
    case 4:
      deleteEnd(&head);
      break;
    case 5:
      peek(head);
      break;
    case 6:
      display(head);
      printf("\n");
      break;
    default:
      printf("Invlaid Choice,,,\n");
    }
  }
  return 0;
}