#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int expo, coeff;
  struct Node *next;
} Node;

Node *createNode(int expo, int coeff)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->expo = expo;
  n->coeff = coeff;
  n->next = NULL;
  return n;
}

Node *insert(Node *head, int expo, int coeff)
{
  if (!head)
    return createNode(expo, coeff);
  head->next = insert(head->next, expo, coeff);
  return head;
}

void display(Node *head)
{
  if (!head)
    return;
  printf("%dx^%d ", head->coeff, head->expo);
  if (head->next)
    printf("+ ");
  display(head->next);
}

Node *add(Node *head1, Node *head2)
{
  Node *head3 = NULL;
  while (head1 && head2)
  {
    if (head1->expo > head2->expo)
    {
      head3 = insert(head3, head1->expo, head1->coeff);
      head1 = head1->next;
    }
    else if (head1->expo < head2->expo)
    {
      head3 = insert(head3, head2->expo, head2->coeff);
      head2 = head2->next;
    }
    else
    {
      head3 = insert(head3, head1->expo, head1->coeff + head2->coeff);
      head1 = head1->next;
      head2 = head2->next;
    }
  }

  while (head1)
  {
    head3 = insert(head3, head1->expo, head1->coeff);
    head1 = head1->next;
  }
  while (head2)
  {
    head3 = insert(head3, head2->expo, head2->coeff);
    head2 = head2->next;
  }
  return head3;
}

Node *multiply(Node *head1, Node *head2)
{
  Node *head3 = NULL;
  Node *temp = head1;
  while (temp)
  {
    Node *temp2 = head2;
    while (temp2)
    {
      int coeff = temp->coeff * temp2->coeff;
      int expo = temp->expo + temp2->expo;
      head3 = insert(head3, expo, coeff);
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
  return head3;
}

int main()
{
  Node *head1 = NULL;
  Node *head2 = NULL;

  int n;
  printf("Enter the highest degree of Polynomial 1: ");
  scanf("%d", &n);

  for (int i = n; i >= 0; i--)
  {
    int coeff;
    printf("Enter coefficient of x^%d: ", i);
    scanf("%d", &coeff);
    head1 = insert(head1, i, coeff);
  }

  printf("Polynomial 1: ");
  display(head1);
  printf("\n");

  int m;
  printf("Enter the highest degree of Polynomial 2: ");
  scanf("%d", &m);

  for (int i = m; i >= 0; i--)
  {
    int coeff;
    printf("Enter coefficient of x^%d: ", i);
    scanf("%d", &coeff);
    head2 = insert(head2, i, coeff);
  }

  printf("Polynomial 2: ");
  display(head2);
  printf("\n");

  Node *head3 = add(head1, head2);
  printf("After additon: ");
  display(head3);

  Node *head4 = multiply(head1, head2);
  printf("After Multiplication: ");
  display(head4);

  return 0;
}