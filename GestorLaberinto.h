/* 
 * File:   GestorLaberinto.h
 * Author: HP
 *
 * Created on 6 de junio de 2015, 08:37 PM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H

#include <string>

class Laberinto;
class DataBase;
using namespace std;

class GestorLaberinto {
public:
    GestorLaberinto();
    Laberinto crearLaberinto(string,int,DataBase&);
    virtual ~GestorLaberinto();    
    friend class Laberinto;
private:   
        
};

#endif	/* GESTORLABERINTO_H */

