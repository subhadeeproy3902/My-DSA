#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void BToDLL(struct Node* root, struct Node** head) {
    if (root == NULL)
        return;

    BToDLL(root->right, head);

    root->right = *head;
    if (*head != NULL)
        (*head)->left = root;

    *head = root;

    BToDLL(root->left, head);
}

void printList(struct Node* head) {
    printf("Extracted Double Linked list is:\n");
    while (head) {
        printf("%d ", head->data);
        head = head->right;
    }
}

int main() {
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);

    struct Node* head = NULL;
    BToDLL(root, &head);

    printList(head);

    return 0;
}
