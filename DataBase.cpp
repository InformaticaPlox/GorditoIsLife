/* 
 * File:   DataBase.cpp
 * Author: JuanI
 * 
 * Created on 21 de junio de 2015, 05:54 AM
 */

#include "DataBase.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#define NUMFILE 10
#define PORCENTAJEAUMENTO 0.6
#define NUMARTEFACTOS 5
using namespace std;

DataBase::DataBase() {
    ifstream input("basedatos\\data_base.txt",ios::in);
    if(input){
        char buffLinea[500];
        input.getline(buffLinea,500,'\n'); //==Monstruos==
        while(1){
            input.getline(buffLinea,500,'\n');
            if(strcmp(buffLinea,"===Armas===")==0) break;
            this->SetMonstruo(buffLinea); 
        }
        while(1){
            input.getline(buffLinea,500,'\n');
            if(strcmp(buffLinea,"===Pociones===")==0)break;
            this->SetArmas(buffLinea);
        }
        while(1){
            input.getline(buffLinea,500,'\n');
            if(strcmp(buffLinea,"===Armaduras===")==0)break;
            this->SetPocimas(buffLinea);
        }
        while(input.getline(buffLinea,500,'\n')){
            this->SetArmaduras(buffLinea);
        }   
    }
    input.close();
}

DataBase::~DataBase() {
}

Artefacto *DataBase::devuelve_artefacto(int* niveles){
    int min,max;
    this->rangoNiveles(niveles,min,max);
    int nivelRandom =rand()%(max-min)+1;
    int opcion =rand()%3;
    if(opcion==0){ //Es una armadura
        int size=this->armaduras.size();
        int index=rand()%size;
        Armadura arm =this->armaduras[index];
        arm.SetDefensa(arm.GetDefensa()*nivelRandom*PORCENTAJEAUMENTO);
        Artefacto *art =new Armadura(arm);
        return art;
    }
    else if(opcion==1){ //Arma
        int size =this->armas.size();
        int index =rand()%size;
        Arma weapon=this->armas[index];
        weapon.SetDanhoMax(weapon.GetDanhoMax()*nivelRandom*PORCENTAJEAUMENTO); weapon.SetDanhoMin(weapon.GetDanhoMin()*nivelRandom*PORCENTAJEAUMENTO);
        weapon.GetAtaque1().SetDanio(weapon.GetAtaque1().GetDanio()*nivelRandom*PORCENTAJEAUMENTO); weapon.GetAtaque2().SetDanio(weapon.GetAtaque2().GetDanio()*nivelRandom*PORCENTAJEAUMENTO);
        weapon.GetAtaque1().SetMana(weapon.GetAtaque1().GetMana()*nivelRandom*PORCENTAJEAUMENTO); weapon.GetAtaque2().SetMana(weapon.GetAtaque2().GetMana()*nivelRandom*PORCENTAJEAUMENTO);
        Artefacto *art=new Arma(weapon);
        return art;
    }
    else{
        int size=this->pociones.size();
        int index=rand()%size;
        Pocion pocion=this->pociones[index];
        pocion.SetPuntos(pocion.GetPuntos()*nivelRandom*PORCENTAJEAUMENTO);
        Artefacto *art=new Pocion(pocion);
        return art; 
    }
}

Monstruo DataBase::devuelve_monstruo(int* niveles){
    int min,max;
    this->rangoNiveles(niveles,min,max);
    int nivelRandom =rand()%(max-min)+1;
    int size = this->monstruos.size();
    int index =rand()% size;
    Monstruo mon =this->monstruos[index];
    mon.SetAtaque(mon.GetAtaque()*nivelRandom*PORCENTAJEAUMENTO); 
    mon.SetDefensa(mon.GetDefensa()*nivelRandom*PORCENTAJEAUMENTO);
    mon.SetMaxVida(mon.GetMaxVida()*nivelRandom*PORCENTAJEAUMENTO);
    mon.SetNivel(nivelRandom); 
    mon.SetVidaActual(mon.GetMaxVida());
    for(int i=0;i<NUMARTEFACTOS;i++){
        Artefacto *art=this->devuelve_artefacto(niveles);
        mon.registraArtefacto(art);
    }
    return mon;
}
void DataBase::SetMonstruo(char* buffLinea){
    Monstruo mon;
    string nombre = strtok(buffLinea," \t");
    int ataque =atoi(strtok(NULL," \t"));
    int defensa =atoi(strtok(NULL," \t"));
    mon.SetNombre(nombre);mon.SetAtaque(ataque);mon.SetDefensa(defensa);
    this->monstruos.push_back(mon);
}
void DataBase::SetArmas   (char* buffLinea){
    string nombre= strtok(buffLinea,"/");
    int ataqMax =atoi(strtok(NULL,"/"));
    int ataqMin=atoi (strtok(NULL,"/"));
    string nombAt1=strtok(NULL,"/");
    int danio1=atoi(strtok(NULL,"/"));
    int mana1 =atoi(strtok(NULL,"/"));
    string nombAt2=strtok(NULL,"/");
    int danio2=atoi(strtok(NULL,"/"));
    int mana2 =atoi(strtok(NULL,"/"));
    Ataque ata1(nombAt1,danio1,mana1);
    Ataque ata2(nombAt2,danio2,mana2);
    Arma weapon(ataqMin,ataqMax,nombre,ata1,ata2);
    this->armas.push_back(weapon);    
}
void DataBase::SetPocimas (char* buffLinea){
    int tipo=atoi(strtok(buffLinea,"/"));
    string nombre =strtok(NULL,"/");
    int cantidad =atoi(strtok(NULL,"/"));
    Pocion potion(tipo,nombre,cantidad);
    this->pociones.push_back(potion);
}
void DataBase::SetArmaduras(char* buffLinea){
    string nombre =strtok(buffLinea," \t");
    int defensa=atoi(strtok(NULL," \t"));
    Armadura arm(defensa,nombre);
    this->armaduras.push_back(arm);
}
 void DataBase::rangoNiveles(int* niveles,int& min,int& max)const{
     min=12;max=-1;
     for(int i=0;i<NUMFILE;i++){
         if(niveles[i]<min) min=niveles[i];
         if(niveles[i]>max) max=niveles[i];
     }
     min+=1; max+=1;
 }