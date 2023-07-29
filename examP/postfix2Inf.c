#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX][MAX];
    int top;
} Stack;

void initialize(Stack* stack) { stack->top = -1; }

bool isEmpty(const Stack* stack) { return stack->top == -1; }

bool isFull(const Stack* stack) { return stack->top == MAX - 1; }

void push(Stack* stack, const char* value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }

    stack->top++;
    if (strcpy_s(stack->data[stack->top], MAX, value) != 0) {
        printf("Error copying string.\n");
        exit(EXIT_FAILURE);
    }
}

char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top--];
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void postfixToInfix(const char* postfix, char* infix) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            char operand[2];
            operand[0] = ch;
            operand[1] = '\0';
            push(&stack, operand);
        } else if (isOperator(ch)) {
            char op2[MAX], op1[MAX], temp[MAX];

            strcpy_s(op2, MAX, pop(&stack));
            strcpy_s(op1, MAX, pop(&stack));

            sprintf(temp, "(%s%c%s)", op1, ch, op2);

            push(&stack, temp);
        }

        i++;
    }

    strcpy_s(infix, MAX, pop(&stack));
}

int main() {
    char postfix[MAX];
    char infix[MAX];

    printf("Enter the postfix expression: ");
    scanf_s("%s", postfix);

    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
