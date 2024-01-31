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

void deleteAny(Node **head, int data)
{
  if (*head == NULL)
    return;
  if ((*head)->data == data)
  {
    Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
    return;
  }
  deleteAny(&(*head)->next, data);
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
      deleteAny(&head, data);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}