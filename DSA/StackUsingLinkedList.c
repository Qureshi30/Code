// Write a menu driven program to implement STACK ADT using linkedlist and perform
// the following operations
// 1. PUSH
// 2. POP
// 3. DISPLAY
// 4. SEARCH
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node
{
    int data;
    struct Node *next;
};

// Initialize the top of the stack
struct Node *top = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = top; // Point new node to the current top
    top = newNode;       // Update top to new node
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty, cannot pop\n");
        return;
    }
    struct Node *temp = top;
    top = top->next; // Update top to the next node
    printf("%d popped from stack\n", temp->data);
    free(temp); // Free the popped node
}

// Function to display the stack elements
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element in the stack
void search(int data)
{
    struct Node *temp = top;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("%d found at position %d in the stack\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("%d not found in the stack\n", data);
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
