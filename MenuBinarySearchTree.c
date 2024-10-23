// Write a menu driven program to implement following operations in a binary search tree
// (BST).
// 1. Insertion of node
// 2. Preorder Traversal
// 3. Postorder Traversal
// 4. Inorder Traversal
// 5. Search node in the tree

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function for Preorder Traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Postorder Traversal
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function for Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to search for a node in the BST
Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to display menu and handle user choices
void menu()
{
    Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\n*** Binary Search Tree Operations ***\n");
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Search Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &data);
            Node *result = search(root, data);
            if (result != NULL)
            {
                printf("%d found in the tree.\n", data);
            }
            else
            {
                printf("%d not found in the tree.\n", data);
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

// Main function
int main()
{
    menu();
    return 0;
}
