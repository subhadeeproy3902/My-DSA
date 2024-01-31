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

void insertAtStart(Node **head, int data)
{
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int main()
{
  Node *head = NULL;
  int choice, data;
  printf("0. Exit\n");
  printf("1. Insert at start\n");
  printf("2. Print list\n");
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
      insertAtStart(&head, data);
      break;
    case 2:
      printList(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}