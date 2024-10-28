// Write a menu driven program to implement STACK ADT using array and perform the
// following operations
// 1. PUSH
// 2. POP
// 3. DISPLAY
// 4. COUNT
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1;

void push();
void pop();
void display();
void count(); // Declaration of count function

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n");
        printf("\t\t*** Stack Operations ***\n");
        printf("\t\t1. PUSH [Insert Element]\n");
        printf("\t\t2. POP [Delete Element]\n");
        printf("\t\t3. DISPLAY [Display Stack Elements]\n");
        printf("\t\t4. COUNT [Count Elements in Stack]\n");
        printf("\t\t5. EXIT\n");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            count(); // Adding COUNT operation in the switch case
            break;

        case 5:
            printf("\nExiting the program.\n");
            return 0;

        default:
            printf("\n\nYou Entered a Wrong Choice!");
        }
    }
}

void push()
{
    int n;
    if (top == MAX - 1)
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("%d pushed into the stack\n", n);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("%d element is popped\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The elements in the stack are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void count()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("There are %d elements in the stack\n", top + 1);
    }
}
