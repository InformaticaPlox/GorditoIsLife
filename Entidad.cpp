/* 
 * File:   Entidad.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 04:50 PM
 */

#include "Entidad.h"
#include <iostream>

Entidad::Entidad() : posX(0),posY(0),maxVida(0),vidaActual(0),nombre(""){
}

Entidad::Entidad(int pX, int pY, int maxLife, int actualLife, string name) : posX(pX),posY(pY),maxVida(maxLife),vidaActual(actualLife),nombre(name){    
}

Entidad::Entidad(const Entidad& orig) {
    this->posX = orig.posX;
    this->posY = orig.posY;
    this->maxVida = orig.maxVida;
    this->vidaActual = orig.vidaActual;
    this->nombre = orig.nombre;
}

Entidad::~Entidad() {
    this->posX = 0;
    this->posY = 0;
    this->maxVida = 0;
    this->vidaActual = 0;
    this->nombre = "";
}

void Entidad::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Entidad::GetNombre() const {
    return nombre;
}

void Entidad::SetVidaActual(int vidaActual) {
    if (vidaActual <= this->maxVida && vidaActual > 0)
        this->vidaActual = vidaActual;
}

int Entidad::GetVidaActual() const {
    return vidaActual;
}

void Entidad::SetMaxVida(int maxVida) {
    this->maxVida = maxVida;
}

int Entidad::GetMaxVida() const {
    return maxVida;
}

void Entidad::SetPosY(int posY) {
    this->posY = posY;
}

int Entidad::GetPosY() const {
    return posY;
}

void Entidad::SetPosX(int posX) {
    this->posX = posX;
}

int Entidad::GetPosX() const {
    return posX;
}

void Entidad::imprimePosACtual(){
    cout << '(' << this->posX << ':' << this->posY << ')' << endl;
}

Entidad Entidad::operator =(const Entidad& ent){   
}