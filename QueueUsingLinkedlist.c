// Write a menu driven program to implement QUEUE ADT using linkedlist and perform
// the following operation
// 1. ENQUEUE
// 2. DEQUEUE
// 3. DISPLAY
// 4. SEARCH
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the queue
struct Node
{
    int data;
    struct Node *next;
};

// Define the structure for the queue
struct Queue
{
    struct Node *front; // Pointer to the front of the queue
    struct Node *rear;  // Pointer to the rear of the queue
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return (q->front == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = createNode(data);
    if (isEmpty(q))
    {
        q->front = newNode; // If the queue is empty, front and rear point to the new node
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode; // Add the new node at the end of the queue
        q->rear = newNode;       // Update the rear pointer
    }
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 if the queue is empty
    }
    struct Node *temp = q->front; // Get the front node
    int data = temp->data;        // Get the data to return
    q->front = q->front->next;    // Move the front pointer to the next node
    free(temp);                   // Free the dequeued node
    if (q->front == NULL)
    { // If the queue is now empty, set rear to NULL
        q->rear = NULL;
    }
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to display the queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the queue
void search(struct Queue *q, int data)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot search.\n");
        return;
    }
    struct Node *temp = q->front;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the queue.\n", data);
}

// Main function to drive the menu
int main()
{
    struct Queue *q = createQueue();
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(q, data);
            break;
        case 5:
            free(q); // Free the queue memory before exiting
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
