class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def insert_at_beginning(head, data):
    new_node = Node(data)

    if head is None:
        new_node.next = new_node
        new_node.prev = new_node
    else:
        new_node.next = head
        new_node.prev = head.prev
        head.prev.next = new_node
        head.prev = new_node

    return new_node

def insert_at_end(head, data):
    new_node = Node(data)

    if head is None:
        new_node.next = new_node
        new_node.prev = new_node
        return new_node

    new_node.next = head
    new_node.prev = head.prev
    head.prev.next = new_node
    head.prev = new_node

    return head

def insert_after(head, prev_node, data):
    if prev_node is None:
        return head

    new_node = Node(data)
    new_node.prev = prev_node
    new_node.next = prev_node.next
    prev_node.next.prev = new_node
    prev_node.next = new_node

    return head

def insert_before(head, next_node, data):
    if next_node is None:
        return head

    new_node = Node(data)
    new_node.prev = next_node.prev
    new_node.next = next_node
    next_node.prev.next = new_node
    next_node.prev = new_node

    if next_node == head:
        head = new_node

    return head

def delete_node(head, del_node):
    if head is None or del_node is None:
        return head

    if head == del_node and head.next == head:
        del del_node
        return None

    del_node.prev.next = del_node.next
    del_node.next.prev = del_node.prev

    if del_node == head:
        head = del_node.next

    del del_node

    return head

def print_forward(head):
    if head is None:
        print("List is empty.")
        return

    current = head
    while True:
        print(current.data, "->", end=" ")
        current = current.next
        if current == head:
            break
    print("... (Loop)")

def print_backward(head):
    if head is None:
        print("List is empty.")
        return

    current = head.prev
    while True:
        print(current.data, "->", end=" ")
        current = current.prev
        if current == head.prev:
            break
    print("... (Loop)")

head = None

head = insert_at_end(head, 10)
head = insert_at_end(head, 20)
head = insert_at_beginning(head, 5)
head = insert_after(head, head.next, 15)
head = insert_before(head, head.next, 8)

print("Circular Doubly Linked List (Forward):")
print_forward(head)

print("Circular Doubly Linked List (Backward):")
print_backward(head)

head = delete_node(head, head.next)  # Deleting the second node

print("Circular Doubly Linked List after deleting a node:")
print_forward(head)

# No need to explicitly free memory in Python (handled by garbage collector)
