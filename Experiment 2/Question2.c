#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size < 2)
    {
        printf("At least two elements are required.\n");
        return 0;
    }

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int secondLargest = 0;
    int smallest = arr[0];
    int secondSmallest = 0;

    int hasSecondLargest = 0;
    int hasSecondSmallest = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            hasSecondLargest = 1;
            largest = arr[i];
        }
        else if (arr[i] < largest &&
                 (!hasSecondLargest || arr[i] > secondLargest))
        {
            secondLargest = arr[i];
            hasSecondLargest = 1;
        }

        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            hasSecondSmallest = 1;
            smallest = arr[i];
        }
        else if (arr[i] > smallest &&
                 (!hasSecondSmallest || arr[i] < secondSmallest))
        {
            secondSmallest = arr[i];
            hasSecondSmallest = 1;
        }
    }

    if (hasSecondLargest)
    {
        printf("Second largest element: %d\n", secondLargest);
    }
    else
    {
        printf("Second largest distinct element does not exist.\n");
    }

    if (hasSecondSmallest)
    {
        printf("Second smallest element: %d\n", secondSmallest);
    }
    else
    {
        printf("Second smallest distinct element does not exist.\n");
    }

    free(arr);

    return 0;
}
