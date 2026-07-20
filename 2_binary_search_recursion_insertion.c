/*
 * Program 2: Binary Search using Recursion
 * and Insertion of an element into an array
 *
 * Note: Binary search requires the array to be sorted.
 * After insertion, the element is placed at the correct sorted position.
 */

#include <stdio.h>

#define MAX 100

/* Recursive Binary Search: returns index of key if found, else -1 */
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

/* Insert a value into a sorted array, keeping it sorted */
int insertSorted(int arr[], int n, int value) {
    int i;
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }

    /* find the correct position */
    for (i = n - 1; i >= 0 && arr[i] > value; i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = value;
    return n + 1;
}

void display(int arr[], int n) {
    int i;
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n, i, choice, key, value, result;

    printf("Enter number of elements (array must be sorted): ");
    scanf("%d", &n);
    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n----- Binary Search & Insertion Menu -----\n");
        printf("1. Display array\n");
        printf("2. Search element (Binary Search - recursive)\n");
        printf("3. Insert element (maintains sorted order)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = binarySearch(arr, 0, n - 1, key);
                if (result != -1)
                    printf("Element %d found at index %d.\n", key, result);
                else
                    printf("Element %d not found.\n", key);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                n = insertSorted(arr, n, value);
                display(arr, n);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
