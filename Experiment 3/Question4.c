#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter array size: ");

    if (scanf("%d", &n) != 1 || n <= 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    int arr[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid array element!\n");
            return 1;
        }

        if (arr[i] < 1 || arr[i] >= n)
        {
            printf("Elements must be between 1 and %d.\n", n - 1);
            return 1;
        }
    }

    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Detect the cycle
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    // Phase 2: Find the duplicate
    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    printf("Duplicate element: %d\n", slow);

    return 0;
}
