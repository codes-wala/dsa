// 3. Implement Binary Search Tree ADT using Linked List
#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node in the BST
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
// Function to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Function to insert a node in the BST
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Function for in-order traversal (left, root, right)
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
    struct Node *root = NULL;
    int n, value;
    // Taking the number of nodes as input
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // Taking node values as input
    // printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    // Performing in-order traversal of the BST
    // printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}