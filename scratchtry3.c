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

Node *push(Node *head, int data)
{
  if (!head)
    return createNode(data);
  Node *n = createNode(data);
  n->next = head;
  head = n;
  return head;
}

void pop(Node **head)
{
  if (!(*head))
  {
    printf("Stack underflow\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void peek(Node *head)
{
  if (!head)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("%d\n", head->data);
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%d ", head->data);
  display(head->next);
}

void swap(int *a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(Node* head){
  Node* i = head;
  while(i){
    Node* j = i->next;
    while(j){
      if(i->data > j->data){
        swap(&i->data, &j->data);
      }
      j = j->next;
    }
    i = i->next;
  }
}

int main()
{
  printf("0. Exit\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Peek\n");
  printf("4. Display\n");

  int choice, data;
  Node *head = NULL;

  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
      exit(1);
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      head = push(head, data);
      break;
    case 2:
      pop(&head);
      break;
    case 3:
      peek(head);
      break;
    case 4:
      display(head);
      printf("\n");
      break;
    default:
      printf("Invalic choice...\n");
    }
  }
  return 0;
}