#include <stdio.h>
int main()
{
    int a[100], i, n, pos = 0, Snum;
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
    printf("Enter element to search data -");
    scanf("%d", &Snum);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == Snum)
        {
            printf("%d found at position %d", Snum, i + 1);
            return 0;
        }
    }
    printf("%d not found - ", Snum);
    return 0;
}