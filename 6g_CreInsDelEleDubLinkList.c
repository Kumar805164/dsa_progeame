#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node with a given value from the doubly linked list
void deleteElement(struct Node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = *head;

    // Search for the node with the given data
    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    // If the node is not found
    if (current == NULL)
    {
        printf("Element %d not found. Cannot delete.\n", data);
        return;
    }

    // Update the next and prev pointers of adjacent nodes
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    // Free the memory of the deleted node
    free(current);
}

// Function to print the doubly linked list in forward order
void printForward(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to print the doubly linked list in reverse order
void printReverse(struct Node *head)
{
    struct Node *temp = head;

    // Traverse to the end of the list
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }

    // Print in reverse order
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to free the allocated memory for the doubly linked list
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Driver program to test the functions
int main()
{
    struct Node *head = NULL;

    // Insert elements at the beginning and end of the doubly linked list
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);

    // Print the doubly linked list in forward and reverse order
    printf("Doubly Linked List in Forward Order: ");
    printForward(head);

    printf("Doubly Linked List in Reverse Order: ");
    printReverse(head);

    // Delete an element from the doubly linked list
    deleteElement(&head, 2);

    // Print the doubly linked list after deletion
    printf("Doubly Linked List after Deletion: ");
    printForward(head);

    // Free the memory allocated for the doubly linked list
    freeList(head);

    return 0;
}
