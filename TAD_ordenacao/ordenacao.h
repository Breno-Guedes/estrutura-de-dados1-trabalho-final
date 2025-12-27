#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura do Vetor
typedef struct {
    int *dados;
    int tamanho;
} Vetor;

// --- Gerenciamento de Vetor ---
Vetor* criar_vetor(int tamanho);
void liberar_vetor(Vetor *v);
void preencher_aleatorio(Vetor *v); // Agora só existe preenchimento aleatório
Vetor* copiar_vetor(Vetor *origem);

// --- Algoritmos de Ordenação ---
void bubble_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void merge_sort(int *arr, int n);
void quick_sort(int *arr, int n);

// --- Benchmark ---
void executar_benchmark(int tamanhos[], int qtd_tamanhos, const char *arquivo_saida);

#endif // ORDENACAO_H