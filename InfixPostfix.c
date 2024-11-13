#include <stdio.h>
#include <ctype.h>
#define max 100

int top = -1, a[max];

// Push function
void push(char x) {
    a[++top] = x;
}

// Pop function
char pop() {
    if (top == -1) {
        return -1;  // Error case, stack empty
    } else {
        return a[top--];
    }
}

// Precedence function
int precedence(char c) {
    if (c == '(') {
        return 0;
    } else if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return -1;  // For non-operators
}

// Infix to Postfix Conversion
void infixtopostfix(char infix[max], char postfix[max]) {
    char temp;
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        temp = infix[i];
        
        // If the character is an operand, add to postfix
        if (isalnum(temp)) {
            postfix[j++] = temp;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (temp == '(') {
            push(temp);
        }
        // If the character is a closing parenthesis, pop until '(' is found
        else if (temp == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        }
        // Operator handling
        else {
            while (top != -1 && precedence(a[top]) >= precedence(temp)) {
                postfix[j++] = pop();
            }
            push(temp);
        }
        i++;
    }
    
    // Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[max], postfix[max];
    
    printf("Enter the infix expression:\n");
    fgets(infix, max, stdin);  // Use fgets for safe input
    printf("The infix expression is: %s", infix);
    
    infixtopostfix(infix, postfix);
    
    printf("The postfix expression is: %s\n", postfix);
    
    return 0;
}
