/*
 * Integrantes:
 *              - Ana Lucía Castillo Ramirez
 *              - Sigifredo Escobar Gómez
 * Grupo: 6
 */

#include<stdio.h>

int mayores(int * v, int n); #prototipo de la función mayores

int main() // Función principal
{
    #define N       8 // Tamaño del vector
    int v[] = {6, 2, 3, 4, 5, 6, 7, 8}; // El vector

    printf("Los números mayores al primer elemento son: %d\n", mayores(v, N)); // Mostramos resultados
    return 0; // Fin de la función
}

int mayores(int * v, int n) // Función para encontrar los mayores al primer elemento
{
    int i = 0;
    int cont = 0;

    while(i++ < n)
        if(v[i] > v[0])
            cont++;

    return cont;
}
