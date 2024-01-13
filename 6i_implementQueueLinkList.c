#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Define a structure for the queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to initialize an empty queue
void initializeQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Unable to enqueue.\n");
        return;
    }

    // Set the data and next pointer of the new node
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Otherwise, update the next pointer of the current rear to the new node
        queue->rear->next = newNode;
        // Update the rear to the new node
        queue->rear = newNode;
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue)
{
    // Check if the queue is empty
    if (isEmpty(queue))
    {
        printf("Queue is empty. Unable to dequeue.\n");
        return -1; // Return a value indicating failure
    }

    // Get the data from the front node
    int data = queue->front->data;

    // Store the reference to the front node
    struct Node *temp = queue->front;

    // If there is only one node in the queue, set both front and rear to NULL
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        // Otherwise, update the front to the next node
        queue->front = queue->front->next;
    }

    // Free the memory of the dequeued node
    free(temp);

    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *current = queue->front;
    printf("Queue: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the allocated memory for the queue
void freeQueue(struct Queue *queue)
{
    struct Node *temp;
    while (queue->front != NULL)
    {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}

// Driver program to test the queue implementation
int main()
{
    struct Queue myQueue;
    initializeQueue(&myQueue);

    // Enqueue elements into the queue
    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    // Print the queue
    printQueue(&myQueue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(&myQueue));

    // Print the queue after dequeue
    printQueue(&myQueue);

    // Free the memory allocated for the queue
    freeQueue(&myQueue);

    return 0;
}
