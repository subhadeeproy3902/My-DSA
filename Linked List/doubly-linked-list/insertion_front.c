#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

Node *insertionAtStart(Node *head, int data)
{
  Node *newNode = createNode(data);
  if (head == NULL)
    return newNode;
  newNode->next = head;
  head->prev = newNode;
  return newNode;
}

void printList(Node *head)
{
  if (head == NULL)
    return;
  if (head->prev == NULL)
    printf("NULL <- ");
  printf("%d <-> ", head->data);
  if (head->next == NULL)
    printf("NULL\n");
  printList(head->next);
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n");
  printf("1. Insert at start\n");
  printf("2. Print list\n");

  int choice, data;

  while (1)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      head = insertionAtStart(head, data);
      break;
    case 2:
      printList(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}