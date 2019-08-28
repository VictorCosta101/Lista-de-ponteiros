#include <stdio.h>
#include <stdlib.h>
/* cabecalho da funcao de ordenacao, parametro n = quantidade de elementos do vetor, *v um vetor de ponteiro*/
void  ordenar (int n, float *v[]);
int main()
{
    // ponteiro v
    float *v;
    int n;

    // Qnt de lementos do vetor
    printf("Elementos do vetor: \n");
    scanf("%i", &n);

    // alocacao de memoria para o vetor v
    v = malloc(n*sizeof (float));

    // insercao de n elementos no vetor
    printf("Inserir elementos no vetor: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%f",&v[i]);

    }


    // chama a funcao ordenar para o vetor v.
    ordenar(n,v);


    // imprimir os elementos do vetor em ordem crescente
    printf("Ordenacao  do vetor: \n");
    for(int t =0; t< n; t++)
    {
        printf("%f\n", v[t]);
    }

    // libera a memoria alocada para o vetor v
    free(v);

    return 0;
}


// funcao de ordenacao
void  ordenar (int n, float *v[])
{
    for (int i = 0; i < n-1; ++i) {
        int min = i; // indice do menor elemento pertencente a v
        for (int j = i+1; j < n; ++j)
            if (*(v+j)< *(v+min))  min = j;
        int x = *(v+i); *(v+i) = *(v+min); *(v+min) = x; // mudaca de posicao dos elementos
    }

}
