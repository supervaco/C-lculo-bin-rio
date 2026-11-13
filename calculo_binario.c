#include <stdio.h>

#define NAO_ENCONTRADO -1

/*
 * Busca binária em um vetor ORDENADO de forma crescente.
 *
 * Ideia: a cada passo, olha o elemento do meio e descarta metade do vetor.
 *   - Se o palpite for menor que o alvo -> o alvo está na metade direita.
 *   - Se o palpite for maior que o alvo -> o alvo está na metade esquerda.
 *
 * Parâmetros:
 *   vetor   -> vetor ordenado onde vamos procurar
 *   tamanho -> quantidade de elementos do vetor
 *   alvo    -> valor que estamos procurando
 *
 * Retorno: o ÍNDICE onde o alvo está, ou NAO_ENCONTRADO (-1) se ele não existir.
 */
int busca_binaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0;            // índice do começo da região de busca
    int fim = tamanho - 1;     // índice do fim da região de busca
    int meio = 0;              // índice do elemento do meio
    int palpite = 0;           // valor que está na posição 'meio'
    int iteracao = 0;          // contador só para acompanhar os prints

    printf("\nAntes do loop:\n");
    printf("Inicio  -> %d (indice)\n", inicio);
    printf("Fim     -> %d (indice)\n", fim);
    printf("Meio    -> %d (indice)\n", meio);
    printf("Palpite -> %d (valor do elemento)\n", palpite);

    // Enquanto ainda existir região para procurar
    while (inicio <= fim) {
        iteracao++;

        // Calcula o meio (forma que evita estouro de int em vetores gigantes)
        meio = inicio + (fim - inicio) / 2;
        palpite = vetor[meio];

        printf("\nIteracao %d:\n", iteracao);
        printf("Meio    -> %d (indice)\n", meio);
        printf("Palpite -> %d (valor do elemento)\n", palpite);

        if (palpite == alvo) {
            // Achou! Devolve a posição.
            return meio;
        } else if (palpite < alvo) {
            // Alvo é maior: descarta a metade esquerda (incluindo o meio)
            inicio = meio + 1;
        } else {
            // Alvo é menor: descarta a metade direita (incluindo o meio)
            fim = meio - 1;
        }

        printf("Inicio  -> %d (indice)\n", inicio);
        printf("Fim     -> %d (indice)\n", fim);
    }

    // A região de busca acabou sem encontrar o alvo
    return NAO_ENCONTRADO;
}

int main() {
    int tamanho = 0;   // quantidade de elementos do vetor
    int alvo = 0;      // número que o usuário quer procurar

    // --- Entrada: tamanho do vetor ---
    printf("Escolha o tamanho de seu array:\n");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("O tamanho precisa ser maior que zero.\n");
        return 1;
    }

    // --- Monta o vetor ordenado: {1, 2, 3, ..., tamanho} ---
    int vetor[tamanho];
    int *ponteiroVetor = vetor;
    for (int i = 0; i < tamanho; i++) {
        *(ponteiroVetor + i) = i + 1;
    }

    // --- Entrada: número a ser procurado ---
    printf("Escolha o seu número alvo:\n");
    scanf("%d", &alvo);

    // --- Busca ---
    int posicao = busca_binaria(vetor, tamanho, alvo);

    // --- Saída ---
    printf("\n");
    if (posicao != NAO_ENCONTRADO) {
        printf("O número foi encontrado na lista (indice %d)\n", posicao);
    } else {
        printf("O número não foi encontrado na lista\n");
    }

    return 0;
}
