#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

Node *insert(Node *head, int data)
{
  if (!head)
    return createNode(data);
  if (head->data > data)
  {
    Node *n = createNode(data);
    n->next = head;
    return n;
  }
  head->next = insert(head->next, data);
  return head;
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%d-> ", head->data);
  display(head->next);
}

int main()
{
  printf("0. Exit\n1. Insert\n2. Display\n");
  Node *head = NULL;
  int ch, data;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      head = insert(head, data);
      break;
    case 2:
      display(head);
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}