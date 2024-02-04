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

Node *insertAtAny(Node *head, int data, int pos)
{
  if (!head)
    return createNode(data);
  if (pos == 1)
  {
    Node *n = createNode(data);
    n->next = head;
    head = n;
    return head;
  }

  head->next = insertAtAny(head->next, data, pos - 1);
  return head;
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%d-> ", head->data);
  display(head->next);
}

void delete(Node **head, int data)
{
  if (!head)
    return;
  if (!(*head)->next)
  {
    if ((*head)->data == data)
    {
      free(*head);
      *head = NULL;
      return;
    }
    return;
  }
  if ((*head)->data == data)
  {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }
  delete (&((*head)->next), data);
}

void reverse(Node **head)
{
  Node *curr = *head;
  Node *prev = NULL;
  Node *forward = NULL;
  while (curr)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  *head = prev;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(Node **head)
{
  Node *curr = *head;
  while (curr)
  {
    Node *temp = curr->next;
    while (temp)
    {
      if (curr->data > temp->data)
      {
        swap(&curr->data, &temp->data);
      }
      temp = temp->next;
    }
    curr = curr->next;
  }
}

int main()
{
  printf("0. Exit\n");
  printf("1. Insert At End\n");
  printf("2. Insert At Start\n");
  printf("3. Insert At Any Position\n");
  printf("4. Display List\n");
  printf("5. Delete\n");
  printf("6. Reverse\n");
  printf("7. Sort\n");

  int choice, data, pos;
  Node *head = NULL;

  while (1)
  {
    printf("Enter a choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      exit(1);
    case 1:
      printf("Enter a number to be inserted: ");
      scanf("%d", &data);
      head = insertAtEnd(head, data);
      break;
    case 2:
      printf("Enter a number to be inserted: ");
      scanf("%d", &data);
      head = insertAtStart(head, data);
      break;
    case 3:
      printf("Enter a number to be inserted: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &pos);
      head = insertAtAny(head, data, pos);
      break;
    case 4:
      display(head);
      printf("\n");
      break;
    case 5:
      printf("Enter number to be deleted: ");
      scanf("%d", &data);
      delete (&head, data);
      break;
    case 6:
      reverse(&head);
      break;
    case 7:
      sort(&head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}