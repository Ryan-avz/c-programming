#include <stdio.h>


float somando (float num1, float num2) {
    float soma;
    soma = num1 + num2;
    printf("O resultado e %.2f\n", soma);
    return soma;
}

float subtraindo (float num1, float num2) {
    float subtrair;
    subtrair = num1 - num2;
    printf("O resultado e %.2f\n", subtrair);
    return subtrair;
}

float multiplicando (float num1, float num2) {
    float multiplica;
    multiplica = num1 * num2;
    printf("O resultado e %.2f\n", multiplica);
    return multiplica;
}

float dividindo (float num1, float num2) {
    float divide;
    if (num2 == 0){
        printf("Nao e possivel dividir por 0. \n");
        return 0;
    }
    
    divide = num1 / num2;
    printf("O resultado e %.2f\n", divide);
    return divide;
}

float confirmar(float num1, float num2, char operation) {

    char ask = 's';
    float result;

    switch (operation) {
        case '+':
            result = somando(num1, num2);
            break;

        case '-':
            result = subtraindo(num1, num2);
            break;

        case '*':
            result = multiplicando(num1, num2);
            break;

        case '/':
            result = dividindo(num1, num2);
            break;

        default:
            printf("Operador invalido!\n");
            return 0;
    }

    while (ask == 's') {

        printf("Deseja continuar realizando essa operacao? [s/n]\n>> ");
        scanf(" %c", &ask);

        if (ask == 's') {

            printf("Numero: ");
            scanf("%f", &num2);

            switch (operation) {
                case '+':
                    result = somando(result, num2);
                    break;

                case '-':
                    result = subtraindo(result, num2);
                    break;

                case '*':
                    result = multiplicando(result, num2);
                    break;

                case '/':
                    result = dividindo(result, num2);
                    break;
            }
        }
    }

    return result;
}


int main() {
    int c;
    float num1, num2, result;
    char operation, ask;


    printf("Bem vindo a calculadora em C!!\n");
    printf("Passo a passo: \t\n I - Digite um numero qualquer \t\n II - Escolha o operador a ser usado \t\n III - Escolha o segundo numero \t\n\n");
    c = 0;
    while (c == 0) {
        
        char escolha;

        printf("Digite 0 para prosseguir ou outra tecla para sair: ");
        scanf(" %c", &escolha);

        if (escolha != '0') {
         break;
        }
        
        if (c != 0){
            break;
        }

        printf("Numero: ");
        scanf("%f", &num1);
        
        printf("\n");
        printf("|  [+]   Adicao            |\n");
        printf("|  [-]   Subtracao         |\n");
        printf("|  [*]   Multiplicacao     |\n");
        printf("|  [/]   Divisao           |\n\n");
        printf("Escolha uma operacao: ");
        scanf(" %c", &operation);
        
        printf("Numero 2: ");
        scanf("%f", &num2);
        

        switch (operation) {

            case '+':
            case '-':
            case '*':
            case '/':
                result = confirmar(num1, num2, operation);
                break;

            default:
                printf("Operador invalido!\n");
                break;
        }
        
        printf("Deseja realizar outra operacao? [s/n]\n>> ");
        scanf(" %c", &ask);
        if ((ask != 's') || (ask != 'n')){
            printf("Shut down...");
            return 0;
        }
         
    }
    return 0;  
}
