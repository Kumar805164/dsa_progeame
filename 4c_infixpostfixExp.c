#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
void push(char item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack overflow..!!");
        return;
    }
    stack[++top] = item;
}
char pop()
{
    if (top == -1)
    {
        printf("stack underflow...!!");
        return -1;
    }
    return stack[top--];
}
int precedence(char operator)
{
    if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator== '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void infixTopostfix(char infix[], char postfix[])
{
    int i, j;
    char token;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            postfix[j++] = token;
        }
        else if (token == '(')
        {
            push(token);
        }
        else if (token == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(')
            {
                pop();
            }
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] == pop();
            }
            push(token);
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];
    printf("Enter infix expression - ");
    scanf("%s", infixExpression);
    infixTopostfix(infixExpression, postfixExpression);
    printf("Postfix Expression : %s\n", postfixExpression);
    return 0;
}