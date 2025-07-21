#include <stdio.h>
#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void Enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    q[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

int Dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q[front];
    front++;
    return value;
}

void Display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    Display();

    printf("Dequeued: %d\n", Dequeue());
    Display();

    return 0;
}
