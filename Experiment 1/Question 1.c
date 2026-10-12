#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size!");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    int *pos = malloc(size * sizeof(int));
    int *neg = malloc(size * sizeof(int));
    int *ans = malloc(size * sizeof(int));

    if (arr == NULL || pos == NULL || neg == NULL || ans == NULL)
    {
        printf("Memory allocation failed!");

        free(arr);
        free(pos);
        free(neg);
        free(ans);

        return 1;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n_pos = 0, n_neg = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            pos[n_pos++] = arr[i];
        }
        else
        {
            neg[n_neg++] = arr[i];
        }
    }

    if (n_pos - n_neg > 1 || n_neg - n_pos > 1)
    {
        printf("Alternating arrangement is not possible.\n");

        free(arr);
        free(pos);
        free(neg);
        free(ans);

        return 0;
    }

    int j = 0;

    if (n_pos > n_neg)
    {
        for (int i = 0; i < n_neg; i++)
        {
            ans[j++] = pos[i];
            ans[j++] = neg[i];
        }

        ans[j] = pos[n_pos - 1];
    }
    else if (n_neg > n_pos)
    {
        for (int i = 0; i < n_pos; i++)
        {
            ans[j++] = neg[i];
            ans[j++] = pos[i];
        }

        ans[j] = neg[n_neg - 1];
    }
    else
    {
        for (int i = 0; i < n_pos; i++)
        {
            ans[j++] = neg[i];
            ans[j++] = pos[i];
        }
    }

    printf("Rearranged array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(arr);
    free(pos);
    free(neg);
    free(ans);

    return 0;
}
