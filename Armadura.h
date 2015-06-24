/* 
 * File:   Armadura.h
 * Author: alulab14
 *
 * Created on 12 de junio de 2015, 12:00 PM
 */

#ifndef ARMADURA_H
#define	ARMADURA_H

#include "Artefacto.h"
#include <string>
using namespace std;

class Avatar;

class Armadura:public Artefacto{
public:
    Armadura(int, string);
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    
    void SetDefensa(int defensa);
    void SetNombre(string nombre);
    
    int GetDefensa() const;
    string GetNombre() const;
    
    void imprimirNombre();
    Armadura operator=(const Armadura& armor);
    void usar(Avatar& heroe);
    char* ObtenDescripcion();
private:
    string nombre;
    int defensa;
};

#endif	/* ARMADURA_H */

