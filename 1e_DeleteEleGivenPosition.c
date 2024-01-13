#include <stdio.h>
void main()
{
    int a[100], n, i, dlval, j;
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
    printf("Enter position which you want to delete element in array ");
    scanf("%d", &dlval);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == dlval)
        {
            for (int j = 0; j < n - 1; j++)
            {
                a[i] = a[j + 1];
            }
            a[j] = 0;
            n = n - 1;
        }
    }
    printf("After deleteing array element - ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[j]);
    }
}