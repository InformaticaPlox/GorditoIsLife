/* 
 * File:   Artefacto.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 05:41 PM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

//#include <iostream>
#include <string>

class Avatar;

using namespace std;

class Artefacto {
public:
    Artefacto();
    virtual ~Artefacto();
    virtual Artefacto operator=(const Artefacto& artefacto);
    virtual void usar(Avatar& heroe); 
    virtual void imprimirNombre();
    
    void setCoordY(int coordY);
    void setCoordX(int coordX);
    void setTipo(int tipo);
    
    int getCoordY() const;
    int getCoordX() const;
    int getTipo() const;
    virtual char* ObtenDescripcion();

private:
    int coordX;
    int coordY;
    int tipo;
};

#endif	/* ARTEFACTO_H */

