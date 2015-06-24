/* 
 * File:   DataBase.h
 * Author: JuanI
 *
 * Created on 21 de junio de 2015, 05:54 AM
 */

#ifndef DATABASE_H
#define	DATABASE_H
#include <vector>
#include "Monstruo.h"
#include "Armadura.h"
#include "Arma.h"
#include "Pocion.h"

class DataBase {
public:
    DataBase();
    virtual ~DataBase();
    Artefacto *devuelve_artefacto(int*);
    Monstruo devuelve_monstruo(int*);
    void SetMonstruo(char*);
    void SetArmas   (char*);
    void SetPocimas (char*);
    void SetArmaduras(char*);
    void rangoNiveles(int*,int&,int&)const;

private:
    std::vector<Pocion> pociones;
    std::vector<Arma>armas;
    std::vector<Armadura>armaduras;
    std::vector<Monstruo> monstruos;
};

#endif	/* DATABASE_H */

