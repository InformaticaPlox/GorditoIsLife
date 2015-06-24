/* 
 * File:   GestorLaberinto.cpp
 * Author: HP
 * 
 * Created on 6 de junio de 2015, 08:37 PM
 */


#include "GestorLaberinto.h"
#include "Laberinto.h"
#include "DataBase.h"

#include <fstream>
#include <iostream>
#include <cstdlib>


double const pcA=0.008;
double const pcM =0.01;

using namespace std;

GestorLaberinto::GestorLaberinto() {
}

GestorLaberinto::~GestorLaberinto() {
}

Laberinto GestorLaberinto::crearLaberinto(string escenario,int nivel,DataBase &data){
    Laberinto laberinto;
    laberinto.SetPctArtefacto(pcA*(nivel+1));
    laberinto.SetPctMonstruo(pcM*(nivel+1));
    ifstream escenario_map(escenario.c_str(),ios::in);
    if(escenario_map){
        int fil,col;
        escenario_map>>fil>>col;
        laberinto.SetM(fil);
        laberinto.SetN(col);
        laberinto.SetNivelesArtefacto(nivel+1);
        laberinto.SetNivelesMonstruo(nivel+1);
        laberinto.SetMatriz(escenario_map);
        laberinto.InicializarArtefacto(data);
        laberinto.InicializarMonstruo(data);
    }
    return laberinto;
}


