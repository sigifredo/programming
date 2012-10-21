/*
 * Integrantes:
 *              - Ana Lucía Castillo Ramirez
 *              - Sigifredo Escobar Gómez
 * Grupo: 6
 */

#include<stdio.h>

int impares();

int main()
{
    #define N	9
    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Números impares: %d\n", impares(n, N));

    return 0;
}

int impares(int * v, int n)
{
    int i = 0;
    int imp = 0;

    while(i++ < n)
        if((v[i] & 1) == 1)
            imp++;

    return imp;
}

