/* 
 * File:   graficos.h
 * Author: JuanI
 *
 * Created on 22 de junio de 2015, 01:43 AM
 */

#ifndef GRAFICOS_H
#define	GRAFICOS_H

class graficos {
public:
    graficos();
    graficos(const graficos& orig);
    virtual ~graficos();
    int  Movimiento(int&,int&)const;
    int  Recibe_tecla()const;
    void Dibujar(int,int,int,int,int,int,int**)const;
    int  Inicio()const;
    int  Inventario()const; /*Dentro debe ir las descripciones */
    int  Equipamiento()const; /*Dentro debe ir las descripciones */
    void MostrarArtefacto()const; /*Descripcion */
    int  RecogerArtefacto()const; /*Descripcion */
    void PantallaVictoria()const;
    void PantallaPerder()const;
    void PantallaCreditos()const;  
    
    /* EL HARD:*/
    int InterfazCombate()const; /*Descripcion*/
private:
    
};

#endif	/* GRAFICOS_H */

