// Write a program to REVERSE a given string using a Stack
#include <stdio.h>

#define MAX 100 // Maximum size for the stack

// Function to reverse a string using a stack
void reverseString(char str[])
{
    char stack[MAX];
    int top = -1;
    int len = 0;

    // Manually calculate the length of the string
    while (str[len] != '\0')
    {
        len++;
    }

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++)
    {
        stack[++top] = str[i]; // Directly using top to manage the stack
    }

    // Pop characters from the stack and put them back into the string
    for (int i = 0; i < len; i++)
    {
        str[i] = stack[top--]; // Pop elements by decreasing top
    }
}

int main()
{
    char str[MAX];

    // Input the string to be reversed
    printf("Enter a string: ");
    scanf("%s", str); // Using scanf to take input (without spaces)

    printf("Original string: %s\n", str);

    // Reverse the string
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// #define MAX 100  // Maximum size for the stack

// char stack[MAX];
// int top = -1;

// // Function to push a character onto the stack
// void push(char c) {
//     if (top == MAX - 1) {
//         printf("Stack overflow\n");
//     } else {
//         top++;
//         stack[top] = c;
//     }
// }

// // Function to pop a character from the stack
// char pop() {
//     if (top == -1) {
//         printf("Stack underflow\n");
//         return '\0';  // Return null character if the stack is empty
//     } else {
//         char c = stack[top];
//         top--;
//         return c;
//     }
// }

// // Function to reverse a string using a stack
// void reverseString(char str[]) {
//     int len = strlen(str);

//     // Push all characters of the string onto the stack
//     for (int i = 0; i < len; i++) {
//         push(str[i]);
//     }

//     // Pop characters from the stack and put them back into the string
//     for (int i = 0; i < len; i++) {
//         str[i] = pop();
//     }
// }

// int main() {
//     char str[MAX];

//     // Input the string to be reversed
//     printf("Enter a string: ");
//     scanf("%s", str);  // Use scanf to take input (note that spaces will not be handled)

//     printf("Original string: %s\n", str);

//     // Reverse the string
//     reverseString(str);

//     printf("Reversed string: %s\n", str);

//     return 0;
// }
