// Recursion OP :)
// Ok so in here priority ordered insertion but deleteStart for pop() so O(1)


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
  int priority;
} Node;

Node *createNode(int data, int priority)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  newNode->priority = priority;
  return newNode;
}

Node *push(Node *head, int data, int priority)
{
  Node *newNode = createNode(data, priority);
  if (head == NULL || head->priority > priority)
  {
    newNode->next = head;
    return newNode;
  }
  head->next = push(head->next, data, priority);
  return head;
}

void pop(Node **head)
{
  if (*head == NULL)
    return;
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void top(Node *head)
{
  if (head == NULL)
    return;
  printf("%d\n", head->data);
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
  printf("1. push\n");
  printf("2. Print\n");
  printf("3. Delete\n");
  printf("4. Top?\n");

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
      head = push(head, data, priority);
      break;
    case 2:
      printList(head);
      printf("\n");
      break;
    case 3:
      pop(&head);
      break;
    case 4:
      top(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}