// WAP short the array element using bubble short
#include <stdio.h>
void main()
{
    int a[20], n, i, j, t, pass = 0;
    printf("Enter size of array-");
    scanf("%d", &n);
    printf("Enter element - ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array element befour sort ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    // bubble short Desscinding order

    for (pass = 0; pass < n - 1; pass++)
    {
        for (j = 0; j < n - pass - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    printf(" Aftre sort the array element using bubble sort\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
