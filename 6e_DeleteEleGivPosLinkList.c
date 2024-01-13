#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to delete a node at the given position in the linked list
void deleteAtPosition(struct Node **head, int position)
{
    // If the list is empty, do nothing
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete at the given position.\n");
        return;
    }

    // If the position is 0, delete the first node
    if (position == 0)
    {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node just before the specified position
    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // If the given position is greater than the number of nodes in the list
    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds. Cannot delete.\n");
        return;
    }

    // Store the reference to the node to be deleted
    struct Node *nodeToDelete = temp->next;

    // Update the next pointer of the previous node to skip the node to be deleted
    temp->next = nodeToDelete->next;

    // Free the memory of the deleted node
    free(nodeToDelete);
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
    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    // Print the linked list before deletion
    printf("Linked List before deletion: ");
    printList(head);

    // Delete an element at the given position (position = 2)
    deleteAtPosition(&head, 2);

    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
