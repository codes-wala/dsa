// 6. Evaluate Postfix Expression using Stack ADT
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>   // for pow()

#define MAX 100

int stack[MAX];
int top = -1;

// Push value to stack
void push(int value) {
    if (top == MAX - 1) {
        printf("-1\n"); // stack overflow
        exit(1);
    }
    stack[++top] = value;
}

// Pop value from stack
int pop() {
    if (top == -1) {
        printf("-1\n"); // stack underflow
        exit(1);
    }
    return stack[top--];
}

// Perform the given operation
int calculate(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;    // assuming valid division input
        case '^': return pow(a, b); // power a^b
        default: return 0;         // invalid operator fallback
    }
}

int main() {
    char expr[MAX];
    fgets(expr, sizeof(expr), stdin); // read postfix expression

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (isspace(ch))
            continue; // ignore spaces/newlines

        if (isdigit(ch)) {
            push(ch - '0'); // convert char digit to number
        } 
        else {
            // for operator, need at least 2 values
            if (top < 1) {
                printf("-1\n");
                return 1;
            }

            int b = pop();  // second operand
            int a = pop();  // first operand
            int result = calculate(ch, a, b);
            push(result);
        }
    }

    // After full evaluation, only one result must remain
    if (top != 0) {
        printf("-1\n");
        return 1;
    }

    printf("%d\n", pop());
    return 0;
}