#include <stdio.h>
#include <gc.h>


int main(void)
{
    int *p;// ponteiro para a matriz p

    int n;// n elementos

    printf("Qnt de elementos :");
    scanf("%d",&n);

    p = GC_malloc(3*sizeof(int)); //alocacao de memoria


    for(int i = 0; i < n; i++ ) // entrada de dados
    {
        scanf("%d",&p[i]);
    }

    printf(" {");
    for(int i = 0; i < n; i++ )// imprimir o vetor
    {
        printf("%d,", p[i]);
    }

    printf("}\n");

    GC_free(p);// libera a memoria alocada

    return 0;
}
