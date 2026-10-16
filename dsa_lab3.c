#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return ((rear + 1) % SIZE == front);
}

bool isEmpty() {
    return (front == -1);
}
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return -1;
    }

    int dequeuedValue = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {

        front = (front + 1) % SIZE;
    }

    return dequeuedValue;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (true) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display(); h
    enqueue(60);

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    printf("\n--- testing circular wrap-around ---\n");
    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
