/* 
 * File:   Entidad.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 04:50 PM
 */

#ifndef ENTIDAD_H
#define	ENTIDAD_H

#include <string>
//#include <iostream>
#include "Saco.h"

class Artefacto;

using namespace std;

class Entidad {
public:
    virtual ~Entidad();
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetVidaActual(int vidaActual);
    int GetVidaActual() const;
    void SetMaxVida(int maxVida);
    int GetMaxVida() const;
    void SetPosY(int posY);
    int GetPosY() const;
    void SetPosX(int posX);
    int GetPosX() const;
    void imprimePosACtual();
    virtual Entidad operator=(const Entidad& ent);
    friend Artefacto;
protected:
    Entidad();
    Entidad(int pX,int pY,int maxLife,int actualLife,string name);
    Entidad(const Entidad& orig);
    int posX;
    int posY;
    int maxVida;
    int vidaActual;
    string nombre;
    Saco inventario;
};

#endif	/* ENTIDAD_H */

