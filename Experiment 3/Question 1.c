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

    int *height = malloc((size_t)n * sizeof(int));

    if (height == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter heights of bars: ");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &height[i]) != 1 || height[i] < 0)
        {
            printf("Invalid height!\n");
            free(height);
            return 1;
        }
    }

    int left = 0;
    int right = n - 1;

    int maxLeft = 0;
    int maxRight = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                water += maxLeft - height[left];
            }

            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                water += maxRight - height[right];
            }

            right--;
        }
    }

    printf("Total trapped water: %d units\n", water);

    free(height);

    return 0;
}
