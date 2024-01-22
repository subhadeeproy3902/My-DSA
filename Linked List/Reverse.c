#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

Node* createNode(){
  Node *temp = (Node*)malloc(sizeof(Node));
  return temp;
}

Node *head = NULL;

void insert(int val){
  Node *temp = createNode();
  temp->data = val;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
    return;
  }
  Node *temp2 = head;
  while(temp2->next != NULL){
    temp2 = temp2->next;
  }
  temp2->next = temp;
}

void print(){
  Node *temp = head;
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void reverse(){
  Node *current = head;
  Node *prev = NULL;
  Node *next = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

int main(){
  printf("0. Exit\n");
  printf("1. Insert\n");
  printf("2. Print\n");
  printf("3. Reverse\n");
  int choice, val;
  while(1){
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 0:
        exit(0);
      case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        insert(val);
        break;
      case 2:
        print();
        break;
      case 3:
        reverse();
        break;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}