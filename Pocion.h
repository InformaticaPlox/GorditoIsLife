/* 
 * File:   Pocion.h
 * Author: Propietario
 *
 * Created on 13 de junio de 2015, 02:49 AM
 */

#ifndef POCION_H
#define	POCION_H
#include "Artefacto.h"
#include <string>

using namespace std;

class Avatar;

class Pocion:public Artefacto {
public:
    Pocion();
    Pocion(int cod,string nomb,int pts);
    Pocion(const Pocion& orig);
    virtual ~Pocion();
    void SetNombre(string nombre);
    string GetNombre() const;
    void imprimirNombre();
    Pocion operator=(const Pocion& poc);
    void SetId(int id);
    int GetId() const;
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void usar(Avatar& avatar);
    char* ObtenDescripcion();
protected:
    string nombre;
    int puntos;
    int id;
};

#endif	/* POCION_H */

