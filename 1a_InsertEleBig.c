#include <stdio.h>
int main()
{
    int a[100], n, i, value;
    printf("Enter the array size - ");
    scanf("%d", &n);
    printf("Enter the array element - ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array element that you have enterd are listed below :\n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\n", a[i]);
    }
    printf("Pleses enter the element which you want to add at the begning -");
    scanf("%d", &value);
    n = n + 1;
    for (int i = n - 1; i > 0; i--)
    {
        /* code */
        a[i] = a[i - 1];
    }
    a[i] = value;
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\n", a[i]);
    }
    return 0;
}