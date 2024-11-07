#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

int knapSack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    int i;
    for ( i = 0; i <= n; i++) {
        int w;
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i-1] <= w) {
                dp[i][w] = (val[i-1] + dp[i-1][w-wt[i-1]] > dp[i-1][w]) ?
                           (val[i-1] + dp[i-1][w-wt[i-1]]) : dp[i-1][w];
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int val[n], wt[n];

    printf("Enter the values of the items:\n");
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    int u;
    for ( u  = 0; u < n; u++) {
        scanf("%d", &wt[u]);
    }

    printf("Maximum value in knapsack = %d\n", knapSack(W, wt, val, n));

    return 0;
}
