#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("Enter array size: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof(int));
    int *output = malloc((size_t)n * sizeof(int));

    if (arr == NULL || output == NULL)
    {
        printf("Memory allocation failed!\n");
        free(arr);
        free(output);
        return 1;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid element!\n");
            free(arr);
            free(output);
            return 1;
        }
    }

    output[0] = 1;

    for (int i = 1; i < n; i++)
    {
        output[i] = output[i - 1] * arr[i - 1];
    }

    int suffix = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        output[i] *= suffix;
        suffix *= arr[i];
    }

    printf("Product array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }

    printf("\n");

    free(arr);
    free(output);

    return 0;
}
