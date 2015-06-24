/* 
 * File:   Laberinto.cpp
 * Author: HP
 * 
 * Created on 14 de junio de 2015, 03:54 AM
 */

#include "Laberinto.h"
#include "DataBase.h"
#include "auxiliar.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>
#define NUMFILE 10

using namespace std;

Laberinto::Laberinto() {
    this->nivelesArtefacto=new int[NUMFILE];
    this->nivelesMonstruo=new int[NUMFILE];
}

Laberinto::Laberinto(const Laberinto& orig) {
    this->M=orig.M;
    this->N=orig.N;
    this->matriz=orig.GetMatriz();
    this->nivelesArtefacto=orig.GetNivelesArtefacto();
    this->nivelesMonstruo=orig.GetNivelesMonstruo();
    this->pctArtefacto=orig.pctArtefacto;
    this->pctMonstruo=orig.pctMonstruo;
    this->artefactos=orig.artefactos;
    this->monstruos=orig.monstruos;
            
}

Laberinto::~Laberinto() {
    this->M=0;
    this->N=0;
    delete[]this->matriz;
    delete[]this->nivelesArtefacto;
    delete[]this->nivelesMonstruo;
    this->pctArtefacto=0;
    this->pctMonstruo=0;
}

void Laberinto::crearMatriz(){
    int filas = this->GetM();
    int columnas = this->GetN();
    
    this->matriz = new Celda*[filas];
    for(int i = 0; i < columnas; i++)
        this->matriz[i] = new Celda[columnas];   
}

void Laberinto::SetMatriz(ifstream &arch) {
    srand(time(NULL)); 
    
    this->crearMatriz();
    char c; arch.get(c);
    for (int i = 0; i < this->M;  i++){
        for (int j = 0; j < this->N; j++){
            arch.get(c);
            if (c == '#') this->matriz[i][j].SetTipo(1);
            if (c == 'I') this->matriz[i][j].SetTipo(3);
            if (c == 'F') this->matriz[i][j].SetTipo(4);
            if (c == ' '){
                this->matriz[i][j].SetTipo(0); // Valor inicial
                double valor = fRand(0,1);
                if (this->pctMonstruo > valor) 
                    this->matriz[i][j].SetTipo(6);
                else{
                    valor = fRand(0,1);
                    if (this->pctArtefacto > valor) 
                        this->matriz[i][j].SetTipo(5);                
                }                  
            }
        }
        arch.get(c);
    }
}

Celda** Laberinto::GetMatriz() const {
    int fil =this->M;
    int col= this->N;
    Celda ** C = new Celda*[fil];
    for(int i=0;i<col;i++){
        C[i]=new Celda[col];
    }
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            C[i][j]=this->matriz[i][j];
        }
    }
    return C;
}

void Laberinto::SetNivelesArtefacto(int cont) {
    for (int i = 0; i < NUMFILE; i++) this->nivelesArtefacto[i] = 0;
    for (int i = 0; i < cont; i++){
        this->nivelesArtefacto[i] = i+1;
    } 
}

int* Laberinto::GetNivelesArtefacto() const {
    int *aux = new int[NUMFILE];
    for (int i = 0; i < NUMFILE; i++)
        aux[i] = this->nivelesArtefacto[i];
    return aux;
}

void Laberinto::SetPctArtefacto(double pctArtefacto) {
    this->pctArtefacto = pctArtefacto;
}

double Laberinto::GetPctArtefacto() const {
    return pctArtefacto;
}

void Laberinto::SetNivelesMonstruo(int cont) {
    for (int i = 0; i < 8; i++) this->nivelesMonstruo[i] = 0;
    for (int i = 0; i < cont; i++){
        this->nivelesMonstruo[i] = i+1;
    }    
}

int* Laberinto::GetNivelesMonstruo() const {
    int *aux = new int[NUMFILE];
    for (int i = 0; i <NUMFILE; i++)
        aux[i] = this->nivelesMonstruo[i];
    return aux;
}

void Laberinto::SetPctMonstruo(double pctMonstruo) {
    this->pctMonstruo = pctMonstruo;
}

double Laberinto::GetPctMonstruo() const {
    return pctMonstruo;
}

void Laberinto::SetN(int N) {
    this->N = N;
}

int Laberinto::GetN() const {
    return N;
}

void Laberinto::SetM(int M) {
    this->M = M;
}

int Laberinto::GetM() const {
    return M;
}


void Laberinto::imprimir(){
    cout << this->GetM() << "\t" << this->GetN() << endl;
    for (int i = 0; i < NUMFILE; i++){
        if (this->nivelesArtefacto[i] == 0) break;
        cout << this->nivelesArtefacto << "\t" << this->nivelesMonstruo << endl;
    }
    
    for (int i = 0; i < this->GetM(); i++){
        for(int j = 0; j < this->GetN(); j++){
            cout << this->matriz[i][j].GetTipo();
        }
        cout << endl;
    }
}
Laberinto& Laberinto::operator=(const Laberinto& orig){
    if(this==&orig)
        return *this;
    else{
        this->M=orig.M;
        this->N=orig.N;
        this->matriz=orig.GetMatriz();
        this->nivelesArtefacto=orig.GetNivelesArtefacto();
        this->nivelesMonstruo=orig.GetNivelesMonstruo();
        this->pctArtefacto=orig.pctArtefacto;
        this->pctMonstruo=orig.pctMonstruo;
        this->monstruos=orig.monstruos;
        this->artefactos=orig.artefactos;
        return *this;
    }
}
void Laberinto::InicializarArtefacto(DataBase &data){
    for(int i=0;i<this->M;i++){
        for(int j=0;j<this->N;j++){
            if(this->matriz[i][j].GetTipo()==5){
                Artefacto* art = data.devuelve_artefacto(this->nivelesArtefacto);
                art->setCoordX(i); art->setCoordY(j);
                this->artefactos.push_back(art);
            }
        }
    }
}
void Laberinto::InicializarMonstruo(DataBase &data){
    for(int i=0;i<this->M;i++){
        for(int j=0;j<this->N;j++){
            if(this->matriz[i][j].GetTipo()==6){
                Monstruo mon = data.devuelve_monstruo(this->nivelesMonstruo);
                mon.SetPosX(i); mon.SetPosY(j);
                this->monstruos.push_back(mon);
            }
        }
    }
}
Celda& Laberinto::operator()(int fil,int col)const{
    if(fil<this->M && col<this->N){
        return this->matriz[fil][col];
    }
}
void Laberinto::AgregarArtefacto( Artefacto*& Art){
    this->artefactos.push_back(Art);
}
void Laberinto::AgregarMonstruo(const Monstruo& Mon){
    this->monstruos.push_back(Mon);
}
Artefacto* Laberinto::buscarArtefacto(int x,int y){
    list<Artefacto*>::iterator it;
    for(it=this->artefactos.begin();it!=this->artefactos.end();it++){
        Artefacto *art=*it;
        if(art->getCoordX()==x && art->getCoordY()==y) {
            this->artefactos.erase(it);
            return art;
        }
    }
    Artefacto *A;
    return A;  //Vacío
}
Monstruo  Laberinto::buscarMonstruo (int x,int y){
   list<Monstruo>::iterator it;
   for(it=this->monstruos.begin();it!=this->monstruos.end();it++){
       Monstruo mon=*it;
       if(mon.GetPosX()==x && mon.GetPosY()==y){
           this->monstruos.erase(it);
           return mon;
       }
   }
   Monstruo mon;
   return mon; //vacio
}