#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at a given index in the linked list
void insertAtIndex(struct Node **head, int data, int index)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If index is 0, insert at the beginning
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the node at index - 1
    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++)
    {
        temp = temp->next;
    }

    // If the given index is greater than the number of nodes in the list
    if (temp == NULL)
    {
        printf("Index out of bounds.\n");
        free(newNode);
        return;
    }

    // Insert the new node at the specified index
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the linked list
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

    // Insert elements into the linked list
    insertAtIndex(&head, 1, 0);
    insertAtIndex(&head, 2, 1);
    insertAtIndex(&head, 3, 2);
    insertAtIndex(&head, 5, 1);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
