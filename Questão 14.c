#include <stdio.h>
#include <stdlib.h>

void ordem(float *, int);

int main()
{
    float *v;
    int i, n;

    printf("Digite o tamanho do vetor: \n");

    scanf("%d", &n);

    v = (float *) malloc( n * sizeof(float));

    printf("Digite os elementos do vetor: \n");

    for(i=0 ; i<n ; i++)
        scanf("%f", &v[i]);

    ordem(v,n);

    printf ("Vetor Ordenado:\n");

    for(i=0; i < n; i++)
        printf ("%.2f ",v[i]);

    free(v);
    return 0;
}

void ordem( float *v, int n )
{
    int j, continua, aux, final = n;

    do
    {
        continua = 0; 

        for(j=0; j < final-1; j++)
        {
            if ( v[j] > v[j+1])
            {
                aux = v[j];

                v[j] = v[j+1];

                v[j+1] = aux;

                continua = j;
            }
        }
        final--;

    }while (continua!=0);

}







