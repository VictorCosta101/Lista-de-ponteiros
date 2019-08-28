#include <stdio.h>
#include <stdlib.h>
/* cabecalho da funcao de ordenacao, parametro n = quantidade de elementos do vetor, *v um vetor de ponteiro*/
int compare (const void *a, const void *b){
  return ( *(int*)a - *(int*)b );
}
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
    qsort(v, n, sizeof (float),compare);


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
