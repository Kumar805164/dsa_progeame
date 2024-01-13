#include <stdio.h>
#include <stdlib.h>

#define Size 4
int top = -1, inp_array[Size];
void push();
void pop();
void show();
int main()
{
    int ch;
    while (1)
    {
        printf("\n Perform Operation on the STACK");
        printf("\n1.Push the element        2.Pop the element\n3.show array element       4.Exit\n");
        printf("********************************");
        printf("\nEnter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalide choice...!");
        }
    }
}
void push()
{
    int x;
    if (top == Size - 1)
    {
        printf("Stack overflow...!!");
    }
    else
    {
        printf("Enter element to be added onto the stack - \n");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow...!!");
    }
    else
    {
        printf("Pop element :%d", inp_array[top]);
        top = top - 1;
    }
}
void show()
{
    int i;
    if (top == -1)
    {
        printf("\n Underflow....!!");
    }
    else
    {
        printf("\nElement present in the stack -\n ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", inp_array[i]);
        }
    }
}