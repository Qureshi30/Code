// Write a menu driven program to implement QUEUE ADT using array and perform the
// following operation
// 1. ENQUEUE
// 2. DEQUEUE
// 3. DISPLAY
// 4. COUNT
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the queue

int front = -1;
int rear = -1;
int queue[MAX];

// Function to enqueue an element into the queue
void enqueue(int x)
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is Full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
        printf("\nElement %d entered", x);
    }
    else
    {
        rear++;
        queue[rear] = x;
        printf("\nElement %d entered", x);
    }
}

// Function to dequeue an element from the queue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else if (front == rear)
    {
        printf("\nElement %d dequeued", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\nElement %d dequeued", queue[front]);
        front++;
    }
}

// Function to display the elements in the queue
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nQueue elements are:");
        for (int i = front; i <= rear; i++)
        {
            printf(" %d", queue[i]);
        }
        printf("\n");
    }
}

// Function to count the number of elements in the queue
void count()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nTotal elements in the queue: %d", (rear - front + 1));
    }
}

int main()
{
    int ch, n1;
    while (1)
    {
        printf("\n\n*** Queue Operations ***");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Count");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number to enqueue: ");
            scanf("%d", &n1);
            enqueue(n1);
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
            printf("\nWrong choice! Please try again.");
        }
    }
}
