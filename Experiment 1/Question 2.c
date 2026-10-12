#include <stdio.h>
#include <stdlib.h>

int target, size;
int *arr;
int *subset;
int total = 0;

void findSubsets(int index, int sum, int count)
{
    if (sum == target)
    {
        total++;

        printf("Subset %d: ", total);

        for (int i = 0; i < count; i++)
        {
            printf("%d ", subset[i]);
        }

        printf("\n");
        return;
    }

    if (index >= size || sum > target)
    {
        return;
    }

    // Include the current element
    subset[count] = arr[index];

    findSubsets(index + 1, sum + arr[index], count + 1);

    // Exclude the current element
    findSubsets(index + 1, sum, count);
}

int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    arr = malloc(size * sizeof(int));
    subset = malloc(size * sizeof(int));

    if (arr == NULL || subset == NULL)
    {
        printf("Memory allocation failed!\n");

        free(arr);
        free(subset);

        return 1;
    }

    printf("Enter the array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    findSubsets(0, 0, 0);

    printf("Total number of subsets = %d\n", total);

    free(arr);
    free(subset);

    return 0;
}
