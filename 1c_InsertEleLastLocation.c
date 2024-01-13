#include <stdio.h>
int main()
{
    int a[100], n, i, item;
    printf("enter size of array -");
    scanf("%d", &n);
    printf("Enter array element - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The element that you have enter - \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    printf("Plese enter the element that you want to add last position\n");
    scanf("%d", &item);
    n = n + 1;
    a[n - 1] = item;
    printf("Now the array element are listed below : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}