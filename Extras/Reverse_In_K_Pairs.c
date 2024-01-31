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
  if (head == NULL)
    return createNode(data);
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

Node *reverseInKPairs(Node *head, int k)
{
  Node *prev = NULL;
  Node *curr = head;
  int x = 0;
  Node *forward = NULL;

  Node *count = head;
  int y = 0;
  while (count != NULL)
  {
    count = count->next;
    y++;
  }
  if (y < k)
    return head;

  while (curr != NULL && x < k)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    x++;
  }
  if (forward != NULL)
  {
    head->next = reverseInKPairs(forward, k);
  }
  return prev;
}

int main()
{
  Node *head = NULL;
  int choice, data, k;
  printf("0. Exit\n1. Insert at end\n2. Print List\n3. Reverse in K pairs\n");
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
      printf("Enter K: ");
      scanf("%d", &k);
      head = reverseInKPairs(head, k);
      break;
    default:
      printf("Invalid choice.\n");
    }
  }
  return 0;
}