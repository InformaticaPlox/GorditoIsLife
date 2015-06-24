/* 
 * File:   Equipamiento.h
 * Author: Juan
 *
 * Created on 14 de junio de 2015, 12:00 AM
 */

#ifndef EQUIPAMIENTO_H
#define	EQUIPAMIENTO_H

#include "Arma.h"
#include "Armadura.h"

class Equipamiento {
public:
    Equipamiento();
    Equipamiento(const Arma &arma,const Armadura &armadura);
    Equipamiento(const Equipamiento& orig);
    virtual ~Equipamiento();
    void SetArmor(Armadura shield);
    Armadura GetArmor() const;
    void SetWeapon(Arma weapon);
    Arma GetWeapon() const;
    Equipamiento operator=(const Equipamiento& equip);
private:
    Arma weapon;
    Armadura armor;
};

#endif	/* EQUIPAMIENTO_H */

