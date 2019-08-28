#include <stdio.h>
#include <stdlib.h>


int main(){
    char x[4];
    short int x1[4];
    float x2[4];
    double x3[4];

    int i;
    printf("a) char: \n");

    for(i=0;i<4;i++){
        printf("x+%d:  %d \n",i,x+i);
    }

    printf("\nb) int: \n");

    for(i=0;i<4;i++){
        printf("x+%d:  %d \n",i,x1+i);
    }

    printf("\nc) float: \n");

    for(i=0;i<4;i++){
        printf("x+%d:  %d \n",i,x2+i);
    }

    printf("\nd) double: \n");

    for(i=0;i<4;i++){
        printf("x+%d:  %d  \n",i,x3+i);
    }
} 
