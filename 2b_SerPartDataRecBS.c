#include <stdio.h>
int binarySearch(int arr[], int low, int high, int size, int value)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
            return binarySearch(arr, low, high, size, value);
        }
        else
        {
            low = mid + 1;
            return binarySearch(arr, low, high, size, value);
        }
    }
    else
    {
        return -1;
    }
}
void main()
{
    int arr[100], i, n, value, index;
    printf(" Enter the number of element ");
    scanf("%d", &n);
    if (n > 100)
    {
        printf("Array is out of bound");
        return;
    }
    printf("enter the element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf(" enter the value you want to search : ");
    scanf("%d", &value);
    index = binarySearch(arr, 0, n - 1, n, value);
    if (index >= 0)
    {
        printf("The value found of index %d", index);
    }
    else
    {
        printf("The value does not exits ");
    }
}