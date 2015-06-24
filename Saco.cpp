/* 
 * File:   Saco.cpp
 * Author: Juan
 * 
 * Created on 14 de junio de 2015, 02:42 AM
 */

#include "Saco.h"
#include <iterator>
#include <iostream>

using namespace std;

Saco::Saco() {
}

Saco::Saco(const Saco& orig) {
    this->saco = orig.saco;
}

Saco::~Saco() {
//    cout << "Esstoy en el destructor de saco" << endl;
}

void Saco::agregaArtefacto(Artefacto*& artefacto){
    this->saco.push_back(artefacto);
}

Artefacto *Saco::sacaElemento(int pos){
    vector<Artefacto*>::iterator it;
    it = this->saco.begin();
    it += pos;
    Artefacto *art;
    art = *it;
    saco.erase(it);
    return art;
}

void Saco::imprimeElementos(){
    vector<Artefacto*>::iterator constIt;
    for(constIt = this->saco.begin(); constIt != this->saco.end(); constIt++){
        Artefacto *art = *constIt;
        art->imprimirNombre();
    }
}

Saco Saco::operator =(const Saco& bag){
    if (!this->saco.empty())
        this->saco.clear();
    this->saco = bag.saco;
    return *this;
}
int  Saco::cantidad()const{
    return this->saco.size();
}