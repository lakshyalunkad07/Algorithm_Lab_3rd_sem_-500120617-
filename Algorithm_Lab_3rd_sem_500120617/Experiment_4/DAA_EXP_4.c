#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    struct Activity *activityA = (struct Activity *)a;
    struct Activity *activityB = (struct Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select the maximum number of activities
void activitySelection(struct Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(activities[0]), compare);

    printf("Selected activities:\n");

    // The first activity always gets selected
    int lastSelectedIndex = 0;
    printf("Activity %d: [%d, %d]\n", lastSelectedIndex + 1, activities[lastSelectedIndex].start, activities[lastSelectedIndex].finish);

    // Iterate through the sorted activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= activities[lastSelectedIndex].finish) {
            printf("Activity %d: [%d, %d]\n", i + 1, activities[i].start, activities[i].finish);
            lastSelectedIndex = i; // Update the last selected activity index
        }
    }
}

int main() {
    // Predefined list of activities
    struct Activity activities[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    // Call the activity selection function
    activitySelection(activities, n);

    return 0;
}
