
//Correct Circular Logic:

// You're using (rear + 1) % SIZE == front to detect full queue — ✅ correct.

// You're wrapping both front and rear using modulo — ✅ essential for circular behavior.

// Proper isEmpty() and isFull() checks:

// isEmpty() just checks if front == -1 — ✅ clean and sufficient.

// isFull() is working correctly using modulo logic — ✅

// Accurate Handling of Edge Cases:

// When dequeuing the last element, you reset front and rear to -1 — ✅ well handled.

// Improved Display() function:

// You’re using a while loop to iterate from front to rear with wrapping — ✅ this solves the common bug where rear < front.

#include <stdio.h>
#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

int isFull() {
    // In circular queue, full when next rear position is front
    return (rear+1)%SIZE == front;
}

int isEmpty() {
    // When both front and rear are -1, queue is empty
    return front == -1;  //rear == -1 is not useful as it makes the code redundant becoz there is no element
}                        //it is clear that rear is already at -1

void Enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {                //updating the place of rear
        rear = (rear + 1) % SIZE;
    }
    q[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

int Dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q[front];
    if (front == rear) {
        // Queue is now empty after this dequeue
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

void Display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    // Traverse the queue from front to rear using circular logic
    while (1) {
        printf("%d ", q[i]);        //We didn't used the condition i<=rear becoz 
        if (i == rear)              //in some condition rear may not be smaller than as it is a circular queue
            break;
        i = (i + 1) % SIZE;
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


//Working but improper code


// #include <stdio.h>
// #define SIZE 100

// int q[SIZE];
// int front = -1, rear = -1;

// int isFull() {
//     return (rear+1)%SIZE == front;
// }

// int isEmpty() {
//     return front == -1;
// }

// void Enqueue(int value) {
//     if (isFull()) {
//         printf("Queue Overflow\n");
//         return;
//     }
//     if (front == -1) {
//         front = 0;
//     }
//     rear++;
//     q[rear] = value;
//     printf("%d inserted into the queue.\n", value);
// }

// int Dequeue() {
//     if (isEmpty()) {
//         printf("Queue Underflow\n");
//         return -1;
//     }
//     int value = q[front];
//     front++;
//     return value;
// }

// void Display() {
//     if (isEmpty()) {
//         printf("Queue is empty\n");
//         return;
//     }
//     printf("Queue elements are: ");
//     for (int i = front; i <= rear; i++) {
//         printf("%d ", q[i]);
//     }
//     printf("\n");
// }

// int main() {
//     Enqueue(10);
//     Enqueue(20);
//     Enqueue(30);

//     Display();

//     printf("Dequeued: %d\n", Dequeue());
//     Display();

//     return 0;
// }
