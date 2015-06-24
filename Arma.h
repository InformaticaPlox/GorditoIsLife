/* 
 * File:   Arma.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 11:50 AM
 */

#ifndef ARMA_H
#define	ARMA_H

#include "Artefacto.h"
#include "Ataque.h"
#include <string>
#include <ctime> 
#include <cstdlib>
using namespace std;
 // esto se colocará en juego

class Avatar;

class Arma:public Artefacto{
public:
    Arma(int, int, string,const Ataque&,const Ataque&);
    Arma();
    
    Arma(const Arma& orig);
    virtual ~Arma();
    
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetDanhoMax(int danhoMax);
    int GetDanhoMax() const;
    void SetDanhoMin(int danhoMin);
    int GetDanhoMin() const;
    int critico()const;
    Ataque GetAtaque2() const;
    Ataque GetAtaque1() const;
    void imprimirNombre();
    Arma operator=(const Arma& arma);
    void usar(Avatar& heroe);
    char* ObtenDescripcion();
private:
    int danhoMin;
    int danhoMax;
    string nombre;
    Ataque ataque1;
    Ataque ataque2;
};

#endif	/* ARMA_H */

