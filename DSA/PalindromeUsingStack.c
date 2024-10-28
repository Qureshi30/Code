// Write a program to check if a given number is a PALLINDROME using a stack
#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Max digits in the number

// Define the stack structure
struct Stack
{
    int top;
    int array[MAX];
};

// Initialize the stack
void initStack(struct Stack *stack)
{
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack *stack, int item)
{
    if (stack->top < MAX - 1)
        stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(struct Stack *stack)
{
    if (stack->top >= 0)
        return stack->array[stack->top--];
    return -1; // Error value
}

// Function to check if a number is a palindrome using a stack
int isPalindrome(int number)
{
    struct Stack stack;
    initStack(&stack);
    int original = number;

    // Push digits onto the stack
    while (number > 0)
    {
        push(&stack, number % 10);
        number /= 10;
    }

    // Compare digits with the original number
    while (original > 0)
    {
        if (pop(&stack) != original % 10)
            return 0; // Not a palindrome
        original /= 10;
    }

    return 1; // Is a palindrome
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a palindrome.\n", number);
    else
        printf("%d is not a palindrome.\n", number);

    return 0;
}
