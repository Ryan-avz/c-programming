#include <stdio.h>

float calculate(float numbers[], int quantity, int operation) {
    float result;

    if (operation == 1) {
        result = 0;
        for (int i = 0; i < quantity; i++) {
            result += numbers[i];
        }
    }
    else if (operation == 2) {
        result = numbers[0];
        for (int i = 1; i < quantity; i++) {
            result -= numbers[i];
        }
    }
    else if (operation == 3) {
        result = 1;
        for (int i = 0; i < quantity; i++) {
            result *= numbers[i];
        }
    }
    else if (operation == 4) {
        result = numbers[0];
        for (int i = 1; i < quantity; i++) {
            result /= numbers[i];
        }
    }
    else {
        printf("Invalid operation.\n");
        return 0;
    }

    return result;
}

int main() {
    int quantity, operation;

    printf("Choose an operation:\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Division\n");
    printf(">> ");
    scanf("%d", &operation);

    printf("Enter the number of values: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("The quantity must be greater than zero.\n");
        return 1;
    }

    float numbers[quantity];

    for (int i = 0; i < quantity; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &numbers[i]);
    }

    if (operation == 4) {
        for (int i = 1; i < quantity; i++) {
            if (numbers[i] == 0) {
                printf("Error: division by zero is not allowed.\n");
                return 1;
            }
        }
    }

    printf("Result: %.2f\n", calculate(numbers, quantity, operation));

    return 0;
}
