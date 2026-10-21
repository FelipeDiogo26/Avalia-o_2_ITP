#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int nomeVazio(const char nome[]) {
    int i;

    for (i = 0; nome[i] != '\0'; i++) {
        if (!isspace((unsigned char)nome[i])) {
            return 0;
        }
    }

    return 1;
}


void calcularMedias(float notas[10][3], int quantidade,
                    float *medias) {
    int i, j;
    float soma;

    for (i = 0; i < quantidade; i++) {
        soma = 0.0f;

        for (j = 0; j < 3; j++) {
            soma += notas[i][j];
        }

        medias[i] = soma / 3.0f;
    }
}

void exibirRelatorio(char nomes[10][50],
                     float notas[10][3],
                     float medias[],
                     int quantidade) {
    int i, j;
    float somaMedias = 0.0f;
    float maiorMedia = medias[0];

    printf("\n========== BOLETIM DA TURMA ==========\n");

    printf("%-20s %6s %6s %6s %7s  %s\n",
           "Nome", "Nota 1", "Nota 2", "Nota 3",
           "Media", "Situacao");

    for (i = 0; i < quantidade; i++) {
        printf("%-20s", nomes[i]);

        for (j = 0; j < 3; j++) {
            printf(" %6.2f", notas[i][j]);
        }

        printf(" %7.2f  ", medias[i]);

        if (medias[i] >= 6.0f) {
            printf("Atingiu a meta\n");
        } else {
            printf("Abaixo da meta\n");
        }

        somaMedias += medias[i];

        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
        }
    }

    printf("\nMedia geral da turma: %.2f\n",
           somaMedias / quantidade);

    printf("\nEstudante(s) com maior media (%.2f):\n",
           maiorMedia);

    for (i = 0; i < quantidade; i++) {
        if (maiorMedia - medias[i] < 0.0001f) {
            printf("- %s\n", nomes[i]);
        }
    }

    printf("======================================\n");
}

int main() {
    int quantidade;
    int i, j;
    int resultado;

    float notas[10][3];
    char nomes[10][50];
    float *medias;

    do {
        printf("Digite a quantidade de estudantes (1 a 10): ");

        resultado = scanf("%d", &quantidade);

        if (resultado != 1) {
            printf("Entrada invalida! Digite um numero inteiro.\n");

            while (getchar() != '\n') {
            }

            quantidade = 0;
        } else if (quantidade < 1 || quantidade > 10) {
            printf("Quantidade invalida! Tente novamente.\n");
        }

    } while (quantidade < 1 || quantidade > 10);

    getchar();

    for (i = 0; i < quantidade; i++) {
        while (1) {
            printf("Digite o nome do estudante %d: ", i + 1);

            if (fgets(nomes[i], 50, stdin) == NULL) {
                printf("Erro ao ler o nome.\n");
                return 1;
            }

            if (strchr(nomes[i], '\n') == NULL) {
                int c;

                while ((c = getchar()) != '\n' && c != EOF) {
                }

                printf("Nome muito longo! Digite ate 49 caracteres.\n");
                continue;
            }

            nomes[i][strcspn(nomes[i], "\n")] = '\0';

            if (nomeVazio(nomes[i])) {
                printf("O nome nao pode ficar vazio!\n");
            } else {
                break;
            }
        }
    }

    for (i = 0; i < quantidade; i++) {
        printf("\nNotas de %s:\n", nomes[i]);

        for (j = 0; j < 3; j++) {
            while (1) {
                printf("Digite a nota %d (0 a 10): ", j + 1);

                resultado = scanf("%f", &notas[i][j]);

                if (resultado != 1) {
                    printf("Entrada invalida! Digite um numero.\n");

                    while (getchar() != '\n') {
                    }

                    continue;
                }

                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota invalida! Use valores entre 0 e 10.\n");
                    continue;
                }

                break;
            }
        }
    }
    
    
    medias = (float *) malloc(quantidade * sizeof(float));

    if (medias == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (i = 0; i < quantidade; i++) {
        medias[i] = 0.0f;
    }

    calcularMedias(notas, quantidade, medias);


    
    printf("\n--- Boletim cadastrado ---\n");

    
    exibirRelatorio(nomes, notas, medias, quantidade);

    free(medias);
    medias = NULL;

    return 0;
}
