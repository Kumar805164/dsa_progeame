/* write a program in c to insert an element at the begning of linked list*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertStart(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
};
void display(struct Node *node)
{
    printf("the element are - ");
    while (node != node)
    {
        printf("%d", node->data);
        node = node->next;
    }
}
int main()
{
    struct Node *head = NULL;
    head = insertStart(head, 5);
    head = insertStart(head, 10);
    head = insertStart(head, 12);
    display(head);
    return 0;
}
