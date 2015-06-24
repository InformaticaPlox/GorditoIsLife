/* 
 * File:   Armadura.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 12:00 PM
 */

#include "Armadura.h"
#include "Avatar.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

Armadura::Armadura(int def, string nomb):defensa(def),nombre(nomb){
    
}

Armadura::Armadura():defensa(0),nombre(""){
    
}

Armadura::Armadura(const Armadura& orig) {
    this->defensa = orig.defensa;
    this->nombre = orig.nombre;
}

Armadura::~Armadura() {
    this->defensa = 0;
    this->nombre = "";
//    cout << "Estoy en el destructor de armadura" << endl;
}

void Armadura::SetDefensa(int defensa) {
    this->defensa = defensa;
}

int Armadura::GetDefensa() const {
    return defensa;
}

void Armadura::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Armadura::GetNombre() const {
    return nombre;
}

Armadura Armadura::operator =(const Armadura& armor){
    if (this == &armor)
        return *this;
    else{
        this->defensa = armor.defensa;
        this->nombre = armor.nombre;
        return *this;
    }
}

void Armadura::imprimirNombre(){
    cout << this->nombre << endl;
}

void Armadura::usar(Avatar& heroe){
    Artefacto *art = new Armadura(heroe.obtenarmadura());
    heroe.CambiaArmadura(*this);
    heroe.recogeArtefacto(art);
}

char* Armadura::ObtenDescripcion(){
    char buff[200], aux[10];
    string strAux = this->GetNombre();
    strcpy(buff,strAux.c_str());
    strcat(buff,"/");
    sprintf(aux,"%d",this->GetDefensa());
    strcat(buff,aux);
    char *nuevo = new char[strlen(buff)+1];
    strcpy(nuevo,buff);
    return nuevo;
}