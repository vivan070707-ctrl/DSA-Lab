#include <stdio.h>
#include <stdlib.h>

int *arr;
int size;

void display()
{
    printf("Array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void insertElement(int index, int value)
{
    if (index < 0 || index > size)
    {
        printf("Invalid index!\n");
        return;
    }

    int *temp = realloc(arr, (size + 1) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    arr = temp;

    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size++;

    printf("Element inserted successfully.\n");
    display();
}

void deleteElement(int index)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    if (size > 0)
    {
        int *temp = realloc(arr, size * sizeof(int));

        if (temp != NULL)
        {
            arr = temp;
        }
    }
    else
    {
        free(arr);
        arr = NULL;
    }

    printf("Element deleted successfully.\n");
    display();
}

int main()
{
    printf("Enter array size: ");
    scanf("%d", &size);

    if (size < 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    if (size > 0)
    {
        arr = malloc(size * sizeof(int));

        if (arr == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    else
    {
        arr = NULL;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    display();

    int choice;

    while (1)
    {
        printf("\n0. Insert element\n");
        printf("1. Delete element\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            break;
        }

        if (choice == 0)
        {
            int index, value;

            printf("Enter index: ");
            scanf("%d", &index);

            printf("Enter value: ");
            scanf("%d", &value);

            insertElement(index, value);
        }
        else if (choice == 1)
        {
            int index;

            printf("Enter index: ");
            scanf("%d", &index);

            deleteElement(index);
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    free(arr);

    return 0;
}
