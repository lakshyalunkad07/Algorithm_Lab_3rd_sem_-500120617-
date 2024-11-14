#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void traditionalMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]);
void strassenMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]);
void printMatrix(int n, int matrix[][n]);

// Function to add two matrices
void addMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtractMatrix(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Traditional matrix multiplication (O(n^3) complexity)
void traditionalMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's matrix multiplication (implementation omitted for brevity)
void strassenMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    // Implementation of Strassen's matrix multiplication algorithm
    // This is a placeholder for your Strassen's algorithm implementation
    // You can define the actual algorithm as needed
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n]) {
    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 4;  // Use a fixed size for the matrix (ensure it's a power of 2, e.g., 4)
    
    // Define fixed matrices A and B
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int B[4][4] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    
    int C[4][4];  // Result matrix

    clock_t start, end;
    double time_used;

    // Traditional multiplication
    start = clock();
    traditionalMatrixMultiplication(n, A, B, C);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Traditional multiplication time: %f seconds\n", time_used);
    printMatrix(n, C);  // Print the result of traditional multiplication

    // Strassen multiplication
    start = clock();
    strassenMatrixMultiplication(n, A, B, C);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Strassen multiplication time: %f seconds\n", time_used);
    printMatrix(n, C);  // Print the result of Strassen multiplication

    return 0;
}
