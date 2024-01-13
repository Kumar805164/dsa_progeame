#include <stdio.h>
void main()
{
    int a[100], i, n, prs, item;
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
    printf("Enter the position where new element to be inseted-\n ");
    scanf("%d", &prs);
    printf("Enter the new element- ");
    scanf("%d", &item);
    n = n + 1;
    for (int i = n - 1; i >= prs; i--)
    {
        /* code */
        a[i] = a[i - 1];
    }
    a[prs - 1] = item;
    printf("New Array element is - \n");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d\n", a[i]);
    }
}