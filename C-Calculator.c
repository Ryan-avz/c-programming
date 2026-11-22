
#include <stdio.h>

float add(float num1, float num2) {
    float sum;
    sum = num1 + num2;
    printf("The result is %.2f\n", sum);
    return sum;
}

float subtract(float num1, float num2) {
    float difference;
    difference = num1 - num2;
    printf("The result is %.2f\n", difference);
    return difference;
}

float multiply(float num1, float num2) {
    float product;
    product = num1 * num2;
    printf("The result is %.2f\n", product);
    return product;
}

float divide(float num1, float num2) {
    float quotient;

    if (num2 == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }

    quotient = num1 / num2;
    printf("The result is %.2f\n", quotient);
    return quotient;
}

float confirm(float num1, float num2, char operation) {

    char answer = 'y';
    float result;

    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;

        case '-':
            result = subtract(num1, num2);
            break;

        case '*':
            result = multiply(num1, num2);
            break;

        case '/':
            result = divide(num1, num2);
            break;

        default:
            printf("Invalid operator!\n");
            return 0;
    }

    while (answer == 'y') {

        printf("Do you want to continue this operation? [y/n]\n>> ");
        scanf(" %c", &answer);

        if (answer == 'y') {

            printf("Number: ");
            scanf("%f", &num2);

            switch (operation) {
                case '+':
                    result = add(result, num2);
                    break;

                case '-':
                    result = subtract(result, num2);
                    break;

                case '*':
                    result = multiply(result, num2);
                    break;

                case '/':
                    result = divide(result, num2);
                    break;
            }
        }
    }

    return result;
}

int main() {
    int c;
    float num1, num2, result;
    char operation, answer;

    printf("Welcome to the C Calculator!!\n");
    printf("Step by step:\n");
    printf(" I - Enter any number\n");
    printf(" II - Choose the operator\n");
    printf(" III - Enter the second number\n\n");

    c = 0;

    while (c == 0) {

        char choice;

        printf("Enter 0 to continue or any other key to exit: ");
        scanf(" %c", &choice);

        if (choice != '0') {
            break;
        }

        if (c != 0) {
            break;
        }

        printf("Number: ");
        scanf("%f", &num1);

        printf("\n");
        printf("|  [+]   Addition          |\n");
        printf("|  [-]   Subtraction       |\n");
        printf("|  [*]   Multiplication    |\n");
        printf("|  [/]   Division          |\n\n");

        printf("Choose an operation: ");
        scanf(" %c", &operation);

        printf("Number 2: ");
        scanf("%f", &num2);

        switch (operation) {

            case '+':
            case '-':
            case '*':
            case '/':
                result = confirm(num1, num2, operation);
                break;

            default:
                printf("Invalid operator!\n");
                break;
        }

        printf("Do you want to perform another operation? [y/n]\n>> ");
        scanf(" %c", &answer);

        if (answer == 'n') {
            printf("Shutting down...\n");
            return 0;
        }
    }

    return 0;
}
