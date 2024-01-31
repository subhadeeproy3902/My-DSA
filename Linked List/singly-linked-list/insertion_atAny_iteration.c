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

Node *insertAtAny(Node *head, int data, int pos)
{
  Node *newNode = createNode(data);
  if (pos == 1)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }
  Node *temp = head;
  for (int i = 0; i < pos - 2; i++)
  {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  return head;
}

void printList(Node *head)
{
  if (head == NULL)
    return;
  printf("%d-> ", head->data);
  printList(head->next);
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n1. Insert at any position\n2. Print List\n");
  int choice, data, pos;
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
      printf("Enter position: ");
      scanf("%d", &pos);
      head = insertAtAny(head, data, pos);
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