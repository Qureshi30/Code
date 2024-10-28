// Write a menu driven program to implement list ADT using SINGLE LINKEDLIST and
// perform the following operations
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

struct node
{
    int info;
    struct node *next;
};

struct node *list = NULL;

// Function to create a new node
struct node *getnode()
{
    return (struct node *)malloc(sizeof(struct node));
}

// Function to free a node
void freenode(struct node *p)
{
    free(p);
}

// Insert at the beginning
void insert_at_beg(int x)
{
    struct node *nn = getnode();
    nn->info = x;
    nn->next = list;
    list = nn;
}

// Insert at the end
void insert_at_end(int x)
{
    struct node *nn = getnode();
    nn->info = x;
    nn->next = NULL;
    if (list == NULL)
    {
        list = nn;
    }
    else
    {
        struct node *temp = list;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

// Insert at a specific position
void insert_at_anypoint(int x, int p)
{
    struct node *nn = getnode();
    nn->info = x;
    if (p == 1)
    {
        nn->next = list;
        list = nn;
    }
    else
    {
        struct node *temp = list;
        for (int i = 1; i < p - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            nn->next = temp->next;
            temp->next = nn;
        }
        else
        {
            printf("Position out of bounds\n");
            freenode(nn);
        }
    }
}

// Delete at the beginning
void delete_at_beg()
{
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *dn = list;
    list = dn->next;
    freenode(dn);
}

// Delete at the end
void delete_at_end()
{
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *dn = list;
    struct node *temp = NULL;
    if (dn->next == NULL)
    {
        free(dn);
        list = NULL;
    }
    else
    {
        while (dn->next != NULL)
        {
            temp = dn;
            dn = dn->next;
        }
        temp->next = NULL;
        freenode(dn);
    }
}

// Delete at a specific position
void deleteAtPosition(int position)
{
    // Check if the list is empty
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // If deleting the first node
    if (position == 1)
    {
        delete_at_beg(); // Call function to delete the first node
        return;
    }

    struct node *current = list;  // Start from the head of the list
    struct node *previous = NULL; // To keep track of the previous node

    // Traverse the list to find the node before the specified position
    for (int i = 1; i < position && current != NULL; i++)
    {
        previous = current;      // Move previous to current node
        current = current->next; // Move to the next node
    }

    // Check if the current node is not NULL (valid position)
    if (current != NULL)
    {
        previous->next = current->next; // Link the previous node to the next node
        freenode(current);              // Free the memory of the deleted node
        printf("Node at position %d deleted\n", position);
    }
    else
    {
        printf("Position out of bounds\n"); // Position is invalid
    }
}

// Display the list
void display()
{
    struct node *print = list;
    if (print == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (print != NULL)
    {
        printf("%d ", print->info);
        print = print->next;
    }
    printf("\n");
}

// Count the number of nodes in the list
int count()
{
    int cnt = 0;
    struct node *temp = list;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

// Search for a node in the list
void search(int x)
{
    struct node *temp = list;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->info == x)
        {
            printf("Element %d found at position %d\n", x, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", x);
}

// Reverse the linked list
void reverse()
{
    struct node *prev = NULL, *current = list, *next = NULL;
    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    list = prev; // Update head to new first node
}

// Main function
int main()
{
    int a, n = 0, boopon, pos;

    while (n != 1)
    {
        printf("Enter \n1 for insert at beginning \n2 for insert at end \n3 for insert at any point \n4 for delete at beginning \n5 for delete at end \n6 for delete at any point \n7 for display \n8 for count \n9 for search \n10 for reverse \n11 for exit: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the value to be entered: ");
            scanf("%d", &boopon);
            insert_at_beg(boopon);
            break;
        case 2:
            printf("Enter the value to be entered: ");
            scanf("%d", &boopon);
            insert_at_end(boopon);
            break;
        case 3:
            printf("Enter the value to be entered and the position to which it must be entered: ");
            scanf("%d%d", &boopon, &pos);
            insert_at_anypoint(boopon, pos);
            break;
        case 4:
            delete_at_beg();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Total number of nodes: %d\n", count());
            break;
        case 9:
            printf("Enter the value to search: ");
            scanf("%d", &boopon);
            search(boopon);
            break;
        case 10:
            reverse();
            printf("List reversed.\n");
            break;
        case 11:
            n = 1;
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
