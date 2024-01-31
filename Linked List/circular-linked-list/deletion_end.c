#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtEnd(Node **head, int value)
{
  Node *newNode = createNode(value);

  if (*head == NULL)
  {
    *head = newNode;
    newNode->next = *head;
  }
  else
  {
    Node *last = *head;
    while (last->next != *head)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
  }
}

void deleteAtEnd(Node **head)
{
  if (*head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *last = *head;
  Node *secondLast = NULL;
  while (last->next != *head)
  {
    secondLast = last;
    last = last->next;
  }

  if (secondLast == NULL)
  {
    *head = NULL;
  }
  else
  {
    secondLast->next = *head;
  }
  free(last);
}

void printList(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *current = head;
  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

int main()
{
  Node *head = NULL;
  int choice, data;
  printf("0. Exit\n1. Insert at end\n2. Print List\n3. Delete at end\n");

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
      printList(head);
      break;
    case 3:
      deleteAtEnd(&head);
      break;
    default:
      printf("Invalid choice.\n");
      break;
    }
  }

  return 0;
}
