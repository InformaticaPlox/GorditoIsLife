/* 
 * File:   Saco.h
 * Author: Juan
 *
 * Created on 14 de junio de 2015, 02:42 AM
 */

#ifndef SACO_H
#define	SACO_H

#include "Artefacto.h"
#include <vector>
//#include <iostream>

using namespace std;

class Saco {
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();
    void agregaArtefacto(Artefacto *&artefacto);
    Artefacto *sacaElemento(int pos);
    void imprimeElementos();
    int  cantidad()const;
    Saco operator=(const Saco& bag);
private:
    vector<Artefacto*> saco;
};

#endif	/* SACO_H */

