/* 
 * File:   Avatar.h
 * Author: Juan
 *
 * Created on 13 de junio de 2015, 12:18 AM
 */

#ifndef AVATAR_H
#define	AVATAR_H

#include "Entidad.h"
#include "Equipamiento.h"
#include "Arma.h"
#include "Armadura.h"

class Avatar : public Entidad{
public:
    Avatar(int pX,int pY,int mxVida,int vidaA,string nomb,const Arma& arma, const Armadura& armadura, int manaAc, int maxMana);
    Avatar(const Avatar& orig);
    Avatar();
    virtual ~Avatar();
    void SetManaMax(int manaMax);
    int GetManaMax() const;
    void SetManaActual(int manaActual);
    int GetManaActual() const;
    void SetEquip(Equipamiento equip);
    Equipamiento GetEquip() const;  
    Avatar operator=(const Avatar& av);
    void recogeArtefacto(Artefacto *&artefacto);
    Artefacto *retiraArtefacto(int pos);
    void observaSaco();
    void CambiaArma(Arma &arma);
    Arma obtenArma() const;
    void CambiaArmadura(Armadura &armadura);
    Armadura obtenarmadura() const;
    void recibeDanio(int danho);
    void disminuyeMana(int tipoAtq);
    int verificaMana(int tipoAtq);
    int obtenDanho(int i);
    void SetDanhoNormal(int danhoNormal);
    int GetDanhoNormal() const;
    int AtkNormal() const;
    void RecuperaMana();
private:
    Equipamiento equip;
    int manaActual;
    int manaMax;
};

#endif	/* AVATAR_H */

