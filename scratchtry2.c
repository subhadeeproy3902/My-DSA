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

Node *insertAtEnd(Node *head, int val)
{
  if (!head)
    return createNode(val);
  head->next = insertAtEnd(head->next, val);
  return head;
}

Node *insertAtStart(Node *head, int val)
{
  Node *n = createNode(val);
  n->next = head;
  head = n;
  return head;
}

void deleteAtEnd(Node **head)
{
  if (!*head)
    return;
  if (!(*head)->next)
  {
    free(*head);
    *head = NULL;
    return;
  }
  deleteAtEnd(&(*head)->next);
}

void deleteAtStart(Node **head)
{
  if (!*head)
    return;
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
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
  Node *head = NULL;
  printf("0. Exit\n1. Insert at end\n2. Insert at start\n3. Delete at end\n4. Delete at start\n5. Display\n");
  int ch, val;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &ch);
    if (ch == 0)
      break;
    switch (ch)
    {
    case 1:
      printf("Enter value: ");
      scanf("%d", &val);
      head = insertAtEnd(head, val);
      break;
    case 2:
      printf("Enter value: ");
      scanf("%d", &val);
      head = insertAtStart(head, val);
      break;
    case 3:
      deleteAtEnd(&head);
      break;
    case 4:
      deleteAtStart(&head);
      break;
    case 5:
      display(head);
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}