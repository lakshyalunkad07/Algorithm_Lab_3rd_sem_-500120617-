#include <stdio.h>

void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int nodeCount, int sum) {
    if (sum == total) {  // If we found a subset with the desired sum
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (int i = nodeCount; i < n; i++) {  // Try including each element in the subset
        subset[subsetSize] = set[i];
        sumOfSubsets(set, subset, n, subsetSize + 1, total, i + 1, sum + set[i]);
    }
}

int main() {
    // Predefined input values
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int total = 9;

    int subset[n];  // Array to store subset elements
    printf("Subsets with sum %d:\n", total);
    sumOfSubsets(set, subset, n, 0, total, 0, 0);

    return 0;
}
