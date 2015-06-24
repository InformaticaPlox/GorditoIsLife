/* 
 * File:   Dibujador.cpp
 * Author: Juan
 * 
 * Created on 6 de junio de 2015, 09:32 PM
 */

#include "graficos.h"
#include <iostream>
#include "Dibujador.h"
#include "Laberinto.h"
#define TAM 50

using namespace std;

Dibujador::Dibujador(int valA,int valB) {
    this->SetA(valA);
    this->SetB(valB);
}

void Dibujador::SetB(int B) {
    this->B = B;
}

int Dibujador::GetB() const {
    return B;
}

void Dibujador::SetA(int A) {
    this->A = A;
}

int Dibujador::GetA() const {
    return A;
}

Dibujador::Dibujador(const Dibujador& orig) {
    this->A = orig.A;
    this->B = orig.B;
}

Dibujador::~Dibujador() {
    this->A = 0;
    this->B = 0;
}

void Dibujador::Dibuja(int posX, int posY,int limFil,int limCol,const Laberinto& lab,const graficos& graf){
    int **matriz;
    matriz =new int*[lab.GetM()];
    for(int i=0;i<lab.GetM();i++)
        matriz[i]=new int[lab.GetN()];
    for(int i=0;i<lab.GetM();i++){
            for(int j=0;j<lab.GetN();j++){
                matriz[i][j]=lab(i,j).GetTipo();
                cout<<matriz[i][j];
            }
            cout<<endl;
    }
    graf.Dibujar(posX,this->B,posY,this->A,limFil,limCol,matriz);
    delete[] matriz;
   
}

