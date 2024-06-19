#include <stdio.h>
#include "zadaniya/zadanie.h"
#include <math.h>
#include <stdlib.h>


int main(void) {
    //printf("%lf\n", zadanie1(3, 58, 12));

    //zadanie2(30,30,30);

    //zadanie3(cos, 5);

    //int a[7] = {1,2,3,4,-3,-2,-1};
    //zadanie4(a,7);

    /*
    int **A = (int**)malloc(sizeof(int*) * 3);
    for(int i = 0; i < 3; i++)
        A[i] = malloc(sizeof(int) * 2);
    int L[3] = {1,1,2};
    int T[6];
    int size = zadanie5(A,L,T,3,2);
    for(int i = 0; i < size; i++) {
        printf("%d ", T[i]);
    }
    printf("\n%d ", size);

    for(int i = 0; i < 3; i++)
        free(A[i]);
    free(A);
    */

    /*
    int **A = (int**)malloc(sizeof(int*) * 4);
    for(int i = 0; i < 4; i++)
        A[i] = malloc(sizeof(int) * 3);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &A[i][j]);
    zadanie6(A, 4, 4);
    for(int i = 0; i < 4; i++)
        free(A[i]);
    free(A);
    */


    int K[3] = {5,6,7};
    zadanie7(K, 3, 8, 2);
    int Q[2] = {7,7};
    zadanie7(Q, 2, 8, 10);
}
