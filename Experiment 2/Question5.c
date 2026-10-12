#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *arr;
int size;

void displayArray()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

void bubbleSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

int main()
{
    int choice, sortChoice;

    printf("Enter 0 for manual input or 1 for reverse-sorted array: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        printf("Enter array size: ");
        scanf("%d", &size);

        if (size <= 0)
        {
            printf("Invalid array size!\n");
            return 1;
        }
    }
    else if (choice == 1)
    {
        size = 100000;
        printf("Creating reverse-sorted array of %d elements.\n", size);
    }
    else
    {
        printf("Invalid choice!\n");
        return 1;
    }

    arr = malloc((size_t)size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    if (choice == 0)
    {
        printf("Enter array elements: ");

        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = size - i;
        }
    }

    printf("Enter 0 for Insertion Sort or 1 for Bubble Sort: ");
    scanf("%d", &sortChoice);

    clock_t start = clock();

    if (sortChoice == 0)
    {
        insertionSort();
        printf("Insertion Sort completed.\n");
    }
    else if (sortChoice == 1)
    {
        bubbleSort();
        printf("Bubble Sort completed.\n");
    }
    else
    {
        printf("Invalid sorting choice!\n");
        free(arr);
        return 1;
    }

    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time: %.4f seconds\n", elapsed);

    if (size <= 100)
    {
        printf("Sorted array: ");
        displayArray();
    }

    free(arr);

    return 0;
}
