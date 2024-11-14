#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge Sort Algorithm
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int left_arr[n1], right_arr[n2];

    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort Algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// User Input and Performance Comparison
int main() {
    int num_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    int* arr = (int*)malloc(num_elements * sizeof(int));

    printf("Enter %d elements:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original Array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();
    merge_sort(arr, 0, num_elements - 1);
    double merge_sort_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("Merge Sorted Array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Merge Sort Time: %f seconds\n", merge_sort_time);

    // Reset the array for quick sort
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    start_time = clock();
    quick_sort(arr, 0, num_elements - 1);
    double quick_sort_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("Quick Sorted Array:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Quick Sort Time: %f seconds\n", quick_sort_time);

    return 0;
}
