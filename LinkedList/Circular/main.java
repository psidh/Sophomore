class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class CircularDoublyLinkedList {
    public static Node insertAtBeginning(Node head, int data) {
        Node newNode = new Node(data);

        if (head == null) {
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            newNode.next = head;
            newNode.prev = head.prev;
            head.prev.next = newNode;
            head.prev = newNode;
        }

        return newNode;
    }

    public static Node insertAtEnd(Node head, int data) {
        Node newNode = new Node(data);

        if (head == null) {
            newNode.next = newNode;
            newNode.prev = newNode;
            return newNode;
        }

        newNode.next = head;
        newNode.prev = head.prev;
        head.prev.next = newNode;
        head.prev = newNode;

        return head;
    }

    public static Node insertAfter(Node head, Node prevNode, int data) {
        if (prevNode == null) {
            return head;
        }

        Node newNode = new Node(data);
        newNode.prev = prevNode;
        newNode.next = prevNode.next;
        prevNode.next.prev = newNode;
        prevNode.next = newNode;

        return head;
    }

    public static Node insertBefore(Node head, Node nextNode, int data) {
        if (nextNode == null) {
            return head;
        }

        Node newNode = new Node(data);
        newNode.prev = nextNode.prev;
        newNode.next = nextNode;
        nextNode.prev.next = newNode;
        nextNode.prev = newNode;

        if (nextNode == head) {
            head = newNode;
        }

        return head;
    }

    public static Node deleteNode(Node head, Node delNode) {
        if (head == null || delNode == null) {
            return head;
        }

        if (head == delNode && head.next == head) {
            return null;
        }

        delNode.prev.next = delNode.next;
        delNode.next.prev = delNode.prev;

        if (delNode == head) {
            head = delNode.next;
        }

        return head;
    }

    public static void printForward(Node head) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        do {
            System.out.print(current.data + " -> ");
            current = current.next;
        } while (current != head);
        System.out.println("... (Loop)");
    }

    public static void printBackward(Node head) {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head.prev;
        do {
            System.out.print(current.data + " -> ");
            current = current.prev;
        } while (current != head.prev);
        System.out.println("... (Loop)");
    }

    public static void main(String[] args) {
        Node head = null;

        head = insertAtEnd(head, 10);
        head = insertAtEnd(head, 20);
        head = insertAtBeginning(head, 5);
        head = insertAfter(head, head.next, 15);
        head = insertBefore(head, head.next, 8);

        System.out.println("Circular Doubly Linked List (Forward):");
        printForward(head);

        System.out.println("Circular Doubly Linked List (Backward):");
        printBackward(head);

        head = deleteNode(head, head.next); // Deleting the second node

        System.out.println("Circular Doubly Linked List after deleting a node:");
        printForward(head);
    }
}
