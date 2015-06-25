/* 
 * File:   main.cpp
 * Author: JuanI
 *
 * Created on 7 de junio de 2015, 03:31 AM
 */

#include <cstdlib>
#include <ctime>
#include "Juego.h"
#include <iostream>
#include "Avatar.h"
#include "Entidad.h"
#include "Artefacto.h"
#include "Armadura.h"
#include "Ataque.h"
#include "Equipamiento.h"
#include "Monstruo.h"
#include "Pocion.h"
#include "Saco.h"
#include <string>



using namespace std;

void prueba_oso(){
  Ataque pw1("Abrazo de Samoel",40,10,"Capaz de asfixiarte :v");
    Ataque pw2("Puño y Mordida",50,15,"Capaz de herirte mucho :v");
    Arma weapon(20,30,"Samoel",pw1,pw2);
//    cout << weapon.GetDanhoMin() << " " << weapon.GetDanhoMax() << " "<< weapon.GetNombre() << endl;
//    Ataque pw3 = weapon.GetAtaque1();
//    Ataque pw4 = weapon.GetAtaque2();
//    cout << pw3.GetDanio() << " " << pw3.GetMana() << " " << pw3.GetNombre() << " " << pw3.GetDescripcion() << endl;
//    cout << pw4.GetDanio() << " " << pw4.GetMana() << " " << pw4.GetNombre() << " " << pw4.GetDescripcion() << endl;
//      Pocion p1(0,"Pocion de Curacion ksm",100);
//    Pocion p2(1,"Pocion de Mana p",200);
//    cout << p1.GetId() << " " << p1.GetNombre() << " " << p1.GetPuntos() << endl;
//    cout << p2.GetId() << " " << p2.GetNombre() << " " << p2.GetPuntos() << endl;
//    Ataque pw1("Abrazo de Samoel",40,10,"Capaz de asfixiarte :v");
//    Ataque pw2("Puño y Mordida",50,15,"Capaz de herirte mucho :v");
//    Artefacto *art = new Pocion(0,"Pocion de Curacion ksm",100);
//    art->imprimirNombre();
    Artefacto *art2 = new Arma(20,30,"Samoel",pw1,pw2);
//    art2->imprimirNombre();
//    Pocion p1;
//    cout << p1.GetId() << " " << p1.GetNombre() << " " << p1.GetPuntos() << endl;
    Pocion p1(0,"Pocion de curacion",100);
    Artefacto *poc = new Pocion(p1);
   // cout << poc->ObtenDescripcion() << endl;
      Artefacto *art = new Armadura(30,"Chaleco");
//    Pocion *p = (Pocion*)poc;
//    cout << p->GetId() << " " << p->GetNombre() << " " << p->GetPuntos() << endl;
    
//    Saco bag;
//    bag.agregaArtefaacto(poc);
//    bag.agregaArtefaacto(art);
//    bag.imprimeElementos();
//    
//    Artefacto *art2 = bag.sacaElemento(1);
//    bag.imprimeElementos();
//    Artefacto *art1 = new Pocion;
//    art1 = bag.sacaElemento(0);
//    Pocion *p = (Pocion*)art1;
//    cout << p->GetId() << " " << p->GetNombre() << " " << p->GetPuntos() << endl;
    
    Armadura arm(30,"Escudork");
    
//    Equipamiento mm(weapon,arm);
//    Arma a1 = mm.GetWeapon();
//    Armadura b1 = mm.GetArmor();
//     cout << a1.GetNombre() << "/" << a1.GetDanhoMin() << "/" << a1.GetDanhoMax() << endl;
//     Ataque atk1 = a1.GetAtaque1();
//     Ataque atk2 = a1.GetAtaque2();
//     cout << atk1.GetNombre() << "/" << atk1.GetDescripcion() << "/" << atk1.GetDanio() << "/" << atk1.GetMana() << endl;
//    cout << atk2.GetNombre() << "/" << atk2.GetDescripcion() << "/" << atk2.GetDanio() << "/" << atk2.GetMana() << endl;
//     cout << b1.GetDefensa() << "/" << b1.GetNombre() << endl;

    
    Avatar heroe(3,4,100,100,"Pablito",weapon,arm,100,100);
    heroe.SetNombre("JUANI");
    heroe.recogeArtefacto(art2);
    heroe.recogeArtefacto(art);
    heroe.recogeArtefacto(poc);
    char **moc = heroe.observaSaco();
    for(int i = 0; i < 3; i++)
        cout << moc[i] << endl;
//     Ataque pw3("No se que chucha poner",30,10,"Ni idea");
//    Ataque pw4("No se me ocurre nada",60,25,"Bica");
//    Arma arma(10,20,"V",pw3,pw4);
//    arma.usar(heroe);
//    Armadura armadura(40,"Proteccion");
//    armadura.usar(heroe);
//    Equipamiento equip = heroe.GetEquip();
//    Arma a1 = equip.GetWeapon();
//    Ataque atk1 = a1.GetAtaque1();
//    Ataque atk2 = a1.GetAtaque2();
//    Armadura b1 = equip.GetArmor();
//    heroe.recogeArtefacto(poc);
//    heroe.recogeArtefacto(art);
//    heroe.SetVidaActual(20);
//    Pocion pocima(0,"Pocion del V",30);
//    pocima.usar(heroe);
//    
//    cout << heroe.GetPosX() << "-" << heroe.GetPosY() << endl;
//    cout << heroe.GetVidaActual() << "/" << heroe.GetMaxVida() << endl;
//    cout << a1.GetNombre() << "/" << a1.GetDanhoMin() << "/" << a1.GetDanhoMax() << endl;
//    cout << atk1.GetNombre() << "/" << atk1.GetDescripcion() << "/" << atk1.GetDanio() << "/" << atk1.GetMana() << endl;
//    cout << atk2.GetNombre() << "/" << atk2.GetDescripcion() << "/" << atk2.GetDanio() << "/" << atk2.GetMana() << endl;
//    cout << b1.GetDefensa() << "/" << b1.GetNombre() << endl;
//    cout << heroe.GetManaActual() << "/" << heroe.GetManaMax() << endl;
//    heroe.observaSaco();
//    
//    Monstruo monster(3,4,200,200,"Vivian",40,30,1);
//    monster.registraArtefacto(poc);
//    monster.registraArtefacto(art);
//    cout << monster.GetNombre() << "/" << monster.GetNivel() << endl;
//    cout << monster.GetPosX() << "/" << monster.GetPosY() << endl;
//    cout << monster.GetVidaActual() << "/" << monster.GetMaxVida() << endl;
//    cout << monster.GetAtaque() <<"/" << monster.GetDefensa() << endl;
//    Artefacto *aux = monster.retiraArtefacto(0);
//    monster.observaSaco();  
}
void prueba_allegro(){
    
}
void prueba_oso2(){
    Artefacto *art = new Pocion(0,"Pocion de curacion",100);
    Artefacto *art2 = new Armadura(30,"Escudork");
    Ataque pw1("Abrazo de Samoel",40,10,"Capaz de asfixiarte :v");
    Ataque pw2("Puño y Mordida",50,15,"Capaz de herirte mucho :v");
    Artefacto *art3 = new Arma(20,30,"Espadark",pw1,pw2);
    
    char *desc1 = art->ObtenDescripcion();
    char *desc2 = art2->ObtenDescripcion();
    char *desc3 = art3->ObtenDescripcion();
    cout << desc1 << endl;
    cout << desc2 << endl;
    cout << desc3 << endl;
}


int main(int argc, char** argv) {
//   prueba_oso();
   // prueba_allegro();
   // prueba_oso2();
    Juego J;   
    return 0;
}

