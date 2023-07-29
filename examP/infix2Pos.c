#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  char data[MAX];
  int top;
} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool isEmpty(const Stack *stack) { return stack->top == -1; }

bool isFull(const Stack *stack) { return stack->top == MAX - 1; }

void push(Stack *stack, char value) {
  if (isFull(stack)) {
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
  }

  stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
  }

  return stack->data[stack->top--];
}

char peek(const Stack *stack) { // const here so that function peek doesn't modify the contents of the Stack pointd to the stack pointer
  if (isEmpty(stack)) {
    return '\0'; // Null character to indicate empty stack
  }

  return stack->data[stack->top];
}

int getPrecedence(char operator) {
  switch (operator) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

void infixToPostfix(const char *infix, char *postfix) {
  Stack stack;
  initialize(&stack);

  int i = 0; // Index for traversing the infix expression
  int j = 0; // Index for storing characters in the postfix expression

  while (infix[i] != '\0') {
    char ch = infix[i];

    // If the character is an operand, add it to the postfix expression
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      postfix[j++] = ch;
    }
    // If the character is an opening parenthesis, push it onto the stack
    else if (ch == '(') {
      push(&stack, ch);
    }
    // If the character is an operator
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
      // Pop operators from the stack and add them to the postfix expression
      // until a lower precedence operator is encountered or the stack becomes
      // empty
      while (!isEmpty(&stack) &&
             getPrecedence(ch) <= getPrecedence(peek(&stack))) {
        postfix[j++] = pop(&stack);
      }
      // Push the current operator onto the stack
      push(&stack, ch);
    }
    // If the character is a closing parenthesis, pop operators from the stack
    // and add them to the postfix expression until an opening parenthesis is
    // encountered
    else if (ch == ')') {
      while (!isEmpty(&stack) && peek(&stack) != '(') {
        postfix[j++] = pop(&stack);
      }
      // Pop the opening parenthesis from the stack
      if (!isEmpty(&stack) && peek(&stack) == '(') {
        pop(&stack);
      } else {
        printf("Mismatched parentheses!\n");
        exit(EXIT_FAILURE);
      }
    }

    i++; // Move to the next character in the infix expression
  }

  // Pop any remaining operators from the stack and add them to the postfix
  // expression
  while (!isEmpty(&stack)) {
    char topOperator = pop(&stack);
    // Check for mismatched parentheses
    if (topOperator == '(') {
      printf("Mismatched parentheses!\n");
      exit(EXIT_FAILURE);
    }
    postfix[j++] = topOperator;
  }

  postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
  char infix[MAX];
  char postfix[MAX];

  printf("Enter the infix expression: ");
  scanf("%s", infix);

  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}
