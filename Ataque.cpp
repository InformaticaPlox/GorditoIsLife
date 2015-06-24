/* 
 * File:   Ataque.cpp
 * Author: Propietario
 * 
 * Created on 13 de junio de 2015, 01:45 AM
 */

#include "Ataque.h"
#include <iostream>
using namespace std;

Ataque::Ataque(string nombre,int danio,int mana,string descripcion):nombre(nombre),danio(danio),mana(mana),descripcion(descripcion){
}

Ataque::Ataque():nombre(""),danio(100),mana(100),descripcion("") {
}

Ataque::Ataque(const Ataque& orig){
    this->danio=orig.GetDanio();
    this->descripcion=orig.GetDescripcion();
    this->mana=orig.GetMana();
    this->nombre=orig.GetNombre();
}

Ataque::~Ataque() {
    this->danio=0;
    this->descripcion="";
    this->mana=0;
    this->nombre = "";
}

string Ataque::GetDescripcion() const {
    return descripcion;
}

int Ataque::GetMana() const {
    return mana;
}

int Ataque::GetDanio() const {
    return danio;
}

string Ataque::GetNombre() const {
    return nombre;
}

Ataque Ataque::operator =(const Ataque& atk){
    if (this == &atk){
        return *this;
    }
    else{
        this->danio = atk.GetDanio();
        this->descripcion = atk.GetDescripcion();
        this->mana = atk.GetMana();
        this->nombre = atk.GetNombre();
        return *this;
    }
}
void Ataque::SetDanio(int danio){
    this->danio=danio;
}
void Ataque::SetMana(int mana){
    this->mana=mana;
}