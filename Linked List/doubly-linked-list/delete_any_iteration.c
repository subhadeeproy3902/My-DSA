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

Node *insertAtEnd(Node *head, int data)
{
  if (head == NULL)
    return createNode(data);
  head->next = insertAtEnd(head->next, data);
  head->next->prev = head;
  return head;
}

Node *deleteAny(Node *head, int data)
{
  if (head == NULL)
    return NULL;
  if (head->data == data)
  {
    Node *temp = head->next;
    free(head);
    temp->prev = NULL;
    return temp;
  }
  Node *curr = head;
  while (curr->next != NULL)
  {
    if (curr->next->data == data)
    {
      Node *temp = curr->next;
      curr->next = curr->next->next;
      if (curr->next != NULL)
        curr->next->prev = curr;
      free(temp);
      return head;
    }
    curr = curr->next;
  }
  printf("Element not found\n");
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
  printf("1. Insert at end\n");
  printf("2. Print list\n");
  printf("3. Delete from end\n");

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
      head = insertAtEnd(head, data);
      break;
    case 2:
      printList(head);
      break;
    case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      head = deleteAny(head, data);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}