#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Item structure to hold value, weight, and value/weight ratio
struct Item {
    int value;
    int weight;
    double ratio;
};

// Function to compare two items based on value/weight ratio (for sorting)
int compare(const void *a, const void *b) {
    double r1 = ((struct Item *)a)->ratio;
    double r2 = ((struct Item *)b)->ratio;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    return 0;
}

// Greedy Knapsack solution
int knapsack_greedy(struct Item items[], int n, int capacity) {
    int totalValue = 0, currentWeight = 0;
    
    // Sort items by value/weight ratio
    qsort(items, n, sizeof(struct Item), compare);

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }
    return totalValue;
}

// Dynamic Programming approach for 0/1 Knapsack
int knapsack_dp(int value[], int weight[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                dp[i][w] = (value[i - 1] + dp[i - 1][w - weight[i - 1]] > dp[i - 1][w]) 
                            ? (value[i - 1] + dp[i - 1][w - weight[i - 1]]) 
                            : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    // Example dataset
    struct Item items[] = {
        {60, 10, 60.0/10}, {100, 20, 100.0/20}, {120, 30, 120.0/30}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;

    // Measure execution time for Greedy Approach
    clock_t start_greedy = clock();
    int greedyMaxValue = knapsack_greedy(items, n, capacity);
    clock_t end_greedy = clock();
    double greedyTime = (double)(end_greedy - start_greedy) / CLOCKS_PER_SEC;

    // Measure execution time for Dynamic Programming Approach
    clock_t start_dp = clock();
    int dpMaxValue = knapsack_dp(value, weight, n, capacity);
    clock_t end_dp = clock();
    double dpTime = (double)(end_dp - start_dp) / CLOCKS_PER_SEC;

    // Output results
    printf("Greedy Knapsack Result: %d\n", greedyMaxValue);
    printf("Execution Time (Greedy): %lf seconds\n", greedyTime);
    printf("Dynamic Programming Knapsack Result: %d\n", dpMaxValue);
    printf("Execution Time (Dynamic Programming): %lf seconds\n", dpTime);

    return 0;
}
