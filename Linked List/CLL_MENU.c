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
  if (!head)
    return;
  Node *curr = head;
  do
  {
    printf("%d ", curr->data);
    curr = curr->next;
  } while (curr != head);
  printf("\n");
}

void deleteNode(Node **head, int data)
{
  if (!*head)
    return;
  
  Node *temp = *head, *prev = NULL;

  // Find the node to be deleted
  while (temp->data != data && temp->next != *head)
  {
    prev = temp;
    temp = temp->next;
  }

  // If node not found
  if (temp->data != data)
  {
    printf("Node with data %d not found.\n", data);
    return;
  }

  // If the node to be deleted is the only node in the list
  if (temp->next == *head && temp == *head)
  {
    free(temp);
    *head = NULL;
  }
  else if (temp == *head) // If the node is the first node
  {
    prev = *head;
    while (prev->next != *head)
      prev = prev->next;

    prev->next = temp->next;
    *head = temp->next;
    free(temp);
  }
  else
  {
    prev->next = temp->next;
    free(temp);
  }
}

int main()
{
  printf("0. Exit\n");
  printf("1. Insert At End\n");
  printf("2. Insert At Start\n");
  printf("3. Delete\n");
  printf("4. Display\n");

  Node *head = NULL;

  int choice, data;

  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      exit(1);
    case 1:
      printf("Enter data to be inserted: ");
      scanf("%d", &data);
      insertAtEnd(&head, data);
      break;
    case 2:
      printf("Enter data to be inserted: ");
      scanf("%d", &data);
      insertAtStart(&head, data);
      break;
    case 3:
      printf("Enter data to be deleted: ");
      scanf("%d", &data);
      deleteNode(&head, data);
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
