#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Define a structure for the stack
struct Stack
{
    struct Node *top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Unable to push onto the stack.\n");
        return;
    }

    // Set the data and next pointer of the new node
    newNode->data = data;
    newNode->next = stack->top;

    // Update the top of the stack
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    // Check if the stack is empty
    if (isEmpty(stack))
    {
        printf("Stack is empty. Unable to pop.\n");
        return -1; // Return a value indicating failure
    }

    // Get the data from the top node
    int data = stack->top->data;

    // Store the reference to the top node
    struct Node *temp = stack->top;

    // Update the top of the stack
    stack->top = stack->top->next;

    // Free the memory of the popped node
    free(temp);

    return data;
}

// Function to peek at the top element of the stack without removing it
int peek(struct Stack *stack)
{
    // Check if the stack is empty
    if (isEmpty(stack))
    {
        printf("Stack is empty. Unable to peek.\n");
        return -1; // Return a value indicating failure
    }

    return stack->top->data;
}

// Function to print the elements of the stack
void printStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *current = stack->top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the stack
void freeStack(struct Stack *stack)
{
    struct Node *temp;
    while (stack->top != NULL)
    {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

// Driver program to test the stack implementation
int main()
{
    struct Stack myStack;
    initializeStack(&myStack);

    // Push elements onto the stack
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);

    // Print the stack
    printStack(&myStack);

    // Peek at the top element
    printf("Top element: %d\n", peek(&myStack));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&myStack));

    // Print the stack after popping
    printStack(&myStack);

    // Free the memory allocated for the stack
    freeStack(&myStack);

    return 0;
}
