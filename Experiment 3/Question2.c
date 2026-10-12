#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter number of days: ");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    int *prices = malloc((size_t)n * sizeof(int));

    if (prices == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter stock prices: ");

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &prices[i]) != 1)
        {
            printf("Invalid price input!\n");
            free(prices);
            return 1;
        }
    }

    int lowestPrice = prices[0];
    int maximumProfit = 0;

    for (int i = 1; i < n; i++)
    {
        int currentProfit = prices[i] - lowestPrice;

        if (currentProfit > maximumProfit)
        {
            maximumProfit = currentProfit;
        }

        if (prices[i] < lowestPrice)
        {
            lowestPrice = prices[i];
        }
    }

    printf("Maximum Profit: %d\n", maximumProfit);

    free(prices);

    return 0;
}
