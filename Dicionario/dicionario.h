#ifndef DICIONARIO_H_INCLUDED
#define DICIONARIO_H_INCLUDED

typedef struct{

    void *chave;
    void *valor;

} Item;

typedef struct{

    int qtd;
    int tipo_chave;
    int tipo_valor;
    int tamanho;

    Item *dados;

} Dicionario;

Dicionario *cria_dicionario(int tamanho_dicionario, int tipo_chave, int tipo_valor);

void libera_dicionario(Dicionario *dc);

int tamanho_dicionario(Dicionario *dc);

int adc_dicionario(Dicionario *dc, const void *chave, const void *valor);

int remove_dicionario(Dicionario *dc, const void *chave);

int consulta_dicionario(Dicionario *dc, const void *chave, void *valor);

#endif // DICIONARIO_H_INCLUDED
