#include <stdio.h>
#define MAX_SIZE 3
int queue[MAX_SIZE];
int front = -1, rear = -1;
int main()
{
    int choice, item;
    printf("\n1.Enqueue Operation    2.Dequeue operation\n  3.Display Queue    4.Exit\n");
    printf("***********************************************");
    while (1)
    {
        printf("\nEnter your choice...");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (rear == MAX_SIZE - 1)
            {
                printf("Overflow & Exit..!!\n");
            }
            else
            {
                printf("Enter the element - ");
                scanf("%d", &item);
                if (front == -1)
                {
                    front = rear = 0;
                }
                else
                {
                    rear++;
                }
                queue[rear] = item;
                printf("Item Inserted..\n");
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("Underflow &Exit...\n");
            }
            else
            {
                item = queue[front];
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
                printf("Item deleted\n");
            }
            break;
        case 3:
            if (front == -1)
            {
                printf("Queue is empty...\n");
            }
            else
            {
                printf("Queue Element : ");
                for (int i = front; i <= rear; i++)
                {
                    printf("%d", queue[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("Exit\n");
            return 0;
        default:
            printf("Invalide choice..!!");
        }
    }
}