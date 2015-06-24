/* 
 * File:   Artefacto.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 05:41 PM
 */

#include "Artefacto.h"
#include <iostream>

using namespace std;

Artefacto::Artefacto() {    
}

Artefacto::~Artefacto(){
}
Artefacto Artefacto::operator =(const Artefacto& artefacto){    
}

void Artefacto::imprimirNombre(){    
}

void Artefacto::setCoordY(int coordY) {
    this->coordY = coordY;
}

int Artefacto::getCoordY() const {
    return coordY;
}

void Artefacto::setCoordX(int coordX) {
    this->coordX = coordX;
}

int Artefacto::getCoordX() const {
    return coordX;
}

void Artefacto::usar(Avatar& heroe){    
}

char* Artefacto::ObtenDescripcion(){
}