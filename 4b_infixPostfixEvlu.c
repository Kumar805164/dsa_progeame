#include <stdio.h>
int stack[100];
int top = -1;
void push(int value)
{
    stack[++top] = value;
}
int pop()
{
    return stack[top--];
}
int peek()
{
    return stack[top];
}
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}
int applyOperator(char op, int b, int a)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return a ^ b;
    }
    return 0;
}
int eval(char *expression)
{
    int i, value;
    char operator;
    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            value = expression[i] - 'o';
            push(value);
        }
        else if (expression[i] = '(')
        {
            i++;
            value = eval(expression + i);
            while (expression[i] != ')')
            {
                i++;
            }
            push(value);
        }
        else if (precedence(expression[i] > 0))
        {
            operator= expression[i];
            value = applyOperator(operator, pop(), pop());
            push(value);
        }
        i++;
    }
    return pop();
}
int main()
{
    char expression[100];
    printf("Enter the expression : ");
    scanf("%s", expression);
    int result = eval(expression);
    printf("Result - %d\n", result);
    return 0;
}
