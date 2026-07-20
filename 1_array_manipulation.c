/*
 * Program 1: Array Manipulation
 * Operations: Insertion, Deletion, Modification, Replacement
 */

#include <stdio.h>

#define MAX 100

void display(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insertElement(int arr[], int n, int pos, int value) {
    int i;
    if (n >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return n;
    }
    if (pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return n;
    }
    for (i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    int i;
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return n;
    }
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

void modifyElement(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position.\n");
        return;
    }
    arr[pos] = value;
}

void replaceElement(int arr[], int n, int oldValue, int newValue) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
            found = 1;
        }
    }
    if (!found)
        printf("Value %d not found in array.\n", oldValue);
}

int main() {
    int arr[MAX];
    int n = 0, choice, pos, value, oldValue, newValue;

    printf("Enter number of initial elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n----- Array Manipulation Menu -----\n");
        printf("1. Display\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Modify Element (by position)\n");
        printf("5. Replace Element (by value)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter position (0-indexed) and value to insert: ");
                scanf("%d %d", &pos, &value);
                n = insertElement(arr, n, pos, value);
                display(arr, n);
                break;
            case 3:
                printf("Enter position (0-indexed) to delete: ");
                scanf("%d", &pos);
                n = deleteElement(arr, n, pos);
                display(arr, n);
                break;
            case 4:
                printf("Enter position (0-indexed) and new value: ");
                scanf("%d %d", &pos, &value);
                modifyElement(arr, n, pos, value);
                display(arr, n);
                break;
            case 5:
                printf("Enter old value and new value: ");
                scanf("%d %d", &oldValue, &newValue);
                replaceElement(arr, n, oldValue, newValue);
                display(arr, n);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
