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
  if (head == NULL)
    return;
  printf("%d ", head->data);
  printList(head->next);
}

void swap(Node *a, Node *b)
{
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

void sortList(Node **head)
{
  Node *temp = *head;
  while (temp != NULL)
  {
    Node *temp2 = temp->next;
    while (temp2 != NULL)
    {
      if (temp->data > temp2->data)
        swap(temp, temp2);
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");
  printf("3. Sort\n");

  int choice, data;

  while (1)
  {
    printf("Enter your choice: ");
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
      sortList(&head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }

  return 0;
}