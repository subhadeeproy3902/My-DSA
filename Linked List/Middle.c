#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(){
  Node *temp = (Node*)malloc(sizeof(Node));
  return temp;
}

void insert(int val){
  Node *temp = createNode();
  temp->data = val;
  temp->next = NULL;
  if (head == NULL) head = temp;
  else {
    Node* ref = head;
    while(ref->next != NULL) ref = ref->next;
    ref->next = temp;
  }
}

void print(){
  Node *temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int middle(Node *node){
  Node* curr1 = node;
  Node* curr2 = node;
  while(curr2 != NULL && curr2->next != NULL){
    curr1 = curr1->next;
    curr2 = curr2->next->next;
  }
  return curr1->data;
}

int main(){
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");
  printf("3. Middle\n");
  int choice, val;
  while(1){
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 0:
        exit(0);
      case 1:
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
        break;
      case 2:
        print();
        break;
      case 3:
        printf("Middle: %d", middle(head));
        break;
      default:
        printf("Invalid choice!");
    }
  }
  return 0;
}