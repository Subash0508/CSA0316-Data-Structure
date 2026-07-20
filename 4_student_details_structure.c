/*
 * Program 4: Store and display student details using Structure
 */

#include <stdio.h>

#define MAX_STUDENTS 50

struct Student {
    int rollNo;
    char name[50];
    char branch[30];
    float marks;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Branch: ");
        scanf("%s", students[i].branch);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\n----- Student Details -----\n");
    printf("%-10s %-20s %-15s %-10s\n", "Roll No", "Name", "Branch", "Marks");
    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-15s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].branch,
               students[i].marks);
    }

    return 0;
}
