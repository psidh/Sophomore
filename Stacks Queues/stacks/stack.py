class Stack:
    def __init__(self, limit):
        self.limit = limit
        self.stack = []
    
    def is_full(self):
        return len(self.stack) == self.limit
    
    def push(self, value):
        if self.is_full():
            print("Stack is full")
            return
        self.stack.append(value)
        print(f"Pushed {value} onto the stack")
    
    def pop(self):
        if not self.stack:
            print("Stack Underflow")
            return -1
        value = self.stack.pop()
        print(f"Popped {value} from the stack")
        return value
    
    def peek(self):
        if not self.stack:
            print("Stack is empty")
            return -1
        return self.stack[-1]
    
    def is_empty(self):
        return not self.stack
    
    def print_stack(self):
        if self.is_empty():
            print("Stack is empty")
            return
        print("Elements in the stack:")
        for value in reversed(self.stack):
            print(value)

def main():
    limit = int(input("Enter the maximum number of elements for the stack: "))
    stack = Stack(limit)
    
    while True:
        print("Stack Menu:")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Check if stack is empty")
        print("5. Print stack")
        print("6. Exit")
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            if stack.is_full():
                print("Stack is full")
            else:
                value = int(input("Enter value to push: "))
                stack.push(value)
        elif choice == 2:
            stack.pop()
        elif choice == 3:
            print(f"Top element: {stack.peek()}")
        elif choice == 4:
            print(f"Is stack empty? {'Yes' if stack.is_empty() else 'No'}")
        elif choice == 5:
            stack.print_stack()
        elif choice == 6:
            print("Exiting...")
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()
