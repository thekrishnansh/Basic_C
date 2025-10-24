#include <stdio.h>

int main() { 
    float n1, n2;
    char oper;

    printf("Enter value of n1: ");
    scanf("%f", &n1);

    printf("Enter value of n2: ");
    scanf("%f", &n2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &oper);

    switch (oper) {
        case '+':
            printf("Result: %f\n", n1 + n2);
            break;
        case '-':
            printf("Result: %f\n", n1 - n2);
            break;
        case '*':
            printf("Result: %f\n", n1 * n2);
            break;
        case '/':
            if (n2 != 0)
                printf("Result: %f\n", n1 / n2);
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
