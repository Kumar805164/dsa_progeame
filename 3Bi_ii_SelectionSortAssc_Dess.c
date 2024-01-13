#include <stdio.h>
void main()
{
    int a[100], i, n, j, temp;
    printf("Enter size of array ");
    scanf("%d", &n);
    if (n > 100)
    {
        printf("Array is out of bound !!");
        return;
    }
    printf("Enter array element - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array element after insert ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The Array Assecending order sorted -\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("The array Dcending order sorted -\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\n", a[i]);
    }
}