#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push an element into stack
void push(char ch)
{
    stack[++top] = ch;
}

// Pop an element from stack
char pop()
{
    return stack[top--];
}

// Return precedence of operator
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If opening parenthesis, push into stack
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing parenthesis
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
/*
SAMPLE OUTPUT:
Enter an infix expression: A+B*(C-D)^E                                                                                    
Postfix expression: ABCD-E^*+                 
*/