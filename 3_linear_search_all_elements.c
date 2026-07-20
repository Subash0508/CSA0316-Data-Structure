/*
 * Program 3: Search for all elements in an array using Linear Search
 *
 * This program takes multiple keys to search and reports the index
 * (or all matching indices) for each key using Linear Search.
 */

#include <stdio.h>

#define MAX 100

/* Linear search: prints all indices where key is found */
int linearSearchAll(int arr[], int n, int key) {
    int i, count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("  Found %d at index %d\n", key, i);
            count++;
        }
    }
    return count;
}

int main() {
    int arr[MAX];
    int keys[MAX];
    int n, k, i, count;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of elements to search for: ");
    scanf("%d", &k);
    printf("Enter %d elements to search: ", k);
    for (i = 0; i < k; i++)
        scanf("%d", &keys[i]);

    printf("\n----- Linear Search Results -----\n");
    for (i = 0; i < k; i++) {
        printf("Searching for %d:\n", keys[i]);
        count = linearSearchAll(arr, n, keys[i]);
        if (count == 0)
            printf("  %d not found in the array.\n", keys[i]);
        else
            printf("  Total occurrences: %d\n", count);
    }

    return 0;
}
