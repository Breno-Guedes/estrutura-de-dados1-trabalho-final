# 📊 Benchmark de Algoritmos de Ordenação em C

Este projeto implementa e compara o desempenho de **algoritmos clássicos de ordenação** utilizando a linguagem **C**, com foco em análise de tempo de execução para diferentes tamanhos de entrada.

Os resultados são registrados em um arquivo **CSV**, permitindo posterior visualização e comparação por meio de gráficos.

---

## 🚀 Algoritmos Implementados

O projeto contempla os seguintes algoritmos:

- 🫧 **Bubble Sort**
- ✍️ **Insertion Sort**
- 🔀 **Merge Sort**
- ⚡ **Quick Sort**

Cada algoritmo é executado sobre **vetores aleatórios**, garantindo igualdade de condições durante a medição de desempenho.

---

## 🧠 Estrutura do Projeto

- **Gerenciamento de Vetor**
  - Criação dinâmica
  - Preenchimento com valores aleatórios
  - Cópia e liberação segura de memória

- **Algoritmos de Ordenação**
  - Implementações independentes
  - Funções padronizadas para facilitar benchmarking

- **Benchmark**
  - Medição de tempo com `clock()`
  - Execução justa por meio de cópia do vetor original
  - Exportação automática dos resultados em formato CSV

---

## ⏱️ Metodologia de Benchmark

1. Um vetor base é gerado com valores aleatórios.
2. Para cada algoritmo:
   - O vetor é clonado.
   - O algoritmo é executado sobre a cópia.
   - O tempo de execução é medido.
3. Os resultados são salvos em um arquivo `.csv`.

⚠️ **Observação:**  
Bubble Sort e Insertion Sort possuem complexidade \(O(n^2)\) e podem apresentar tempos elevados para vetores muito grandes.

---

## 📁 Exemplo de Saída (CSV)

```csv
Tamanho,Tempo(s),Algoritmo,Ordem
10000,0.012345,Bubble Sort,Aleatoria
10000,0.000987,Quick Sort,Aleatoria

