#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtEnd(Node **head, int value)
{
  Node *newNode = createNode(value);

  if (*head == NULL)
  {
    *head = newNode;
    newNode->next = *head;
  }
  else
  {
    Node *last = *head;
    while (last->next != *head)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
  }
}

void printList(Node *head)
{
  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  Node *current = head;
  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

Node *josephus(Node *head, int k)
{
  if (head->next == head)
    return head;
  Node *curr = head;
  Node *prev = NULL;
  while (curr->next != head)
    curr = curr->next;

  while (curr->next != curr)
  {
    for (int i = 1; i < k; i++)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    curr = prev->next;
  }
  if (!curr) printf("NULL\n");
  return curr;
}

int main()
{
  Node *head = NULL;
  int n, k;
  printf("Enter the number of people: ");
  scanf("%d", &n);
  printf("Enter the value of k: ");
  scanf("%d", &k);
  for (int i = 1; i <= n; i++)
  {
    insertAtEnd(&head, i);
  }
  printList(head);
  head = josephus(head, k);
  if (head == NULL)
    printf("No one left\n");
  else
  printf("The person left at the end is index: %d\n", head->data);
  return 0;
}
