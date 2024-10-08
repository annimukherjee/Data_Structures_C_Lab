#include <stdio.h>
#include <ctype.h>
int stack[20];
int top = -1;

void push(int x);
int pop();

int main()
{

    char exp[20];
    char *e; 
    int n1, n2, n3, num;

    printf("Enter the expression: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;  // ascii of 0 is 48, 1 is 49, 2 is 50
            push(num);
        }

        else
        {
            n1 = pop();
            n2 = pop();

            switch (*e)
            {
            case '+':
                n3 = n2 + n1;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n2 * n1;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            push(n3);
        }
        e++;
    }

    printf("\n The result of expression is: %s = %d\n\n", exp, pop());
    return 0;
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}