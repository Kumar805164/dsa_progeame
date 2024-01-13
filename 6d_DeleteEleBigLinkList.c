#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to delete the first node from the linked list
void deleteFromBeginning(struct Node **head)
{
    // If the list is empty, do nothing
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    // Store the reference to the first node
    struct Node *temp = *head;

    // Move the head to the next node
    *head = temp->next;

    // Free the memory of the deleted node
    free(temp);
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

    // Insert elements at the beginning of the linked list
    for (int i = 5; i >= 1; i--)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    // Print the linked list before deletion
    printf("Linked List before deletion: ");
    printList(head);

    // Delete an element from the beginning
    deleteFromBeginning(&head);

    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
