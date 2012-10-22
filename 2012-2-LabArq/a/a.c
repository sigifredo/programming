/*
 * Integrantes:
 *              - Ana Luc�a Castillo Ramirez
 *              - Sigifredo Escobar G�mez
 * Grupo: 6
 */

#include<stdio.h>

int mayores(int * v, int n); #prototipo de la funci�n mayores

int main() // Funci�n principal
{
    #define N       8 // Tama�o del vector
    int v[] = {6, 2, 3, 4, 5, 6, 7, 8}; // El vector

    printf("Los n�meros mayores al primer elemento son: %d\n", mayores(v, N)); // Mostramos resultados
    return 0; // Fin de la funci�n
}

int mayores(int * v, int n) // Funci�n para encontrar los mayores al primer elemento
{
    int i = 0;
    int cont = 0;

    while(i++ < n)
        if(v[i] > v[0])
            cont++;

    return cont;
}
