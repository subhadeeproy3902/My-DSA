#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void insertAtEnd(Node **head, int data)
{
  Node *node = createNode(data);
  if (!*head)
  {
    *head = node;
    node->next = *head;
  }
  else
  {
    Node *curr = *head;
    while (curr->next != *head)
    {
      curr = curr->next;
    }
    curr->next = node;
    node->next = *head;
  }
}

void insertAtStart(Node **head, int data)
{
  Node *node = createNode(data);
  if (!*head)
  {
    *head = node;
    node->next = *head;
  }
  else
  {
    Node *curr = *head;
    while (curr->next != *head)
    {
      curr = curr->next;
    }
    curr->next = node;
    node->next = *head;
    *head = node;
  }
}

void display(Node *head)
{
  Node *curr = head;
  do
  {
    printf("%d ", curr->data);
    curr = curr->next;
  } while (curr != head);
  printf("\n");
}

void deleteAtStart(Node **head)
{
  if (!*head)
    return;
  Node *curr = *head;
  while (curr->next != *head)
  {
    curr = curr->next;
  }
  Node *temp = *head;
  curr->next = temp->next;
  *head = temp->next;
  free(temp);
}

void deleteAtEnd(Node **head)
{
  if (!*head)
    return;
  Node *curr = *head;
  while (curr->next->next != *head)
  {
    curr = curr->next;
  }
  Node *temp = curr->next;
  curr->next = *head;
  free(temp);
}

int main()
{
  printf("Queue using Stacks\n");
  Node *head = NULL;
  printf("0. Exit\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  int choice, data;

  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtEnd(&head, data);
      break;
    case 2:
      deleteAtStart(&head);
      break;
    case 3:
      printf("Peek: %d\n", head->data);
      break;
    case 4:
      display(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}