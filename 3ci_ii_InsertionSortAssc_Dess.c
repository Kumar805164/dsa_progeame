#include <stdio.h>
void insertionsort(int arr[], int size)
{
    int i, key, j;
    for (int i = 0; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
    }
    arr[j + 1] = key;
}
void main()
{
    int arr[100], n, i;
    printf("Enter size of array- ");
    scanf("%d", &n);
    if (n > 100)
    {
        printf("Invalide array size - ");
        return;
    }
    printf("Enter Element of array -");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("After insert array element ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    insertionsort(arr, n);
    {
        printf("The sorted arrray is accending order is -");
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", arr[i]);
        }
        printf("The sorted arrray is decending order is -");
        for (int i = n - 1; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}