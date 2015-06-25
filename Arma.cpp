/* 
 * File:   Arma.cpp
 * Author: alulab14
 * 
 * Created on 12 de junio de 2015, 11:50 AM
 */

#include "Arma.h"
#include "Avatar.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

Arma::Arma(int min, int max, string nomb,const Ataque& ataque1,const Ataque& ataque2):danhoMin(min),danhoMax(max),
        nombre(nomb),ataque1(ataque1),ataque2(ataque2){   
}

Arma::Arma():danhoMin(0),danhoMax(0),nombre(""),ataque1(),ataque2(){    
}

Arma::Arma(const Arma& orig) {
    this->danhoMin = orig.danhoMin;
    this->danhoMax = orig.danhoMax;
    this->nombre = orig.nombre;
    this->ataque1 = orig.ataque1;
    this->ataque2 = orig.ataque2;
}

Arma::~Arma() {  
    this->danhoMax = 0;
    this->danhoMin = 0;
    this->nombre = "";
}

void Arma::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Arma::GetNombre() const {
    return nombre;
}

void Arma::SetDanhoMax(int danhoMax) {
    this->danhoMax = danhoMax;
}

int Arma::GetDanhoMax() const {
    return danhoMax;
}

void Arma::SetDanhoMin(int danhoMin) {
    this->danhoMin = danhoMin;
}

int Arma::GetDanhoMin() const {
    return danhoMin;
}
int Arma::critico()const{
    int critico = rand()%(this->GetDanhoMax()-this->GetDanhoMin()+1)+this->GetDanhoMin();
    return critico;
}

Ataque Arma::GetAtaque2() const {
    return ataque2;
}

Ataque Arma::GetAtaque1() const {
    return ataque1;
}

Arma Arma::operator =(const Arma& arma){
    if (this == &arma)
        return *this;
    else{
        this->nombre = arma.nombre;
        this->danhoMin = arma.danhoMin;
        this->danhoMax = arma.danhoMax;
        this->ataque1 = arma.ataque1;
        this->ataque2 = arma.ataque2;
        return *this;
    }
}

void Arma::imprimirNombre(){
    cout << this->nombre << endl;
}

void Arma::usar(Avatar& heroe){
    Artefacto *art = new Arma(heroe.obtenArma());
    
    heroe.CambiaArma(*this);
    heroe.recogeArtefacto(art);
}

char* Arma::ObtenDescripcion(){
    char buff[200], aux[10];
    string strAux = this->GetNombre();
    strcpy(buff,strAux.c_str());
    strcat(buff,"/"); sprintf(aux,"%d",this->GetDanhoMax()); strcat(buff,aux);
    strcat(buff,"/"); sprintf(aux,"%d",this->GetDanhoMin()); strcat(buff,aux);
    
    char *nuevo = new char[strlen(buff)+1];
    strcpy(nuevo,buff);
    return nuevo;
}