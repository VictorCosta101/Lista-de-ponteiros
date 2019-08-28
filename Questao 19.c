#include <stdio.h>
#include <stdlib.h>

/* parametros:
 * ordem da amtriz
 * primeira e segunda matriz
 * matriz que recebe o resultado da multiplicacao*/
void multiplicar(int m,int a[m][m],int b[m][m], int **c[]);// cabecalho da funcao de multiplicacao de matrizes

int main()
{
    //definicao dos vetores  veta, vetb e vetc
    int m;
    scanf("%d",&m);
    int veta[m][m];
    int vetb[m][m];
    int **vetc;

    //alocacao de memoria prara o vetor vidimenssional vetc
    vetc = malloc(m*sizeof (int*));



    for(int i =0; i < m; i++)
    {
        vetc[i]=(int*) malloc(m*sizeof (int));
    }

// entrada de dados na matriz a

    printf("matriz a: \n");

    for(int i = 0; i < m; i++)
    {
        for (int j= 0; j < m; j ++) {


        scanf("%d", &veta[i][j]);
        }
    }

    // imprime a matriz a

    printf("matriz A: \n");
    for(int i = 0; i < m; i++)
    {
        for (int j= 0; j < m; j ++) {


        printf("%d ",(veta[i][j]));
        }
        printf("\n");
    }

    // entrada de dados na matriz b

    printf("matzri b: \n");

    for(int i = 0; i < m; i++)
    {
        for (int j= 0; j < m; j ++) {


        scanf("%d", &vetb[i][j]);
        }
    }

    //imprime a matriz b

    printf("matriz B: \n");

    for(int i = 0; i < m; i++)
    {
        for (int j= 0; j < m; j ++) {


        printf("%d ",(vetb[i][j]));
        }
        printf("\n");
    }


    multiplicar(m,veta,vetb,vetc); // chama a funcao multiplicar

    // imprime a matriz c

    printf("matriz C: \n");
    for(int i = 0; i < m; i++)
    {
        for (int j= 0; j < m; j ++) {


        printf("%d ",(vetc[i][j]));
        }
        printf("\n");
    }



    // liberar a memoria alocada para a matriz vetc

    for(int i =0; i < m; i++)
    {
        free(vetc[i]);
    }
    return 0;
}
// funcao multiplicar retorna uma matrix,
void multiplicar(int m,int  veta[m][m],int vetb[m][m],int **vetc[])
{
    int sum=0;
    for (int c = 0; c < m; c++) {
         for (int d = 0; d < m; d++) {
           for (int k = 0; k < m; k++) {
             sum = sum + ((veta[c][k])*(vetb[k][d]));

           }

           vetc[c][d] = sum;
           sum = 0;
         }
       }
}
