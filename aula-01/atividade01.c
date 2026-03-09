
#include <stdio.h>

int main() {

    float nota1[30], nota2[30], media[30];
    float soma = 0, mediaTurma;
    int i, resultado;

    for (i = 0; i < 30; i++) {

        printf("\nAluno %d\n", i + 1);

        // NOTA 1
        while (1) {

            printf("Digite a primeira nota (0 a 10): ");
            resultado = scanf("%f", &nota1[i]);

            if (resultado != 1) {
                printf("Nota invalida, por favor digite o numero novamente.\n");
                while (getchar() != '\n'); // limpa buffer
                continue;
            }

            if (nota1[i] < 0 || nota1[i] > 10) {
                printf("Nota invalida, por favor digite o numero novamente.\n");
                continue;
            }

            break;
        }

        // NOTA 2
        while (1) {

            printf("Digite a segunda nota (0 a 10): ");
            resultado = scanf("%f", &nota2[i]);

            if (resultado != 1) {
                printf("Nota invalida, por favor digite o numero novamente.\n");
                while (getchar() != '\n');
                continue;
            }

            if (nota2[i] < 0 || nota2[i] > 10) {
                printf("Nota invalida, por favor digite o numero novamente.\n");
                continue;
            }

            break;
        }

        media[i] = (nota1[i] * 2 + nota2[i] * 3) / 5;
        soma += media[i];
    }

    mediaTurma = soma / 30;

    printf("\nMedia da turma: %.2f\n", mediaTurma);

    printf("\nAlunos acima da media da turma:\n");

    for (i = 0; i < 30; i++) {

        if (media[i] > mediaTurma) {

            printf("\nAluno %d\n", i + 1);
            printf("Nota 1: %.2f\n", nota1[i]);
            printf("Nota 2: %.2f\n", nota2[i]);
            printf("Media: %.2f\n", media[i]);
        }
    }

    return 0;
}