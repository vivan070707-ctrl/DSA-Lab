#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0)
    {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    int (*matrix)[cols] = malloc(rows * sizeof(*matrix));

    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int capacity = rows * cols;
    int *row = malloc(capacity * sizeof(int));
    int *col = malloc(capacity * sizeof(int));
    int *value = malloc(capacity * sizeof(int));

    if (row == NULL || col == NULL || value == NULL)
    {
        printf("Memory allocation failed!\n");

        free(matrix);
        free(row);
        free(col);
        free(value);

        return 1;
    }

    int count = 0;

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0)
            {
                row[count] = i;
                col[count] = j;
                value[count] = matrix[i][j];

                count++;
            }
        }
    }

    printf("\nOriginal Matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row  Col  Value\n");

    for (int i = 0; i < count; i++)
    {
        printf("%3d  %3d  %5d\n",
               row[i], col[i], value[i]);
    }

    printf("\nTotal non-zero elements: %d\n", count);

    free(matrix);
    free(row);
    free(col);
    free(value);

    return 0;
}
