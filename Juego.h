/* 
 * File:   Juego.h
 * Author: JuanI
 *
 * Created on 7 de junio de 2015, 03:32 AM
 */

#ifndef JUEGO_H
#define	JUEGO_H
#include <string>
#include "Laberinto.h"
#include "GestorLaberinto.h"
class Avatar;
class graficos;
class Juego {
public:
    Juego(); 
    virtual ~Juego();
    void console_clear(int,int,int,int,char=' ')const;
    std::string* nombres_archivos()const;
    void Prologo(graficos &graf)const;
    int Jugar(graficos &graf);
    int Guardar();
    int Cargar();
    int Menu()const;
    void Menu_print(int=0)const;
    void Menu_head()const;
    void PantallaAbandono(graficos &graf)const;
    void PantallaFinal(graficos &graf)const;
    void Creditos(graficos &graf)const;
    int Calc_estado(int,int)const;
    int* Array_index()const;
    bool Batalla(Avatar&,Monstruo&)const;
    int mostrar_menu()const;
    void buscar_pos(const Laberinto&,int&,int&,int) const;
    
    int movimiento(Avatar&,const graficos&) ;
    void mostrar_equipo(Avatar&) const;
    void mostrar_inventario(Avatar&) const;
    int  mostrar_salir(Avatar&)const;

private:
    Laberinto laberintoActual;

};

#endif	/* JUEGO_H */

