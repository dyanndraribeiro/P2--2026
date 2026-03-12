
#include <stdio.h>

int main() {

    double nota1[30], nota2[30], media[30];
    double soma = 0, mediaTurma;
    int i, resultado;

    for (i = 0; i < 30; i++) {

        printf("\nAluno %d\n", i + 1);

        // NOTA 1
        while (1) {

            printf("Digite a primeira nota (0 a 10): ");
            resultado = scanf("%lf", &nota1[i]);

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
            resultado = scanf("%lf", &nota2[i]);

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

    printf("\nMedia da turma: %.2lf\n", mediaTurma);

    printf("\nAlunos acima da media da turma:\n");

    for (i = 0; i < 30; i++) {

        if (media[i] > mediaTurma) {

            printf("\nAluno %d\n", i + 1);
            printf("Nota 1: %.2lf\n", nota1[i]);
            printf("Nota 2: %.2lf\n", nota2[i]);
            printf("Media: %.2lf\n", media[i]);
        }
    }

    return 0;
}
