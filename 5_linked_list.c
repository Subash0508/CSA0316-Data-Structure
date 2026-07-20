/*
 * Program 5: Create and display a Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Insert a node at the end of the linked list */
struct Node* insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Display the linked list */
void display(struct Node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Free all nodes to avoid memory leaks */
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    int n, value, i;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    display(head);

    freeList(head);
    return 0;
}
