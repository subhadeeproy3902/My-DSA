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

Node *insertAtMiddleRecursive(Node* slow, Node* fast, Node* prev, int data){
  if (fast->next == NULL || fast->next->next == NULL){
    Node* newNode = createNode(data);
    newNode->next = slow->next;
    slow->next = newNode;
    return prev;
  }
  return insertAtMiddleRecursive(slow->next, fast->next->next, slow, data);
}

Node* insertAtMiddle(Node* head, int data) {
  if (head == NULL) return createNode(data);
  return insertAtMiddleRecursive(head, head, head, data);
}


void printList(Node *head)
{
  if (head == NULL) return;
  printf("%d-> ", head->data);
  printList(head->next);
}

int main()
{
  Node *head = NULL;
  printf("0. Exit\n1. Insert at end\n2.Insert At Middle\n3. Print List\n");
  int choice, data;
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
      printf("Enter data: ");
      scanf("%d", &data);
      head = insertAtMiddle(head, data);
      break;
    case 3:
      printList(head);
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}