#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Error: The previous node cannot be NULL.\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}

void deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Append elements to the list
    for (int i = 1; i <= 5; i++) {
        append(head, i);
    }

    printf("Original List: ");
    displayList(head);

    // Insert an element after a specific node
    int dataToInsert, insertAfterData;
    printf("Enter the element to be inserted: ");
    scanf("%d", &dataToInsert);
    printf("Enter the element after which to insert: ");
    scanf("%d", &insertAfterData);

    struct Node* current = head;
    while (current != NULL) {
        if (current->data == insertAfterData) {
            insertAfter(current, dataToInsert);
            break;
        }
        current = current->next;
    }

    printf("List after insertion: ");
    displayList(head);

    // Delete a node from the list
    int dataToDelete;
    printf("Enter the element to delete: ");
    scanf("%d", &dataToDelete);
    deleteNode(head, dataToDelete);

    printf("List after deletion: ");
    displayList(head);

    // Free memory for the entire list
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
