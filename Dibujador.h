/* 
 * File:   Dibujador.h
 * Author: Juan
 *
 * Created on 6 de junio de 2015, 09:32 PM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H

#include "Celda.h"
class Laberinto;
class graficos;
class Dibujador {
public:
    Dibujador(int = 2, int = 2);
    Dibujador(const Dibujador& orig);
    virtual ~Dibujador();
    void Dibuja(int,int,int,int,const Laberinto& ,const graficos&);
    void SetB(int B);
    int GetB() const;
    void SetA(int A);
    int GetA() const;
private:
    int A;
    int B;
};

#endif	/* DIBUJADOR_H */

