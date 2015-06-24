/* 
 * File:   Monstruo.cpp
 * Author: alulab14
 * 
 * Created on 15 de junio de 2015, 11:41 AM
 */

#include "Monstruo.h"
#include <cstdlib>

Monstruo::Monstruo() : Entidad(), ataque(0), defensa(0), nivel(1){
}

Monstruo::Monstruo(int pX, int pY, int mxVida, int vidaA, string nomb, int atk, int def, int niv) : Entidad(pX,pY,mxVida,vidaA,nomb), 
        ataque(atk), defensa(def), nivel(niv){
}

Monstruo::Monstruo(const Monstruo& orig) {
    this->ataque = orig.ataque;
    this->defensa = orig.defensa;
    this->maxVida = orig.maxVida;
    this->nombre = orig.nombre;
    this->posX = orig.posX;
    this->posY = orig.posY;
    this->vidaActual = orig.vidaActual;
    this->inventario = orig.inventario;
    this->nivel = orig.nivel;
}

Monstruo::~Monstruo() {
    this->ataque = 0;
    this->defensa = 0;
    this->nivel = 0;
}

void Monstruo::SetDefensa(int defensa) {
    this->defensa = defensa;
}

int Monstruo::GetDefensa() const {
    return defensa;
}

void Monstruo::SetAtaque(int ataque) {
    this->ataque = ataque;
}

int Monstruo::GetAtaque() const {
    return ataque;
}

void Monstruo::SetNivel(int nivel) {
    this->nivel = nivel;
}

int Monstruo::GetNivel() const {
    return nivel;
}

Monstruo Monstruo::operator =(const Monstruo& mons){
    if (this == &mons)
        return *this;
    else{
        this->ataque = mons.ataque;
        this->defensa = mons.defensa;
        this->inventario = mons.inventario;
        this->maxVida = mons.maxVida;
        this->nivel = mons.nivel;
        this->nombre = mons.nombre;
        this->posX = mons.posX;
        this->posY = mons.posY;
        this->vidaActual = mons.vidaActual;
        return *this;
    }
}

Artefacto* Monstruo::retiraArtefacto(int pos){
    this->inventario.sacaElemento(pos);
}

void Monstruo::registraArtefacto(Artefacto*& artefacto){
    this->inventario.agregaArtefacto(artefacto);
}

void Monstruo::observaSaco(){
    this->inventario.imprimeElementos();
}
int Monstruo::GetRandomPos()const{
    int size =this->inventario.cantidad();
    return rand()%size;
}

void Monstruo::recibeDanio(int danho){
    int vida = this->GetVidaActual();
    int def = this->GetDefensa();
    vida = danho - def;
    if (vida < 0) vida = 0;
    this->SetVidaActual(vida);
}