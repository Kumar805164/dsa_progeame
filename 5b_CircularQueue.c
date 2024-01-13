/*write a C program to cinstruct a circular queue as an abstract data type and
perform the following operation of a queue :
1. Insert an element into a queue
. Delete an element into a queue */
#include <stdio.h>
#include <conio.h>
#define Size 20

int Cque[Size];
int front = -1;
int rear = -1;
void inqueue();
void dequeue();
void display();
void main()
{
    int ch;
    while (1)
    {
        printf("\n Perform Operation on the Circular Queue");
        printf("********************************");
        printf("\n1.Insert the element        2.Delete the element\n3.Display queue element       4.Exit\n");
        printf("********************************");
        printf("\nEnter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            inqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice..!!");
        }
    }
}
void inqueue()
{
    int v;
    if ((front == 0 && rear == Size - 1) || (front == rear + 1))
    {
        printf("Queue is overflow..!!");
        return;
    }
    else if (rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == Size - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
        printf("Enter element.. \n");
        scanf("%d", &v);
        Cque[rear] = v;
    }
}
void dequeue()
{
    int v;
    if (front == -1)
    {
        printf("Queue is overflow..!!");
        return;
    }
    v = Cque[front];
    printf(v);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == Size - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}
void display()
{
    int i;
    if (rear == -1)
    {
        printf("Queue is underflow...!!");
    }
    else if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf(Cque[i]);
        }
    }
    else
    {
        for (int i = front; i < Size; i++)
        {
            printf(Cque);
        }
    }
}