#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at position %d.\n", target, result);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}
