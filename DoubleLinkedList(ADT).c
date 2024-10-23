#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create the doubly linked list
void createList()
{
    int data;
    printf("Enter data for the node: ");
    scanf("%d", &data);
    head = createNode(data);
    printf("Doubly linked list created with first node data: %d\n", data);
}

// Function to insert a node at the beginning
void insertAtBeginning(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
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
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node at the beginning
void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
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
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
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
    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
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
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for an element
void searchElement(int data)
{
    struct Node *temp = head;
    int position = 0;
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
    printf("Element %d not found in the list.\n", data);
}

// Function to count the number of nodes
void countNodes()
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes in the list: %d\n", count);
}

// Function to reverse the list
void reverseList()
{
    struct Node *temp = NULL;
    struct Node *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
    }
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
