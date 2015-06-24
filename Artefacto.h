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
    //friend virtual void usar(Entidad);
    virtual void usar(Avatar& heroe); 
    //Sobrecargar operadores de flujo
    virtual void imprimirNombre();
    void setCoordY(int coordY);
    int getCoordY() const;
    void setCoordX(int coordX);
    int getCoordX() const;
    virtual char* ObtenDescripcion();
private:
    int coordX;
    int coordY;
};

#endif	/* ARTEFACTO_H */

