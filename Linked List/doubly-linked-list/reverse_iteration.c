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
  if (!head)
    return createNode(data);
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = createNode(data);
  temp->next->prev = temp;
  return head;
}

void printList(Node *head)
{
  if (head == NULL)
    return;
  if (head->prev == NULL)
    printf("NULL <- ");
  printf("%d <-> ", head->data);
  if (head->next == NULL)
    printf("NULL\n");
  printList(head->next);
}

Node* reverse(Node *head){
  Node *temp = NULL;
  Node *current = head;
  while(current){
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if(temp)
    head = temp->prev;
  return head;
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n");
  printf("1. Insert at end\n");
  printf("2. Print list\n");
  printf("3. Reverse list\n");

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
      head = reverse(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}