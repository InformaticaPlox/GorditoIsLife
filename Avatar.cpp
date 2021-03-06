/* 
 * File:   Avatar.cpp
 * Author: Juan
 * 
 * Created on 13 de junio de 2015, 12:18 AM
 */

#include "Avatar.h"
#include "Ataque.h"
#include "Pocion.h"
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

Avatar::Avatar() : Entidad(),equip(),manaActual(100), manaMax(100){ 
    Ataque at1,at2;
    at1.SetDanio(50); at1.SetMana(10);at1.SetNombre("Beginner Fury");
    at2.SetDanio(40); at2.SetMana(8); at2.SetNombre("Cry of the noob");
    Arma weapon(10,20,"Noob Sword",at1,at2);
    Armadura arm(50,"The protection of the noob");
    Pocion poc_cur(0,"beginner heal",100);
    Pocion poc_mp( 1,"beginner mana",50);
    this->vidaActual=200; this->maxVida=200;
    Artefacto *art =new Pocion(poc_cur);
    this->inventario.agregaArtefacto(art); this->inventario.agregaArtefacto(art);
    Artefacto *art2 =new Pocion(poc_mp);   
    this->inventario.agregaArtefacto(art2); this->inventario.agregaArtefacto(art2);
    this->equip.SetWeapon(weapon);
    this->equip.SetArmor(arm);
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

char** Avatar::observaSaco(){
    char *buff[10];
    vector<Artefacto*>::iterator it;
    int i = 0;
    for(it = this->inventario.saco.begin(); it != this->inventario.saco.end(); it++){
        Artefacto *art = *it;
        buff[i] = new char[strlen(art->ObtenDescripcion())+1];
        strcpy(buff[i],art->ObtenDescripcion());
        i++;
    }
    char **bag = new char*[i];
    for(int j = 0 ; j < i; j++)
        bag[j] = buff[j];
    return bag;
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

int Avatar::AtkNormal() const{
    Arma arma = this->obtenArma();
    return arma.critico();
}

void Avatar::RecuperaMana(){
    this->manaActual += 80;
    if (this->manaActual > this->manaMax)
        this->manaActual = this->manaMax;
}