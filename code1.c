// 1. Implement Singly Linked List ADT. Insert at Beginning, Delete at End
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};
// Global variables for linked list management
struct Node *head = NULL;
// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
// Function to delete a node from the end of the linked list
void deleteAtEnd() {
    if (head == NULL) {
        printf("-1\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
// Function to display the linked list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("-1\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Main function to run the menu-driven program
int main() {
    int choice, value;
    do {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%d", &value);
            insertAtBeginning(value);
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("-1\n");
        }
    } while (choice != 4);
    return 0;
}