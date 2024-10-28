// Write a menu driven program to implement list ADT using CIRCULAR DOUBLE
// LINKEDLIST and perform the following operations
// 1. CREATE
// 2. INSERT AT BEGINNING
// 3. INSERT AT END
// 4. INSERT AT LOCATION
// 5. DELETE AT BEGINNING
// 6. DELETE AT END
// 7. DELETE AT LOCATION
// 8. DISPLAY
// 9. SEARCH
// 10. COUNT
// 11. REVERSE

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Global pointer to the head of the list
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself
    newNode->prev = newNode; // Point to itself
    return newNode;
}

// Function to create the circular doubly linked list
void createList()
{
    int data;
    printf("Enter data for the first node: ");
    scanf("%d", &data);
    head = createNode(data);
    printf("Circular doubly linked list created with first node data: %d\n", data);
}

// Function to insert a node at the beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *tail = head->prev; // Get the last node
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
    }
    head = newNode; // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *tail = head->prev; // Get the last node
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Function to insert a node at a specified location
void insertAtLocation(int data, int position)
{
    if (position == 0)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp->next == head)
    {
        insertAtEnd(data);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head)
    { // Only one node
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *tail = head->prev;
        struct Node *temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
    printf("Node deleted from beginning.\n");
}

// Function to delete a node at the end
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head)
    { // Only one node
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        free(tail);
    }
    printf("Node deleted from end.\n");
}

// Function to delete a node at a specified location
void deleteAtLocation(int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (position == 0)
    {
        deleteAtBeginning();
        return;
    }
    for (int i = 0; i < position && temp->next != head; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->next == head)
    {
        deleteAtEnd();
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    printf("Node deleted from position %d.\n", position);
}

// Function to display the list
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to search for an element
void searchElement(int data)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    int position = 0;
    do
    {
        if (temp->data == data)
        {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("Element %d not found in the list.\n", data);
}

// Function to count the number of nodes
void countNodes()
{
    if (head == NULL)
    {
        printf("Number of nodes in the list: 0\n");
        return;
    }
    struct Node *temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Number of nodes in the list: %d\n", count);
}

// Function to reverse the list
void reverseList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    struct Node *current = head;
    do
    {
        struct Node *nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        current = nextNode;
    } while (current != head);
    head = head->prev; // Update head to the new first node
    printf("List reversed.\n");
}

// Main function to drive the menu
int main()
{
    int choice, data, position;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Location\n");
        printf("8. Display List\n");
        printf("9. Search Element\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &position);
            insertAtLocation(data, position);
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteAtLocation(position);
            break;
        case 8:
            displayList();
            break;
        case 9:
            printf("Enter element to search: ");
            scanf("%d", &data);
            searchElement(data);
            break;
        case 10:
            countNodes();
            break;
        case 11:
            reverseList();
            break;
        case 12:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
