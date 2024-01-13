#include <stdio.h>
void main()
{
    int a[100], n, i;
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
    n = n - 1;
    printf("After delete array ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}