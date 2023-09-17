#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dicionario.h"

void corrige_string(char *str);

int main(){

    setlocale(LC_ALL, "Portuguese");

    Dicionario *dc = cria_dicionario(10, sizeof(int), sizeof(char) * 30);
    int i, chave;
    char valor[30];

    for(i = 0; i < 10; i++){

        printf("Digite a matr�cula do aluno: ");
        scanf("%d", &chave);
        fflush(stdin);

        printf("Digite o nome do aluno: ");
        fgets(valor, 30, stdin);
        corrige_string(valor);
        fflush(stdin);

        adc_dicionario(dc, &chave, valor);

    }

    system("cls");
    printf("Digite a matr�cula do aluno para encontr�-lo: ");
    scanf("%d", &chave);
    fflush(stdin);

    if(consulta_dicionario(dc, &chave, valor))
        printf("\nAluno %s, com a matr�cula %d.\n", valor, chave);
    else
        puts("\nAluno n�o encontrado!");

    libera_dicionario(dc);
    return 0;

}

void corrige_string(char *str){

    if(str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

}
