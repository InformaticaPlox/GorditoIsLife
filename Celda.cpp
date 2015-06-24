/* 
 * File:   Celda.cpp
 * Author: HP
 * 
 * Created on 14 de junio de 2015, 04:01 AM
 */

#include "Celda.h"

Celda::Celda():tipo(0) {
}

Celda::Celda(int celda):tipo(celda){    
}

Celda::Celda(const Celda& orig) {
}

Celda::~Celda() {
    this->tipo = 0;
}

void Celda::SetTipo(int tipo) {
    this->tipo = tipo;
}

int Celda::GetTipo() const {
    return tipo;
}

