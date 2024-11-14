#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 10000 // Reduced text size for quicker comparison

// Naive String Matching Algorithm
int naiveSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            count++;
        }
    }
    return count;
}

// Rabin-Karp String Matching Algorithm
int rabinKarpSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int d = 256;  // Number of characters in the input alphabet
    int q = 101;  // A prime number for hashing
    int count = 0;

    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text

    // Calculate the hash value for pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j]) {
                j++;
            }
            if (j == m) {
                count++;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }
    return count;
}

// Knuth-Morris-Pratt (KMP) String Matching Algorithm
void computeLPSArray(char *pattern, int m, int *lps) {
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmpSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    int count = 0;

    computeLPSArray(pattern, m, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    // Small sample text and pattern
    char text[MAX];
    char pattern[] = "ABAB"; // Pattern to search

    // Filling the text with repeated patterns
    for (int i = 0; i < MAX - 1; i++) {
        text[i] = "ABAB"[i % 4];
    }
    text[MAX - 1] = '\0';  // Null-terminate the text string

    clock_t start, end;
    double timeTaken;

    // Naive Search
    start = clock();
    int countNaive = naiveSearch(text, pattern);
    end = clock();
    timeTaken = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("Naive Search: Matches found = %d, Time = %.2f milliseconds\n", countNaive, timeTaken);

    // Rabin-Karp Search
    start = clock();
    int countRK = rabinKarpSearch(text, pattern);
    end = clock();
    timeTaken = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("Rabin-Karp Search: Matches found = %d, Time = %.2f milliseconds\n", countRK, timeTaken);

    // KMP Search
    start = clock();
    int countKMP = kmpSearch(text, pattern);
    end = clock();
    timeTaken = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;
    printf("KMP Search: Matches found = %d, Time = %.2f milliseconds\n", countKMP, timeTaken);

    return 0;
}
