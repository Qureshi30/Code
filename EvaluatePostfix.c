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

char pop()
{
    if (isEmpty())
    {
        return -1;
    }
    char ch = stack[top];
    top--;
    return (ch);

    // return stack[top--];
}

void push(char ch)
{
    if (isFull())
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;

        // stack[++top] = ch;
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

            push(postfix[i] - '0');
        }
        else
        {
            int num1 = pop();
            int num2 = pop();

            if (postfix[i] == '+')
            {
                val = num1 + num2;
                push(val);
            }
            else if (postfix[i] == '-')
            {
                val = num2 - num1;
                push(val);
            }
            else if (postfix[i] == '*')
            {
                val = num1 * num2;
                push(val);
            }
            else if (postfix[i] == '/')
            {
                val = num2 / num1;
                push(val);
            }
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