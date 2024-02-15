#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
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
    if (head == NULL)
        return createNode(data);
    head->next = insertAtEnd(head->next, data);
    return head;
}

Node *insertAfter(Node *head, int item, int data)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            Node *newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    printf("Item not found\n");
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("0. Exit\n");
    printf("1. Insert After\n");
    printf("2. Print List\n");
    printf("3. Insert At End\n");

    Node *head = NULL;
    int choice, data, item;

    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertAfter(head, item, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}