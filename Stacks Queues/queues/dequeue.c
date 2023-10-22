#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Dequeue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool isEmpty(struct Dequeue *dq) {
    return (dq->front == -1 && dq->rear == -1);
}

bool isFull(struct Dequeue *dq) {
    return ((dq->rear + 1) % MAX_SIZE == dq->front);
}

void insertFront(struct Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot insert.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->arr[dq->front] = value;
}

void insertRear(struct Dequeue *dq, int value) {
    if (isFull(dq)) {
        printf("Dequeue is full. Cannot insert.\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }
    dq->arr[dq->rear] = value;
}

int deleteFront(struct Dequeue *dq) {
    int deletedValue;
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot delete.\n");
        return -1; // Assuming -1 represents an error or empty value
    }
    deletedValue = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    return deletedValue;
}

int deleteRear(struct Dequeue *dq) {
    int deletedValue;
    if (isEmpty(dq)) {
        printf("Dequeue is empty. Cannot delete.\n");
        return -1; // Assuming -1 represents an error or empty value
    }
    deletedValue = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return deletedValue;
}

int getFront(struct Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return -1; // Assuming -1 represents an error or empty value
    }
    return dq->arr[dq->front];
}

int getRear(struct Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return -1; // Assuming -1 represents an error or empty value
    }
    return dq->arr[dq->rear];
}

int main() {
    struct Dequeue dq;
    initialize(&dq);

    // Insert elements at front and rear
    insertFront(&dq, 1);
    insertRear(&dq, 2);
    insertRear(&dq, 3);
    insertFront(&dq, 0);

    // Display the front and rear elements
    printf("Front element: %d\n", getFront(&dq));
    printf("Rear element: %d\n", getRear(&dq));

    // Delete elements from front and rear
    printf("Deleted from front: %d\n", deleteFront(&dq));
    printf("Deleted from rear: %d\n", deleteRear(&dq));

    // Display the front and rear elements after deletions
    printf("Front element: %d\n", getFront(&dq));
    printf("Rear element: %d\n", getRear(&dq));

    return 0;
}