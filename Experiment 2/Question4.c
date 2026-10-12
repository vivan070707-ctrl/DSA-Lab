#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int size)
{
    printf("Rotated array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void reverseArray(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void rotateArray(int arr[], int size, int positions)
{
    positions = positions % size;

    reverseArray(arr, 0, size - 1);
    reverseArray(arr, 0, positions - 1);
    reverseArray(arr, positions, size - 1);
}

int main()
{
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size!\n");
        return 1;
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

    int positions;

    printf("Enter rotation positions: ");
    scanf("%d", &positions);

    positions = ((positions % size) + size) % size;

    rotateArray(arr, size, positions);

    displayArray(arr, size);

    free(arr);

    return 0;
}
