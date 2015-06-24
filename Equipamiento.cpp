/* 
 * File:   Equipamiento.cpp
 * Author: Juan
 * 
 * Created on 14 de junio de 2015, 12:00 AM
 */

#include "Equipamiento.h"

Equipamiento::Equipamiento() : weapon(), armor(){    
}

Equipamiento::Equipamiento(const Arma& arma,const Armadura& armadura) : weapon(arma), armor(armadura){    
}

Equipamiento::Equipamiento(const Equipamiento& orig) {
    this->SetArmor(orig.GetArmor());
    this->SetWeapon(orig.GetWeapon());
}


Equipamiento::~Equipamiento() {
}

void Equipamiento::SetArmor(Armadura shield) {
    this->armor = shield;
}

Armadura Equipamiento::GetArmor() const {
    return armor;
}

void Equipamiento::SetWeapon(Arma weapon) {
    this->weapon = weapon;
}

Arma Equipamiento::GetWeapon() const {
    return weapon;
}

Equipamiento Equipamiento::operator =(const Equipamiento& equip){
    if (this == &equip)
        return *this;
    else{
        this->SetWeapon(equip.GetWeapon());
        this->SetArmor(equip.GetArmor());
        return *this;
    }
}

