// Write a menu driven program to implement CIRCULAR QUEUE ADT using array and
// perform the following operation
// 1. ENQUEUE
// 2. DEQUEUE
// 3. DISPLAY
// 4. COUNT
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the circular queue

int front = -1;
int rear = -1;
int queue[MAX];

// Function to enqueue an element into the circular queue
void enqueue(int x)
{
    if (front == (rear + 1) % MAX)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("Element %d enqueued\n", x);
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        printf("Element %d enqueued\n", x);
    }
}

// Function to dequeue an element from the circular queue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Element %d dequeued\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Element %d dequeued\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

// Function to display the elements of the circular queue
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]); // Print the last element
    }
}

// Function to count the number of elements in the circular queue
void count()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int cnt = (rear >= front) ? (rear - front + 1) : (MAX - front + rear + 1);
        printf("Total elements in the queue: %d\n", cnt);
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n*** Circular Queue Operations ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid input, please try again\n");
        }
    }
}
