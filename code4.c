// 4. Implement Stack ADT using an array
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 10 // max size of stack is 10

int stack[max]; // array to store stack elements
int top = -1; // top points to the index of the top element, -1 means stack is empty

// Function to push value into stack
void push(int val) {
    if (top == max - 1) { // if top reaches max-1, stack is full
        printf("-1\n"); // print -1 if overflow
        return;
    } else {
        stack[++top] = val; // increase top and insert value
    }
}

// Function to pop value from stack
int pop() {
    if (top == -1) { // if top = -1, stack is empty
        printf("-1\n"); // print -1 if underflow
        return -1;
    } else {
        return stack[top--]; // return top value and decrease top
    }
}

// Function to see top element of stack
int peek() {
    if (top == -1) { // if stack is empty
        printf("-1\n"); // print -1
        return -1;
    }
    return stack[top]; // return top element without removing it
}

int main() {
    int val = 0, choice;
    do {
        // take user choice input (1=push, 2=pop, 3=peek, 4=exit)
        scanf("%d", &choice);
        switch (choice) {
        case 1: 
            // push operation
            scanf("%d", &val); // take value to push
            push(val);
            break;
        case 2:
            // pop operation
            val = pop(); // pop element
            printf("%d\n", val); // print popped value
            break;
        case 3:
            // peek operation
            val = peek(); // get top element
            if (val != -1) {
                printf("%d\n", val);
            }
            break;
        case 4:
            exit(0); // exit program
            break;
        default:
            printf("-1\n"); // invalid choice
            break;
        }
    } while (choice != 4); // loop until choice is 4
    return 0;
}