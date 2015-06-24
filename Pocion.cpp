/* 
 * File:   Pocion.cpp
 * Author: Propietario
 * 
 * Created on 13 de junio de 2015, 02:49 AM
 */

#include "Pocion.h"
#include "Entidad.h"
#include "Avatar.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

Pocion::Pocion() : id(0), nombre(""), puntos(0){
    
}

Pocion::Pocion(int cod,string nomb,int pts) : id(cod),nombre(nomb),puntos(pts){
}

Pocion::Pocion(const Pocion& orig) {
    this->SetNombre(orig.GetNombre());
    this->id = orig.id;
    this->puntos = orig.puntos;
}

Pocion::~Pocion() {
    this->SetNombre("");
//    cout << "Estoy en el destructor de pocion" << endl;
}

void Pocion::SetNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Pocion::GetNombre() const {
    return nombre;
}

Pocion Pocion::operator =(const Pocion& poc){
    if (this == &poc)
        return *this;
    else{
        this->id = poc.id;
        this->nombre = poc.nombre;
        this->puntos = poc.puntos;
        return *this;
    }
}

void Pocion::SetId(int id) {
    this->id = id;
}

int Pocion::GetId() const {
    return id;
}

void Pocion::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Pocion::GetPuntos() const {
    return puntos;
}

void Pocion::imprimirNombre(){
    cout << this->nombre << endl;
}

void Pocion::usar(Avatar& heroe){
    if (this->id == 0){
        int aux = heroe.GetVidaActual();
        heroe.SetVidaActual(aux+this->puntos);
    }
    else{
        int aux = heroe.GetManaActual();
        heroe.SetManaActual(aux+this->puntos);
    }
}

char* Pocion::ObtenDescripcion(){
    char buff[200], aux[10];
    string strAux = this->GetNombre();
    strcpy(buff,strAux.c_str());
    //sprintf(aux,"%d",this->GetId());
    //strcat(buff,"/");
    //strcat(buff,aux);
    sprintf(aux,"%d",this->GetPuntos());
    strcat(buff,"/");
    strcat(buff,aux);
    char *nuevo = new char[strlen(buff)+1];
    strcpy(nuevo,buff);
    return nuevo;
}