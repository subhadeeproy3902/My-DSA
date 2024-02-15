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


void printList(Node *head)
{
  if (head == NULL)
    return;
  printf("%d-> ", head->data);
  printList(head->next);
}

Node* deleteNode(Node* head, Node* node)
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return head;
  }
  if (head == node)
  {
    head = head->next;
    free(node);
    return head;
  }
  Node* temp = head;
  while (temp->next != NULL)
  {
    if (temp->next == node)
    {
      temp->next = temp->next->next;
      free(node);
      return head;
    }
    temp = temp->next;
  }
  printf("Node not found\n");
  return head;
}

int main(){
  Node *head = NULL;
  Node* node = NULL;
  printf("0. Exit\n1. Insert at end\n2. Print List\n3. Delete Node\n");
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
        printList(head);
        printf("\n");
        break;
      case 3:
        printf("Enter node: ");
        scanf("%d", &data);
        node = createNode(data);
        head = deleteNode(head, node);
        break;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}