#include <string.h>
#include <stdlib.h>
#include "dicionario.h"

Dicionario *cria_dicionario(int tamanho_dicionario, int tipo_chave, int tipo_valor){

    Dicionario *dc;
    dc = (Dicionario *)malloc(sizeof(Dicionario));

    if(dc != NULL){

        dc -> tamanho = tamanho_dicionario;
        dc -> tipo_chave = tipo_chave;
        dc -> tipo_valor = tipo_valor;
        dc -> dados = (Item *)malloc(sizeof(Item) * tamanho_dicionario);
        if(dc -> dados == NULL){

            free(dc);
            return NULL;

        }
        dc -> qtd = 0;

    }

    return dc;

}

void libera_dicionario(Dicionario *dc){

    if(dc != NULL){

        int i;
        for(i = 0; i < dc -> qtd; i++){

            free(dc -> dados[i].chave);
            free(dc -> dados[i].valor);

        }
        free(dc -> dados);
        free(dc);

    }

}

int tamanho_dicionario(Dicionario *dc){

    if(dc == NULL)
        return -1;

    return (dc -> qtd);

}

int adc_dicionario(Dicionario *dc, const void *chave, const void *valor){

    if(dc == NULL || tamanho_dicionario(dc) == dc -> tamanho)
        return 0;

    dc -> dados[dc -> qtd].chave = malloc(dc -> tipo_chave);
    dc -> dados[dc -> qtd].valor = malloc(dc -> tipo_valor);

    memcpy(dc -> dados[dc -> qtd].chave, chave, dc -> tipo_chave);
    memcpy(dc -> dados[dc -> qtd].valor, valor, dc -> tipo_valor);
    dc -> qtd++;

    return 1;

}

int remove_dicionario(Dicionario *dc, const void *chave){

    if(dc == NULL || tamanho_dicionario(dc) == 0)
        return 0;

    int i, j;
    for(i = 0; i < dc -> qtd; i++){

        if(memcmp(chave, dc -> dados[i].chave, dc -> tipo_chave) == 0)
            break;

    }

    for(j = i; j < (dc -> qtd) - 1; j++)
        dc -> dados[j] = dc -> dados[j + 1];
    dc -> qtd--;

    return 1;

}

int consulta_dicionario(Dicionario *dc, const void *chave, void *valor){

    if(dc == NULL || tamanho_dicionario(dc) == 0)
        return 0;

    int i;
    for(i = 0; i < dc -> qtd; i++){

        if(memcmp(chave, dc -> dados[i].chave, dc -> tipo_chave) == 0){

            memcpy(valor, dc -> dados[i].valor, dc -> tipo_valor);
            return 1;

        }

    }

    return 0;

}
