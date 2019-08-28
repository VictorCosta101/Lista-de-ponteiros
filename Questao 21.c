#include <stdio.h>
#include<windows.h>
#include<stdlib.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

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
    int *p;// ponteiro para a matriz p
    int *v;// ponteiro para a matriz v
    int *z;// ponteiro para a matriz v
    int *y;// ponteiro para a matriz v

    int n;// n elementos

    printf("Qnt de elementos :");
    scanf("%d",&n);

    // tempo de execucao da funcao GC_malloc

    double tempoEmMilissegundo = 0.0000000;


    StartCounter();
    for(int i = 0; i <= 50000; i++); //trecho a ter o tempo de execução contado

    p = GC_malloc(3*sizeof(int)); //alocacao de memoria
    v = GC_malloc(3*sizeof(int)); //alocacao de memoria

    tempoEmMilissegundo = GetCounter();

    printf("Tempo(func GC_malloc) = %.7lf milissegundos\n", tempoEmMilissegundo);


    //Tempo de execucao da funcao malloc:

    StartCounter();
    for(int i = 0; i <= 50000; i++); //trecho a ter o tempo de execução contado

    z = malloc(3*sizeof(int)); //alocacao de memoria
    y =malloc(3*sizeof(int)); //alocacao de memoria

    tempoEmMilissegundo = GetCounter();

    printf("Tempo(func Malloc) = %.7lf milissegundos\n", tempoEmMilissegundo);


    for(int i = 0; i < n; i++ ) // entrada de dados
    {
        scanf("%d",&p[i]);
    }

    for(int i = 0; i < n; i++ ) // entrada de dados
    {
        scanf("%d",&v[i]);
    }
    //libera memoria alocada para os vetores
   GC_free(p);
   GC_free(v);
   free(z);
   free(y);

    return 0;
}
