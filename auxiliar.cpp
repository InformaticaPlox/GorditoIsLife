#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <iostream>
using namespace std;

#include "auxiliar.h"

int* crearArregloIndices(int cant){ 
    int i, j, a, b, aleatorio; 

    int *arreglo = new int[cant]; 

    for(j=0;j<cant;++j) arreglo[j]=-1; 

    /* Conseguimos una semilla */ 
    srand(time(NULL)); 

    /* Usamos la función para obtener números */ 
    for(i=0;i<cant;i++){ 
        aleatorio=alea(0,cant-1); 
        for(j=0;j<cant;++j){ 
            if(arreglo[j] == aleatorio){ 
                aleatorio = alea(0,cant-1); 
                j=-1; 
            } 
            else if(arreglo[j]==-1){ 
                arreglo[j] = aleatorio; 
                break; 
            } 
        } 
        printf("%i\n", arreglo[i]); 
        //getchar(); 
    } 
    arreglo[0] = 9;
    arreglo[7] = 8;
    return arreglo; 
} 


int alea(int desde, int hasta){  
    return rand()%(hasta-desde+1)+desde; 
} 


double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}