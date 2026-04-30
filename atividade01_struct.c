#include <stdio.h>

#define NUM_ALUNOS 30

struct Aluno {
    float nota1;
    float nota2;
    float media;
};

void lerNotas(struct Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("  Nota 2: ");
        scanf("%f", &alunos[i].nota2);
    }
}

void calcularMedias(struct Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        alunos[i].media = (alunos[i].nota1 * 2 + alunos[i].nota2 * 3) / 5.0f;
    }
}

float calcularMediaTurma(struct Aluno alunos[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }
    return soma / n;
}

void imprimirAcimaMedia(struct Aluno alunos[], int n, float mediaTurma) {
    printf("\nMedia da turma: %.2f\n", mediaTurma);
    printf("\nAlunos acima da media da turma:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Aluno", "Nota 1", "Nota 2", "Media");
    printf("------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (alunos[i].media > mediaTurma) {
            printf("%-10d %-10.2f %-10.2f %-10.2f\n",
                   i + 1, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
        }
    }
}

int main() {
    struct Aluno alunos[NUM_ALUNOS];

    lerNotas(alunos, NUM_ALUNOS);
    calcularMedias(alunos, NUM_ALUNOS);

    float mediaTurma = calcularMediaTurma(alunos, NUM_ALUNOS);

    imprimirAcimaMedia(alunos, NUM_ALUNOS, mediaTurma);

    return 0;
}