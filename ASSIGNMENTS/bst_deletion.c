#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node* findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

int main() {
    struct Node *root = NULL;
    int n, value, deleteValue, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder before deletion: ");
    inorder(root);

    printf("\nEnter node to delete: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("\nInorder after deletion: ");
    inorder(root);

    return 0;
}

/*
Test Case 1 - Zero children:
Input: 50 30 70 20 40 60 80
Delete: 20
Before: 20 30 40 50 60 70 80
After:  30 40 50 60 70 80

Test Case 2 - One child:
Input: 50 30 70 20 40 60
Delete: 70
Before: 20 30 40 50 60 70
After:  20 30 40 50 60

Test Case 3 - Two children:
Input: 50 30 70 20 40 60 80
Delete: 50
Before: 20 30 40 50 60 70 80
After:  20 30 40 60 70 80
*/