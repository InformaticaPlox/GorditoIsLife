/* 
 * File:   Avatar.cpp
 * Author: Juan
 * 
 * Created on 13 de junio de 2015, 12:18 AM
 */

#include "Avatar.h"

Avatar::Avatar() : Entidad(), equip(), manaActual(100), manaMax(100){
    
}

Avatar::Avatar(int pX, int pY, int mxVida, int vidaA, string nomb, const Arma& arma, const Armadura& armadura, int manaAc, int maxMana) : Entidad(pX,pY,mxVida,vidaA,nomb), 
            equip(arma,armadura),manaActual(manaAc),manaMax(maxMana){
}

Avatar::Avatar(const Avatar& orig) {
    this->equip = orig.equip;
    this->inventario = orig.inventario;
    this->manaActual = orig.manaActual;
    this->manaMax = orig.manaMax;
    this->maxVida = orig.maxVida;
    this->nombre = orig.nombre;
    this->posX = orig.posX;
    this->posY = orig.posY;
    this->vidaActual = orig.vidaActual;
}

Avatar::~Avatar() {
    this->manaActual = 0;
    this->manaMax = 0;
//    cout << "Estoy en el destructor de Avatar" << endl;
}

void Avatar::SetManaMax(int manaMax) {
    this->manaMax = manaMax;
}

int Avatar::GetManaMax() const {
    return manaMax;
}

void Avatar::SetManaActual(int manaActual) {
    if (manaActual <= this->manaMax)
        this->manaActual = manaActual;
}

int Avatar::GetManaActual() const {
    return manaActual;
}

void Avatar::SetEquip(Equipamiento equip) {
    this->equip = equip;
}

Equipamiento Avatar::GetEquip() const {
    return equip;
}

Avatar Avatar::operator =(const Avatar& av){
    if (this == &av)
        return *this;
    else{
        this->equip = av.equip;
        this->inventario = av.inventario;
        this->manaActual = av.manaActual;
        this->manaMax = av.manaMax;
        this->maxVida = av.maxVida;
        this->nombre = av.nombre;
        this->posX = av.posX;
        this->posY = av.posY;
        this->vidaActual = av.vidaActual;
        return *this;
    }
}

void Avatar::CambiaArma(Arma& arma){
    this->equip.SetWeapon(arma);
}

Arma Avatar::obtenArma() const{
    return this->equip.GetWeapon();
}

void Avatar::CambiaArmadura(Armadura& armadura){
    this->equip.SetArmor(armadura);
}

Armadura Avatar::obtenarmadura() const{
    return this->equip.GetArmor();
}

void Avatar::recogeArtefacto(Artefacto*& artefacto){
    this->inventario.agregaArtefacto(artefacto);
}

Artefacto* Avatar::retiraArtefacto(int pos){
    this->inventario.sacaElemento(pos);
}

void Avatar::observaSaco(){
    this->inventario.imprimeElementos();
}

void Avatar::recibeDanio(int danho){
    int vida = this->GetVidaActual();
    Armadura armadura = this->obtenarmadura();
    vida = danho - armadura.GetDefensa();
    if (vida < 0) vida = 0;
    this->SetVidaActual(vida);
}

void Avatar::disminuyeMana(int tipoAtq){
    Arma arma = this->obtenArma();
    int manaAtq;
    if (tipoAtq == 1){
        Ataque atq = arma.GetAtaque1();
        manaAtq = atq.GetMana();
    }
    else{
        Ataque atq =  arma.GetAtaque2();
        manaAtq = atq.GetMana();
    }
    int mana = this->GetManaActual();
    mana = mana - manaAtq;
    this->SetManaActual(mana);
}

int Avatar::obtenDanho(int i){
    Arma arma = this->obtenArma();
    Ataque atk;
    if (i == 1)
        atk = arma.GetAtaque1();
    else
        atk = arma.GetAtaque2();
    int danho = arma.critico() + atk.GetDanio();
    return danho;
}

int Avatar::verificaMana(int tipoAtq){
    Arma arma = this->obtenArma();
    if (tipoAtq == 1){
        Ataque atk = arma.GetAtaque1();
        if (this->GetManaActual() >= atk.GetMana()) return 1;
    }
    else{
        Ataque atk = arma.GetAtaque2();
        if (this->GetManaActual() >= atk.GetMana()) return 1;
    }
    return 0;
}