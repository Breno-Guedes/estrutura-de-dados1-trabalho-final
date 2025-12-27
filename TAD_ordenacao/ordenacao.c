#include "ordenacao.h"

// ============================================================
// GERENCIAMENTO DE VETOR
// ============================================================

Vetor* criar_vetor(int tamanho) {
    Vetor *v = (Vetor*) malloc(sizeof(Vetor));
    if (v != NULL) {
        v->tamanho = tamanho;
        v->dados = (int*) malloc(tamanho * sizeof(int));
    }
    return v;
}

void liberar_vetor(Vetor *v) {
    if (v != NULL) {
        if (v->dados != NULL) free(v->dados);
        free(v);
    }
}

// Preenche com números aleatórios
void preencher_aleatorio(Vetor *v) {
    for (int i = 0; i < v->tamanho; i++) {
        // Gera números entre 0 e tamanho*2 para ter alguma repetição mas espalhado
        v->dados[i] = rand() % (v->tamanho * 2);
    }
}

Vetor* copiar_vetor(Vetor *origem) {
    Vetor *copia = criar_vetor(origem->tamanho);
    if (copia != NULL && origem->dados != NULL) {
        memcpy(copia->dados, origem->dados, origem->tamanho * sizeof(int));
    }
    return copia;
}

// ============================================================
// ALGORITMOS DE ORDENAÇÃO
// ============================================================

// 1. Bubble Sort
void bubble_sort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 2. Insertion Sort
void insertion_sort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 3. Merge Sort
void merge_aux(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Alocação dinâmica para evitar Stack Overflow em arrays grandes na pilha
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    // Verificação de segurança
    if (!L || !R) {
        if (L) free(L);
        if (R) free(R);
        return; // Falha de memória
    }

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k++] = L[i++]; }
    while (j < n2) { arr[k++] = R[j++]; }

    free(L);
    free(R);
}

void merge_sort_recursivo(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_recursivo(arr, l, m);
        merge_sort_recursivo(arr, m + 1, r);
        merge_aux(arr, l, m, r);
    }
}

void merge_sort(int *arr, int n) {
    merge_sort_recursivo(arr, 0, n - 1);
}

// 4. Quick Sort
void quick_sort_recursivo(int *arr, int low, int high) {
    int i = low, j = high;
    int temp;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) quick_sort_recursivo(arr, low, j);
    if (i < high) quick_sort_recursivo(arr, i, high);
}

void quick_sort(int *arr, int n) {
    quick_sort_recursivo(arr, 0, n - 1);
}

// ============================================================
// BENCHMARK
// ============================================================

double medir_tempo(void (*algoritmo)(int*, int), Vetor *v) {
    clock_t inicio, fim;
    Vetor *copia = copiar_vetor(v); // Clona para não estragar o original

    inicio = clock();
    algoritmo(copia->dados, copia->tamanho);
    fim = clock();

    liberar_vetor(copia);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void executar_benchmark(int tamanhos[], int qtd_tamanhos, const char *arquivo_saida) {
    FILE *fp = fopen(arquivo_saida, "w");
    if (fp == NULL) {
        printf("Erro ao criar arquivo CSV.\n");
        return;
    }

    fprintf(fp, "Tamanho,Tempo(s),Algoritmo,Ordem\n");

    const char *nomes_algo[] = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Quick Sort"};
    void (*funcs_algo[])(int*, int) = {bubble_sort, insertion_sort, merge_sort, quick_sort};

    printf("Iniciando Benchmark...\n");
    printf("AVISO: Bubble e Insertion Sort sao lentos para valores > 100.000. Aguarde.\n");

    for (int i = 0; i < qtd_tamanhos; i++) {
        int tam = tamanhos[i];
        printf("\n--- Testando tamanho: %d ---\n", tam);

        Vetor *base = criar_vetor(tam);
        preencher_aleatorio(base);

        for (int k = 0; k < 4; k++) {
            printf("Executando %s... ", nomes_algo[k]);
            fflush(stdout);

            double tempo = medir_tempo(funcs_algo[k], base);

            printf("Concluido em %.4fs\n", tempo);

            fprintf(fp, "%d,%.6f,%s,Aleatoria\n", tam, tempo, nomes_algo[k]);
        }

        liberar_vetor(base);
    }

    fclose(fp);
    printf("\nBenchmark finalizado. Resultados em '%s'.\n", arquivo_saida);
}