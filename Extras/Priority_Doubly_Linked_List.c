#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *prev;
  struct node *next;
  int priority;
} Node;

Node *createNode(int data, int priority)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->priority = priority;
  return newNode;
}

Node *insert(Node *head, int data, int priority)
{
  Node *newNode = createNode(data, priority);

  if (head == NULL || head->priority > priority)
  {
    newNode->next = head;
    if (head != NULL)
      head->prev = newNode;
    return newNode;
  }

  head->next = insert(head->next, data, priority);
  head->next->prev = head;

  return head;
}

void printList(Node *head)
{
  if (head == NULL)
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

  int choice, data, priority;

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
      printf("Enter priority: ");
      scanf("%d", &priority);
      head = insert(head, data, priority);
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