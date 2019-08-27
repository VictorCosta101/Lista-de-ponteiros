#include <stdio.h>
#include <stdlib.h>

void somaVetor(int v[],int u[],int z[], int x);// prototipo da função de soma vetorial

int main()
{
    // definicao dos vetore u e v
    int v [3]= {1, -4, 5};
    int u [3]= {3, 10, -3};
    int *z;// arrey de ponteiro

    z= malloc(3*sizeof (int));// alocacao de memoria para o vetor z

    somaVetor(u,v,z,3);// chamada da funcao

    // imprimir o vetor z
    for ( int i = 0; i < 3 ; i ++)
    {
        printf("%d\n", z[i]);
    }
    // liberar a alocao de memoria do vetor z
    free(z);
    return 0;
}
/* Parametros da funcao de soma vetorial
 * vetor, vetor, vetor, qnt de elementos dos vetores*/
void somaVetor(int u[], int v[], int z[], int x)
{
    for(int i = 0; i < x; i++)
    {
        z[i]=v[i]+u[i];
    }
}
