#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter array size: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int totalSum = 0;

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid array element!\n");
            free(arr);
            return 1;
        }

        totalSum += arr[i];
    }

    int leftSum = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        int rightSum = totalSum - leftSum - arr[i];

        if (leftSum == rightSum)
        {
            printf("Equilibrium index: %d\n", i);
            found = 1;
        }

        leftSum += arr[i];
    }

    if (!found)
    {
        printf("No equilibrium index found.\n");
    }

    free(arr);

    return 0;
}
