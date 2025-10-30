// 10. Implement Circular Linked List ADT
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the circular linked list
struct Node* insert(struct Node* last, int value) {
    struct Node* newNode = createNode(value);

    // If list is empty — new node points to itself
    if (last == NULL) {
        newNode->next = newNode;
        return newNode; 
    }

    // Insert node after last and update last
    newNode->next = last->next;  
    last->next = newNode;        
    return newNode;              // New last node
}

// Display circular linked list
void display(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next; // Start from first node

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);   // Stop when back to start

    printf("\n");
}

int main() {
    struct Node* last = NULL;
    int n, value;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input values and insert nodes
    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        last = insert(last, value);
    }

    // Display list
    printf("The circular linked list is: ");
    display(last);

    return 0;
}
