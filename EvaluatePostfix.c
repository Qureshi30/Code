// Write a program to evaluate postfix expressions by making use of Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

int pop()
{ // Changed return type to int
    if (isEmpty())
    {
        printf("Error: Stack Underflow\n");
        exit(1); // Exit the program in case of stack underflow
    }
    return stack[top--];
}

void push(int val)
{ // Changed argument type to int
    if (isFull())
    {
        printf("Error: Stack Overflow\n");
    }
    else
    {
        stack[++top] = val;
    }
}

void evaluate_postfix(char *postfix)
{
    int val;
    int i = 0;

    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0'); // Push the integer value of the digit
        }
        else
        {
            int num1 = pop();
            int num2 = pop();

            switch (postfix[i])
            {
            case '+':
                val = num2 + num1;
                break;
            case '-':
                val = num2 - num1;
                break;
            case '*':
                val = num2 * num1;
                break;
            case '/':
                if (num1 == 0)
                {
                    printf("Error: Division by zero\n");
                    return;
                }
                val = num2 / num1;
                break;
            default:
                printf("Error: Invalid operator\n");
                return;
            }
            push(val);
        }
        i++;
    }

    printf("Final Answer = %d\n", pop());
}

int main()
{
    char string[100];
    printf("Enter Postfix: ");
    scanf("%s", string);
    evaluate_postfix(string);

    return 0;
}
