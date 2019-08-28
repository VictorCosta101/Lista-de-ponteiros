#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicacao(int **A, int **B, int **C, int nl, int nc, int nco);

void plotmatriz (int **A, int **B, int **C, int nl, int nc, int nco);

int main()
{
   int **A, **B, **C, nl, nc, nco;
   
   srand(time(NULL));
      
   printf("Digite o numero de linhas e o numero de colunas da matriz A\n");
   
   scanf("%d\n%d", &nl, &nc);
   
   printf("Digite o numero de colunas da matriz B\n");
   
   scanf("%d", &nco);
 
   A = (int**)malloc(nl*sizeof(int));
   
   B = (int**)malloc(nc*sizeof(int));
   
   C = (int**)malloc(nco*sizeof(int));

   int i , j;

   for(i=0; i<nl; i++){
   	
       A[i]=(int*) malloc(nc*sizeof(int));
       
   }
   for(i=0; i<nc; i++){
   	
       B[i]=(int*) malloc(nco*sizeof(int)); 
   }
   for(i=0; i<nl; i++){
   	
       C[i]=(int*) malloc(nco*sizeof(int));
   }


   for(i=0; i<nl; i++){
   	
       for(j=0; j<nc; j++){
       	
         A[i][j] = rand()%30;
       }
    }

   for(i=0; i<nc; i++){
   	
       for(j=0; j<nco; j++){
       	
         B[i][j] = rand()%30;
       }
    }
      
   multiplicacao(A,B,C,nl,nc,nco);
   
   plotmatriz (A,B,C,nl,nc,nco);
   
    for (i=0;i<nl;i++) {
   	
   	   free(A[i]);
   }
   for (i=0;i<nc;i++) {
   	
       free(B[i]);
   }
   for (i=0;i<nco;i++) {
   	
       free(C[i]);
   }

   free(A);
   free(B);
   free(C);

   return 0;
}

void multiplicacao(int **A, int **B, int **C, int nl, int nc, int nco){
	
   int i, j , n , soma=0;
   
   for(i = 0; i < nl; i++){
       for(j = 0; j < nco; j++){
           C[i][j] = 0;
           soma = 0;
           for(n=0; n< nc; n++){
               soma = soma + A[i][n]*B[n][j];
           }
               C[i][j] = soma;
         }
    }
}

void plotmatriz (int **A, int **B, int **C, int nl, int nc, int nco){

  int i,j;
  
   printf("\nMatriz A\n");
    
   for(i=0; i<nl; i++){
   	
       for(j=0; j<nc; j++){
       	
           printf("%d ", A[i][j]);
       }
       printf("\n");
   }

     printf("\nMatriz B\n");
     
   for(i=0; i<nl; i++){
   	
       for(j=0; j<nc; j++){
       	
           printf("%d ", B[i][j]);
       }
       printf("\n");
   }

   printf("\nMatriz C\n");
   
   for(i=0; i<nl; i++){
   	
       for(j=0; j<nc; j++){
       	
           printf("%d ", C[i][j]);
       }
       printf("\n");
   }
}
