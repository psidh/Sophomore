class Queue {
    constructor() {
        this.queue = [];
        this.front = -1;
        this.rear = -1;
    }

    isFull() {
        return this.rear === this.queue.length - 1;
    }

    isEmpty() {
        return this.front === -1;
    }

    enqueue(value) {
        if (this.isFull()) {
            console.log("Queue is full");
            return;
        }
        if (this.isEmpty()) {
            this.front = 0;
        }
        this.queue[++this.rear] = value;
        console.log(`Enqueued ${value}`);
    }

    dequeue() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return -1;
        }
        const value = this.queue[this.front++];
        if (this.front > this.rear) {
            this.front = this.rear = -1;
        }
        console.log(`Dequeued ${value}`);
        return value;
    }

    peek() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return -1;
        }
        return this.queue[this.front];
    }

    printQueue() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return;
        }
        console.log("Elements in the queue:");
        for (let i = this.front; i <= this.rear; i++) {
            console.log(this.queue[i]);
        }
    }
}

const queue = new Queue();

// Example usage
queue.enqueue(5);
queue.enqueue(10);
queue.enqueue(15);
queue.printQueue();
queue.dequeue();
queue.printQueue();
console.log("Front element:", queue.peek());
