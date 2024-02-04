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
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->next = n->prev = NULL;
  return n;
}

Node *insertAtEnd(Node *head, int val){
  if (!head)
  {
    Node *n = createNode(val);
    n->next = n->prev = n;
    return n;
  }
  Node *last = head->prev;
  Node *n = createNode(val);
  n->next = head;
  head->prev = n;
  n->prev = last;
  last->next = n;
  return head;
}


Node* insertAtStart(Node *head, int val){
  if (!head)
  {
    Node *n = createNode(val);
    n->next = n->prev = n;
    return n;
  }
  Node *last = head->prev;
  Node *n = createNode(val);
  n->next = head;
  head->prev = n;
  n->prev = last;
  last->next = n;
  return n;
}

void display(Node *head)
{
  if (!head)
    return;
  Node *temp = head;
  do
  {
    printf("%d-> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("%d", temp->data);
  printf("%d", temp->next->data);
  printf("\n");
}

int main(){
  printf("0. Exit\n1. Insert at end\n2. Display\n");
  Node *head = NULL;
  int ch, val;
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
      exit(0);
    case 1:
      printf("Enter value: ");
      scanf("%d", &val);
      head = insertAtEnd(head, val);
      break;
    case 2:
      display(head);
      break;
    default:
      printf("Invalid choice\n");
    }
  } 
  return 0;
}