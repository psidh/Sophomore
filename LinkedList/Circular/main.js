class Node {
    data: number;
    next: Node | null;
    prev: Node | null;

    constructor(data: number) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

function insertAtBeginning(head: Node | null, data: number): Node {
    const newNode = new Node(data);

    if (head === null) {
        newNode.next = newNode;
        newNode.prev = newNode;
    } else {
        newNode.next = head;
        newNode.prev = head.prev;
        head.prev!.next = newNode;
        head.prev = newNode;
    }

    return newNode;
}

function insertAtEnd(head: Node | null, data: number): Node {
    const newNode = new Node(data);

    if (head === null) {
        newNode.next = newNode;
        newNode.prev = newNode;
        return newNode;
    }

    newNode.next = head;
    newNode.prev = head.prev;
    head.prev!.next = newNode;
    head.prev = newNode;

    return head;
}

function insertAfter(head: Node | null, prevNode: Node | null, data: number): Node {
    if (prevNode === null) {
        return head!;
    }

    const newNode = new Node(data);
    newNode.prev = prevNode;
    newNode.next = prevNode.next;
    prevNode.next!.prev = newNode;
    prevNode.next = newNode;

    return head!;
}

function insertBefore(head: Node | null, nextNode: Node | null, data: number): Node {
    if (nextNode === null) {
        return head!;
    }

    const newNode = new Node(data);
    newNode.prev = nextNode.prev;
    newNode.next = nextNode;
    nextNode.prev!.next = newNode;
    nextNode.prev = newNode;

    if (nextNode === head) {
        head = newNode;
    }

    return head!;
}

function deleteNode(head: Node | null, delNode: Node | null): Node {
    if (head === null || delNode === null) {
        return head!;
    }

    if (head === delNode && head.next === head) {
        return null;
    }

    delNode.prev!.next = delNode.next;
    delNode.next!.prev = delNode.prev;

    if (delNode === head) {
        head = delNode.next;
    }

    return head!;
}

function printForward(head: Node | null) {
    if (head === null) {
        console.log("List is empty.");
        return;
    }

    let current = head;
    do {
        console.log(current.data);
        current = current.next!;
    } while (current !== head);
}

function printBackward(head: Node | null) {
    if (head === null) {
        console.log("List is empty.");
        return;
    }

    let current = head.prev!;
    do {
        console.log(current.data);
        current = current.prev!;
    } while (current !== head.prev);
}

let head: Node | null = null;

head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtBeginning(head, 5);
head = insertAfter(head, head!.next, 15);
head = insertBefore(head, head!.next, 8);

console.log("Circular Doubly Linked List (Forward): ");
printForward(head);

console.log("Circular Doubly Linked List (Backward): ");
printBackward(head);

head = deleteNode(head, head!.next!); // Deleting the second node

console.log("Circular Doubly Linked List after deleting a node: ");
printForward(head);

// Free memory (Not necessary in JavaScript/TypeScript due to automatic garbage collection)
