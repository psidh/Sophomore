#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;

    return head;
}

Node* insertAfter(Node* head, Node* prevNode, int data) {
    if (prevNode == nullptr) {
        return head;
    }

    Node* newNode = new Node(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;

    return head;
}

Node* insertBefore(Node* head, Node* nextNode, int data) {
    if (nextNode == nullptr) {
        return head;
    }

    Node* newNode = new Node(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;

    if (nextNode == head) {
        head = newNode;
    }

    return head;
}

Node* deleteNode(Node* head, Node* delNode) {
    if (head == nullptr || delNode == nullptr) {
        return head;
    }

    if (head == delNode && head->next == head) {
        delete delNode;
        return nullptr;
    }

    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;

    if (delNode == head) {
        head = delNode->next;
    }

    delete delNode;

    return head;
}

void printForward(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    std::cout << "... (Loop)" << std::endl;
}

void printBackward(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* current = head->prev;
    do {
        std::cout << current->data << " -> ";
        current = current->prev;
    } while (current != head->prev);
    std::cout << "... (Loop)" << std::endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtBeginning(head, 5);
    head = insertAfter(head, head->next, 15);
    head = insertBefore(head, head->next, 8);

    std::cout << "Circular Doubly Linked List (Forward): ";
    printForward(head);

    std::cout << "Circular Doubly Linked List (Backward): ";
    printBackward(head);

    head = deleteNode(head, head->next); // Deleting the second node

    std::cout << "Circular Doubly Linked List after deleting a node: ";
    printForward(head);

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
