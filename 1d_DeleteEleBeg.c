#include <stdio.h>
void main()
{
    int a[100], i, n;
    printf("Enter Size of Array- ");
    scanf("%d", &n);
    printf("Enter array element - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("The arrry element that you have enter in array -");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    printf("After delet the element - \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}