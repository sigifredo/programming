
#include<stdio.h>

#define N        8 //Tamaño del vector  
#define M        9 //Tamaño del vector
int v1[] = {1,2,2,4,2,4,7,1}; //Vector 1
int v2[] = {1,2,3,4,5,6,7,9,9};//Vector 2

int repetidos(int * v, int n); //Prototipo de la función

int main() //Función Principal
{
    printf("El el primer vector hay %d números repetidos\n", repetidos(v1, N)); //Muestra
    //El resultado de los elementos repetidos en el vector uno
    printf("El el segundo vector hay %d números repetidos\n", repetidos(v2, M)); //Muestra
    //El resultado de los elementos repetidos en el vector dos

    return 0; //Termina la función
}

int repetidos(int * v, int n) //Función repetidos, encuentra el número de elementos 
//repetidos en el vector
{
    int i = 0, j = 0, k, rep = 0;

    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(v[i] == v[j] && i != j)
            {
                for(k = j+1; k < n; k++)
                    if(v[i] == v[k])
                        v[k] = -1;
                rep++;
            }

    return rep; //Retorna el número de elementos repetidos en el vector. 
}
