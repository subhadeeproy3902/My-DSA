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

Node *insertAtEnd(Node *head, int data)
{
  if (head == NULL) return createNode(data);
  head->next = insertAtEnd(head->next, data);
  return head;
}

void printList(Node *head)
{
  if (head == NULL) return;
  printf("%d-> ", head->data);
  printList(head->next);
}

void findMaxMin(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  int max = head->data, min = head->data;
  while (head != NULL)
  {
    if (head->data > max)
      max = head->data;
    if (head->data < min)
      min = head->data;
    head = head->next;
  }
  printf("Max: %d, Min: %d\n", max, min);
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n1. Insert at end\n2. Print List\n3. Find Largest and Smallest\n");
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
      head = insertAtEnd(head, data);
      break;
    case 2:
      printList(head);
      printf("\n");
      break;
    case 3:
      findMaxMin(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}