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

Node *insert(Node *head, int data)
{
  if (!head)
    return createNode(data);
  if (head->data > data)
  {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
  }
  head->next = insert(head->next, data);
  return head;
}

void printList(Node *head)
{
  if (!head)
    return;
  printf("%d ", head->data);
  printList(head->next);
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");
  int choice, data;

  while (1)
  {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      return 0;
    case 1:
      printf("Enter the data: ");
      scanf("%d", &data);
      head = insert(head, data);
      break;
    case 2:
      printList(head);
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}