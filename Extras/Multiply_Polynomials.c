#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int coeff;
  int exp;
  struct node *next;
} Node;

Node *createNode(int coeff, int exp)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coeff = coeff;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

Node *insertPolynomial(Node *head, int coeff, int exp)
{
  Node *newNode = createNode(coeff, exp);
  if (!head)
    return newNode;
  if (!head->next)
    head->next = newNode;
  else
    insertPolynomial(head->next, coeff, exp);
  return head;
}

void printPolynomial(Node *head)
{
  if (!head)
    return;
  printf("%dx^%d", head->coeff, head->exp);
  if (head->next)
    printf(" + ");
  printPolynomial(head->next);
}

Node *multiplyPolynomials(Node *head1, Node *head2)
{
  Node *head3 = NULL;
  Node *temp1 = head1;
  while (temp1)
  {
    Node *temp2 = head2;
    while (temp2)
    {
      int coeff = temp1->coeff * temp2->coeff;
      int exp = temp1->exp + temp2->exp;
      head3 = insertPolynomial(head3, coeff, exp);
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
  return head3;
}

int main()
{
  Node *head1 = NULL;
  int highestDegree1;
  printf("Enter the highest degree of the polynomial 1: ");
  scanf("%d", &highestDegree1);
  for (int i = highestDegree1; i >= 0; i--)
  {
    int coeff;
    printf("Enter the coefficient of x^%d: ", i);
    scanf("%d", &coeff);
    head1 = insertPolynomial(head1, coeff, i);
  }
  printPolynomial(head1);

  printf("\n");

  Node *head2 = NULL;
  int highestDegree2;
  printf("Enter the highest degree of the polynomial 2: ");
  scanf("%d", &highestDegree2);
  for (int i = highestDegree2; i >= 0; i--)
  {
    int coeff;
    printf("Enter the coefficient of x^%d: ", i);
    scanf("%d", &coeff);
    head2 = insertPolynomial(head2, coeff, i);
  }
  printPolynomial(head2);

  printf("\n");

  printf("The sum of the two polynomials is: ");
  Node *head3 = multiplyPolynomials(head1, head2);
  printPolynomial(head3);
  return 0;
}