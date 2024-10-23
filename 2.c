#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node
{
    int data;
    struct Node *next;
};

// Initialize the head of the circular linked list
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create the circular linked list
void createList()
{
    int data;
    printf("Enter the value for the node: ");
    scanf("%d", &data);

    struct Node *newNode = createNode(data);
    head = newNode;
    newNode->next = head; // Point the new node to itself to make it circular

    printf("Circular linked list created with node: %d\n", data);
}

// Function to insert at the beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // Point to itself
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        { // Traverse to find the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link last node to new node
        newNode->next = head; // Point new node to head
        head = newNode;       // Update head to new node
    }
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert at the end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // Point to itself
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link last node to new node
        newNode->next = head; // Point new node to head
    }
    printf("Inserted %d at the end\n", data);
}

// Function to insert at a specific location
void insertAtLocation(int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode;       // Link previous node to new node
    printf("Inserted %d at position %d\n", data, position);
}

// Function to delete at the beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head)
    { // Only one node in the list
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *last = head;
        while (last->next != head)
        { // Find the last node
            last = last->next;
        }
        head = head->next; // Update head to the next node
        last->next = head; // Point last node to new head
        free(temp);        // Free the old head
    }
    printf("Deleted node at the beginning\n");
}

// Function to delete at the end
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head)
    { // Only one node in the list
        free(head);
        head = NULL;
        printf("Deleted the only node in the list\n");
        return;
    }
    struct Node *last = head;
    while (last->next != head)
    {                // Traverse to the last node
        temp = last; // Keep track of the previous node
        last = last->next;
    }
    temp->next = head; // Link previous node to head
    free(last);        // Free the last node
    printf("Deleted node at the end\n");
}

// Function to delete at a specific location
void deleteAtLocation(int position)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return;
    }
    if (position == 1)
    {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    prev->next = temp->next; // Link previous node to next node
    free(temp);              // Free the deleted node
    printf("Deleted node at position %d\n", position);
}

// Function to display the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to search for a node in the list
void search(int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    int position = 1;
    do
    {
        if (temp->data == data)
        {
            printf("%d found at position %d\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    printf("%d not found in the list\n", data);
}

// Function to count the number of nodes in the list
int count()
{
    if (head == NULL)
    {
        return 0;
    }
    struct Node *temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Function to reverse the list
void reverse()
{
    if (head == NULL)
    {
        printf("List is empty, cannot reverse\n");
        return;
    }
    struct Node *prev = NULL, *current = head, *next = NULL;
    struct Node *last = head;

    // Traverse to find the last node
    while (last->next != head)
    {
        last = last->next;
    }

    do
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev and current one step forward
        current = next;
    } while (current != head);

    head->next = prev; // Make the last node point to the new head
    head = prev;       // Update head to the new head
    printf("List reversed\n");
}

// Main function
int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Location\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Location\n");
        printf("8. Display\n");
        printf("9. Search\n");
        printf("10. Count\n");
        printf("11. Reverse\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createList();
            break;
        case 2:
            printf("Enter the value to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter the value to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            printf("Enter the value and position to insert: ");
            scanf("%d%d", &data, &position);
            insertAtLocation(data, position);
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteAtLocation(position);
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Enter the value to search: ");
            scanf("%d", &data);
            search(data);
            break;
        case 10:
            printf("Total nodes: %d\n", count());
            break;
        case 11:
            reverse();
            break;
        case 12:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
