#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
#include <string.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

/* cabecalho da funcao de ordenacao, parametro n = quantidade de elementos do vetor, *v um vetor de ponteiro*/
void  ordenar (int n, float *v[]);

int compare (const void *a, const void *b){
    return ( *(int*)a - *(int*)b );
}

// funcoes para medir o tempo de execucao das funcoes de ordenamento

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        printf("QueryPerformanceFrequency Failed.\n");
    PCFreq = (double)(li.QuadPart) / 1000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return (double)(li.QuadPart - CounterStart) / PCFreq;
}

int main()
{
    // ponteiro v
    float *v;
    float *u;
    int n;

    // Qnt de lementos do vetor

    printf("Elementos do vetor: \n");

    scanf("%i", &n);

    // alocacao de memoria para o vetor v e u

    v = malloc(n*sizeof (float));
    u = malloc(n*sizeof (float));

    // insercao de n elementos no vetor v

    printf("Inserir elementos no vetor:/n ");

    for(int i = 0; i < n; i++)
    {
        scanf("%f",&v[i]);

    }

    memcpy(u,v,12);// copia do vetor v para o vetor u


    // tempo de execucao da funcao ordenar

    double tempoEmMilissegundo = 0.0000000;

    StartCounter();
    for(int i = 0; i <= 50000; i++); //trecho a ter o tempo de execução contado

    // chama a funcao ordenar para o vetor v.
    ordenar(n,v);

    tempoEmMilissegundo = GetCounter();

    printf("Tempo(func ordenar) = %.7lf milissegundos\n", tempoEmMilissegundo);

    // tempo de execucao da funcao qsort


    StartCounter();
    for(int i = 0; i <= 50000; i++); //trecho a ter o tempo de execução contado

    // chama a funcao ordenar para o vetor v.
    qsort(u, n, sizeof (float),compare);

    tempoEmMilissegundo = GetCounter();
    printf("Tempo(func qsort) = %.7lf milissegundos\n", tempoEmMilissegundo);




    // imprimir os elementos do vetor em ordem decrescente
    printf("Ordenacao  do vetor: \n");
    for(int t =0; t< n; t++)
    {
        printf("%f\n", v[t]);
    }

    // libera a memoria alocada para o vetor v
    free(v);
    free(u);

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

