/* 
 * File:   Laberinto.h
 * Author: HP
 *
 * Created on 14 de junio de 2015, 03:54 AM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

#include "Celda.h"
#include "Artefacto.h"
#include "Monstruo.h"
#include "DataBase.h"
#include <list>
#include <fstream>

using namespace std;
class DataBase;
class Dibujador;
class Laberinto {
public:
    Laberinto();
    Laberinto(const Laberinto& orig);
    virtual ~Laberinto();
    
    void crearMatriz();
    
    void SetMatriz(ifstream &);
    Celda** GetMatriz() const;
    void SetNivelesArtefacto(int);
    int* GetNivelesArtefacto() const;
    void SetPctArtefacto(double pctArtefacto);
    double GetPctArtefacto() const;
    void SetNivelesMonstruo(int);
    int* GetNivelesMonstruo() const;
    void SetPctMonstruo(double pctMonstruo);
    void InicializarArtefacto(DataBase&);
    void InicializarMonstruo(DataBase&);
    void AgregarArtefacto(Artefacto*&);
    void AgregarMonstruo(const Monstruo&);
    Artefacto*  buscarArtefacto(int,int);
    Monstruo    buscarMonstruo (int,int);
    double GetPctMonstruo() const;
    void SetN(int N);
    int GetN() const;
    void SetM(int M);
    int GetM() const;
    Laberinto& operator=(const Laberinto&);
    Celda& operator()(int,int)const;
    void imprimir();
    double random(int,int)const;
    
    friend DataBase;
    friend Dibujador;
    
private:
    int M;
    int N;
    double pctMonstruo;
    int *nivelesMonstruo;
    double pctArtefacto;
    int *nivelesArtefacto;
    list<Artefacto*> artefactos;
    list<Monstruo> monstruos;
    Celda **matriz;
};

#endif	/* LABERINTO_H */

