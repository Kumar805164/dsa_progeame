#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to delete the last node from the linked list
void deleteFromLast(struct Node **head)
{
    // If the list is empty, do nothing
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the last position.\n");
        return;
    }

    // If there is only one node, delete it and set head to NULL
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Free the last node and set the next pointer of the second last node to NULL
    free(temp->next);
    temp->next = NULL;
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

    // Insert elements at the end of the linked list
    for (int i = 1; i <= 5; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Print the linked list before deletion
    printf("Linked List before deletion: ");
    printList(head);

    // Delete an element from the last position
    deleteFromLast(&head);

    // Print the linked list after deletion
    printf("Linked List after deletion: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
