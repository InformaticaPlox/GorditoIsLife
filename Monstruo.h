/* 
 * File:   Monstruo.h
 * Author: alulab14
 *
 * Created on 15 de junio de 2015, 11:41 AM
 */

#ifndef MONSTRUO_H
#define	MONSTRUO_H

#include "Entidad.h"

class Monstruo : public Entidad{
public:
    Monstruo();
    Monstruo(int pX,int pY,int mxVida,int vidaA,string nomb,int atk, int def, int niv);
    Monstruo(const Monstruo& orig);
    virtual ~Monstruo();
    void SetDefensa(int defensa);
    int GetDefensa() const;
    void SetAtaque(int ataque);
    int GetAtaque() const;
    void SetNivel(int nivel);
    int GetNivel() const;
    int GetRandomPos()const;
    Monstruo operator=(const Monstruo& mons);
    Artefacto *retiraArtefacto(int pos);
    void registraArtefacto(Artefacto *&artefacto);
    void observaSaco();
    void recibeDanio(int danho);
private:
    int ataque;
    int defensa;
    int nivel;
};

#endif	/* MONSTRUO_H */

