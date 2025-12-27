#include "ordenacao.h"

int main() {
    srand((unsigned int)time(NULL));

    int tamanhos[] = {50000, 100000, 150000, 200000, 250000, 300000};
    int qtd_tamanhos = 6;

    const char *arquivo = "resultados.csv";

    executar_benchmark(tamanhos, qtd_tamanhos, arquivo);

    return 0;
}