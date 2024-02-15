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

void deleteAtN(Node** head, int n){
  if(*head == NULL) return;
  Node* temp = *head;
  if(n == 1){
    *head = temp->next;
    free(temp);
    return;
  }
  for(int i=0; temp!=NULL && i<n-2; i++){
    temp = temp->next;
  }
  if(temp == NULL || temp->next == NULL) return;
  Node* next = temp->next->next;
  free(temp->next);
  temp->next = next;
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
  printf("0. Exit\n1. Insert at end\n2. Print List\n3. Delete at N\n");
  int choice, data, n;
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
      printf("Enter position: ");
      scanf("%d", &n);
      deleteAtN(&head, n);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}