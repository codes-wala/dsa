// 5. Convert an Infix expression to Postfix expression using stack ADT
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
char infix[MAX], postfix[MAX];

// Push element on stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("-1\n");
        return;
    }
    stack[++top] = ch;
}

// Pop element from stack
char pop() {
    if (top == -1) {
        printf("-1\n");
        return '\0';
    }
    return stack[top--];
}

// Check if stack is empty
int isEmpty() {
    return (top == -1);
}

// Return priority of operators
int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix() {
    int i, j = 0;
    char ch, temp;

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // Ignore newline
        if (ch == '\n')
            continue;

        // If operand, add to postfix
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            postfix[j++] = ch;
        }
        // Push '(' on stack
        else if (ch == '(') {
            push(ch);
        }
        // Pop until '(' found
        else if (ch == ')') {
            while (!isEmpty() && (temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        }
        // Operator encountered
        else {
            while (!isEmpty() && priority(stack[top]) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate string
}

// Print postfix
void printPostfix() {
    printf("%s", postfix);
}

int main() {
    // Input infix expression
    fgets(infix, MAX, stdin);

    // Convert & print
    infixToPostfix();
    printPostfix();

    return 0;
}