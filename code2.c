// 2. Implement Singly Linked List ADT. Insert at end, Delete at beginning
#include<stdio.h>
#include <stdlib.h>
// Node structure representing each element in the list
struct Node {
    int data; // Data field
    struct Node *next; // Pointer to the next node
};
// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node)); // Allocate memory
    newNode->data = data; // Assign data
    newNode->next = NULL; // Initialize next as NULL
    return newNode; // Return the new node
}
// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data); // Create a new node
    if (*head == NULL) { // If the list is empty
        *head = newNode; // Make the new node the head
    } else {
        struct Node *current = *head; // Start from the head
        while (current->next != NULL) { // Traverse to the end
            current = current->next;
        }
        current->next = newNode; // Link the new node
    }
}
// Function to delete a node from the beginning of the list
void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) { // If the list is empty
        printf("-1\n");
        return;
    }
    struct Node *temp = *head; // Store the head node
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the memory of the deleted node
}
// Function to display the list
void display(struct Node *head) {
    if (head == NULL) {
        printf("-1\n");
        return;
    }
    struct Node *current = head; // Start from the head
    while (current != NULL) { // Traverse the list
        printf("%d ", current->data); // Print data
        current = current->next;
    }
    printf("\n"); // End of the list
}
// Main function to test the singly linked list with user input
int main() {
    struct Node *head = NULL; // Initialize head as NULL
    int choice, data; // Variables for user choice and data input
    do {
        scanf("%d", &choice); // Get user choice
        switch (choice) {
        case 1: // Insert at End
            scanf("%d", &data); // Get the value to insert
            insertAtEnd(&head, data); // Insert the value
            break;
        case 2: // Delete from Beginning
            deleteAtBeginning(&head); // Delete the head node
            break;
        case 3: // Display List
            display(head); // Display the list
            break;
        case 4: // Exit
            break;
        default: // Invalid choice
            break;
        }
    } while (choice != 4); // Continue until user chooses to exit
    // Cleanup: Free remaining nodes
    while (head != NULL) {
        deleteAtBeginning(&head); // Delete all nodes
    }
    return 0;
}