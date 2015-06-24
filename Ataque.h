/* 
 * File:   Ataque.h
 * Author: Propietario
 *
 * Created on 13 de junio de 2015, 01:45 AM
 */

#ifndef ATAQUE_H
#define	ATAQUE_H
#include <string>

using namespace std;

class Ataque {
public:
    Ataque(string,int,int,string="");
    Ataque();
    Ataque(const Ataque& orig);
    virtual ~Ataque();
    
    void SetMana(int);
    void SetDanio(int);
    std::string GetDescripcion() const;
    void SetNombre(std::string);
    int GetMana() const;
    int GetDanio() const;
    std::string GetNombre() const;
    
    Ataque operator=(const Ataque& atk);
private:
    std::string nombre;
    int danio;
    int mana;
    string descripcion;
};

#endif	/* ATAQUE_H */

