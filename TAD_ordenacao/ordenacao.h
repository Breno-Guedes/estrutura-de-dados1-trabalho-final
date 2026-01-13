#ifndef TRABALHO_FINAL_ESTRUTURA_DE_DADOS_OREDENACAO_H
#define TRABALHO_FINAL_ESTRUTURA_DE_DADOS_OREDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int *dados;
    int tamanho;
} Vetor;

Vetor* criar_vetor(int tamanho);
void liberar_vetor(Vetor *v);
void preencher_aleatorio(Vetor *v);
void preencher_crescente(Vetor *v);
void preencher_decrescente(Vetor *v);
Vetor* copiar_vetor(Vetor *origem);

void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void quick_sort(int *arr, int n);

void executar_benchmark(int tamanhos[], int qtd_tamanhos, const char *arquivo_saida);

#endif