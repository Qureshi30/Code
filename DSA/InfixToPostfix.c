// Write a program for conversion of INFIX to POSTFIX expression
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isFull()
{
    return top == MAX - 1;
}

int isEmpty()
{
    return top == -1;
}

char peek()
{
    if (isEmpty())
    {
        return -1;
    }
    char ch = stack[top];
    return (ch);
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

// 1. Check if Operand
int isOperand(char ch)
{
    // if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    // {
    //     return 1;
    // }
    // return 0;

    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

// 2. Get Precendence Level
int precedence(char ch)
{

    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

// 3. Infix to Postfix Conversion
int inf_to_post(char *expression)
{
    char result[MAX];

    //  i for input string i.e. "expression", j for output string i.e. "result"
    int i = 0, j = 0;

    while (expression[i] != '\0')
    {
        char ch = expression[i];

        if (isOperand(ch))
        {
            result[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                result[j] = pop();
                j++;
            }
            if (!isEmpty() && peek() != '(')
            {
                return -1;
            }
            else
            {
                pop();
            }
        }
        else
        {
            while (!isEmpty() && precedence(ch) <= precedence(peek()))
            {
                result[j] = pop();
                j++;
            }
            push(ch);
        }
        i++;
    }

    while (!isEmpty())
    {
        result[j] = pop();
        j++;
    }

    result[j] = '\0';

    printf("\nPostfix = %s\n", result);

    return 0;
}

int main()
{
    char string[MAX];
    printf("\nEnter Infix: ");
    scanf("%s", string);

    printf("\nInfix = %s\n", string);

    inf_to_post(string);

    return 0;
}