/* 
 * File:   Juego.cpp
 * Author: JuanI
 * 
 * Created on 7 de junio de 2015, 03:32 AM
 */
 /* DEFINICION DE CABECERAS*/
#include "Juego.h"
#include "Armadura.h"
#include "Avatar.h"
#include "Dibujador.h"
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "DataBase.h"
#include "graficos.h"




#define VACIO 0
#define LABERINTO 1
#define HEROE 2
#define INICIO 3
#define FINAL 4
#define ARTEFACTO 5
#define MONSTRUO 6


#define ENTER_PRESIONADO 1
#define RETORNA 2
#define AVANZA 3
#define MUERTE 4
#define MOVIMIENTO 5


#define NUMFILE 10
#define MONSTERBASE 2
#define ARTEFACTBASE 2
#define ENTER 13
#define Ix 2
#define Iy 2
using namespace std;



/* MÉTODOS*/

Juego::Juego() {
    srand(time(NULL));
    graficos graf;
    while(1){
        int modo= this->Menu();
        if(modo==1){
            this->Prologo();
            int r=this->Jugar(graf);
            if(r==1){ // Perdiste
                cout<<"         GAME OVER"<<endl;
                cout<<"¿DESEA VOLVER A JUGAR?(Y/N)"<<endl;
                char c=getch();
                while(c!='N' && c!='n' && c!='y' && c!='Y') c=getch();
                if(c=='N' || c=='n') break; // termino el juego    
            }
            else{
                if(r==0){// El jugador decidio salir del juego
                    this->PantallaAbandono(graf);
                    Sleep(2000);
                    exit(1);
                }
                else{ // El jugador ha ganado
                    this->PantallaFinal(graf);
                    Sleep(2000);
                    exit(1);
                }
            }
        }
        else if(modo==2){// Cargar un juego guardado
            int r=this->Cargar();
            if(r==1){ // El jugador decidio salir del juego
                this->PantallaAbandono(graf);
            }
            else{
                this->PantallaFinal(graf);
            }
        }
        else if(modo==3) // creditos
            this->Creditos(graf);
        else
            break;
    }   
}


Juego::~Juego() {
    
}
void Juego::console_clear(int x,int y,int dx,int dy,char clearwith)const{
    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);  // get console handle 
    CONSOLE_SCREEN_BUFFER_INFO csbi;        // screen buffer information
    DWORD chars_written;                    // count successful output

    GetConsoleScreenBufferInfo(hc, &csbi);      // Get screen info & size 
    GetConsoleScreenBufferInfo(hc, &csbi);      // Get current text display attributes
    if (x + dx > csbi.dwSize.X)                 // verify maximum width and height
        dx = csbi.dwSize.X - x;                 // and adjust if necessary
    if (y + dy > csbi.dwSize.Y)
        dy = csbi.dwSize.Y - y;

    for (int j = 0; j < dy; j++) {              // loop for the lines 
        COORD cursor = { x, y+j };              // start filling 
        // Fill the line part with a char (blank by default)
        FillConsoleOutputCharacter(hc, TCHAR(clearwith),
            dx, cursor, &chars_written);
        // Change text attributes accordingly 
        FillConsoleOutputAttribute(hc, csbi.wAttributes,
            dx, cursor, &chars_written);
    }
    COORD cursor = { x, y };
    SetConsoleCursorPosition(hc, cursor);  // set new cursor position
}
string* Juego::nombres_archivos()const{
    string *nombreArchivo = new string[NUMFILE];
    for(int i=0;i<NUMFILE;i++){
        string buffer="escenarios\\escenario";
        char c[10];
        itoa(i,c,10);
        buffer=buffer+c+".txt";
        nombreArchivo[i]=buffer;
    }
    return nombreArchivo;
}
void Juego::Prologo()const{
    cout<<"HOLI";
    
}
int Juego::Jugar(graficos &graf){
    /* Variables:*/
    int cond;
    string nombre;
    Avatar heroe;
    GestorLaberinto gestor;
    Dibujador dib(4,5);
    vector <Laberinto> laberintos;
    DataBase data;
    
    
    /* Funciones:*/
    
    string* nombreArchivo=this->nombres_archivos();
    
    int *index=this->Array_index();
    int *index2 =new int [NUMFILE]; index2[0]=0;index2[NUMFILE-1]=NUMFILE-1;
    for(int i=1;i<NUMFILE-1;i++) index2[i]=index[i-1]+1;
    
    for(int i=0;i<NUMFILE;i++){   
        laberintos.push_back(gestor.crearLaberinto(nombreArchivo[index2[i]],i,data));
    }
    
    /* Funcion conseguir nombre*/
    cout<<"INGRESE EL NOMBRE DE SU PERSONAJE: "<<endl;
    cin>>nombre;
    
    heroe.SetNombre(nombre); heroe.SetPosX(Ix+1); heroe.SetPosY(Iy);  //Posicion inicial
    vector<Laberinto>::iterator it;
    it=laberintos.begin();
    this->laberintoActual=*it.base();
    this->laberintoActual(heroe.GetPosX(),heroe.GetPosY()).SetTipo(2);
    while(it!=laberintos.end()){
        //this->laberintoActual=*it.base();
    dib.Dibuja(heroe.GetPosX(),heroe.GetPosY(),this->laberintoActual.GetM()-1,this->laberintoActual.GetN()-1,this->laberintoActual,graf);
        int cond=0;
        cond=this->movimiento(heroe,graf);
        if(cond==ENTER_PRESIONADO){
            cond=this->mostrar_menu();
            if(cond==1)
                this->mostrar_equipo(heroe);
            else if(cond ==2)
                this->mostrar_inventario(heroe);
            else if(cond==3)
                continue;
            else{
                int selc=this->mostrar_salir(heroe);
                if (selc==1) return 0; // sale del juego
            } 
        }
        else if(cond==RETORNA){
            if(it==laberintos.begin()) {                
                continue;
            }
            it--;
            int x=0,y=0;
            buscar_pos(*it.base(),x,y,0);
            this->laberintoActual =*it;
            heroe.SetPosX(x); heroe.SetPosY(y);
            this->laberintoActual(x,y).SetTipo(2);
        }
        else if(cond==AVANZA){
            it++;
            if(it==laberintos.end()) continue;
            int x=0,y=0;
            buscar_pos(*it.base(),x,y,1);
            this->laberintoActual=*it;
            heroe.SetPosX(x); heroe.SetPosY(y);
            this->laberintoActual(x,y).SetTipo(2);
        }
        else if(cond==MUERTE){
            return 1;
        }
        else // solo movimiento
            continue;       
    }
    return 2;                
}
/* Agregar el this->allegro.dibujar aqui o en juego::jugar*/
int  Juego::movimiento(Avatar& heroe,const graficos& graf){
    int xi=heroe.GetPosX(), yi=heroe.GetPosY();
    int x=xi, y=yi;
    bool enter;
    cout<<"POSICIONES: "<<x<<" "<<y<<endl;
    int valor= graf.Movimiento(x,y); // si se presiona tecla especial (1:enter)
    cout<<"POSICION LUEGO: "<<x<<" "<<y<<endl;
    if(valor) return ENTER_PRESIONADO;   
    int tipo =this->laberintoActual(x,y).GetTipo();
    if(tipo==ARTEFACTO){
        Artefacto *art;
        art=this->laberintoActual.buscarArtefacto(x,y);
        bool eleccion;
        //eleccion= this->allegro.recogerElemento(art.descripcion());
        if(eleccion){
            heroe.SetPosX(x); heroe.SetPosY(y);
            heroe.recogeArtefacto(art);
            this->laberintoActual(x,y).SetTipo(2); // persona
            this->laberintoActual(xi,yi).SetTipo(0); //piso
        }
        else
            this->laberintoActual.AgregarArtefacto(art);
        return MOVIMIENTO; // solo movimiento
    }
    else if(tipo==MONSTRUO){
        Monstruo mon;
        mon=this->laberintoActual.buscarMonstruo(x,y);
        bool muerte=this->Batalla(heroe,mon);
        if(!muerte){
            Artefacto *art;
            art=mon.retiraArtefacto(mon.GetRandomPos());
            bool eleccion;
            //eleccion= this->allegro.recogerElemento(art.descripcion());
            if(eleccion){
                heroe.SetPosX(x); heroe.SetPosY(y);
                heroe.recogeArtefacto(art);
                this->laberintoActual(x,y).SetTipo(2); //persona
                this->laberintoActual(xi,yi).SetTipo(0);
            }
            else {
            art->setCoordX(x); art->setCoordY(y);
            this->laberintoActual.AgregarArtefacto(art);
            this->laberintoActual(x,y).SetTipo(5); //artefacto
            }  
        }
        else{
            this->laberintoActual.AgregarMonstruo(mon);
            return MUERTE; 
        }
    }
    else if(tipo==INICIO){
       this->laberintoActual(xi,yi).SetTipo(0);
       return RETORNA;  
    }
        
    else if(tipo==FINAL){
        this->laberintoActual(xi,yi).SetTipo(0);
        return AVANZA; 
    }
    else if(tipo==VACIO){
        heroe.SetPosX(x); heroe.SetPosY(y);
        this->laberintoActual(x,y).SetTipo(2);
        this->laberintoActual(xi,yi).SetTipo(0);
        return MOVIMIENTO; 
    }
    else{
        return MOVIMIENTO;
    }
}


void Juego::mostrar_equipo(Avatar& heroe) const{
    /* Mostrará el equipamiento actual del personaje*/
}
void Juego::buscar_pos(const Laberinto& lab,int& x,int& y,int cond) const{
    if (cond){
        for(int i=0;i<lab.GetM();i++){ 
            for(int j=0;j<lab.GetN();j++){
                if(lab(i,j).GetTipo()==3){// Ingreso
                    if(lab(i+1,j).GetTipo()!=1){
                        x=i+1;
                        y=j;
                        return;
                    }else if (lab(i,j+1).GetTipo()!=1){
                        x=i;
                        y=j+1;
                        return; 
                    }else if (lab(i-1,j).GetTipo()!=1){
                        x=i-1;
                        y=j;
                        return;
                    }else if (lab(i,j-1).GetTipo()!=1){
                        x=i;
                        y=j-1;
                        return;
                    }else if (lab(i-1,j-1).GetTipo()!=1){
                        x=i-1;
                        y=j-1;
                        return;
                    }else if (lab(i+1,j-1).GetTipo()!=1){
                        x=i+1;
                        y=j-1;
                        return;
                    }else if (lab(i-1,j+1).GetTipo()!=1){
                        x=i-1;
                        y=j+1;
                        return;
                    }else if (lab(i+1,j+1).GetTipo()!=1){
                        x=i+1;
                        y=j+1;
                        return;
                    }    
                }     
            }
        }
    }
    else{
                for(int i=0;i<lab.GetM();i++){ 
            for(int j=0;j<lab.GetN();j++){
                if(lab(i,j).GetTipo()==4){// Ingreso
                    if(lab(i+1,j).GetTipo()!=1){
                        x=i+1;
                        y=j;
                        return;
                    }else if (lab(i,j+1).GetTipo()!=1){
                        x=i;
                        y=j+1;
                        return; 
                    }else if (lab(i-1,j).GetTipo()!=1){
                        x=i-1;
                        y=j;
                        return;
                    }else if (lab(i,j-1).GetTipo()!=1){
                        x=i;
                        y=j-1;
                        return;
                    }else if (lab(i-1,j-1).GetTipo()!=1){
                        x=i-1;
                        y=j-1;
                        return;
                    }else if (lab(i+1,j-1).GetTipo()!=1){
                        x=i+1;
                        y=j-1;
                        return;
                    }else if (lab(i-1,j+1).GetTipo()!=1){
                        x=i-1;
                        y=j+1;
                        return;
                    }else if (lab(i+1,j+1).GetTipo()!=1){
                        x=i+1;
                        y=j+1;
                        return;
                    }    
                }     
            }
        }
    }
}
/* VA AVATAR*/
void Juego::mostrar_inventario(Avatar& heroe) const{
    /* Mostrará el inventario*/
}
int  Juego::mostrar_salir(Avatar& heroe)const{
    /* MOSTRAR MENU DE SALIR, retorna 1 si desea salir
     0 caso contrario*/
}
int Juego::mostrar_menu()const{
    /* MUESTRA UN MENU CON : 1. equipamiento
                             2. inventario
                             3.  retornar
                             4.  Salir
     Retorna 1: equipamiento, 2:inventario...*/
}
int Juego::Guardar(){

}
int Juego::Cargar(){
    return 2;
}
int Juego::Menu()const{
    int x=0,y=0,estado=0;
    this->Menu_print();
    char c=getch();
    while(c!=ENTER){
        if(c=='W'||c=='w')
            x=(x+1)%2;
        if(c=='S'||c=='s')
            x=(x-1)%2;
        if(c=='A'||c=='a')
            y=(y-1)%2;
        if(c=='D'||c=='d')
            y=(y+1)%2;
        estado=this->Calc_estado(x,y);
        this->Menu_print(estado);
        c=getch();
    }
    return estado+1;
}
void Juego::PantallaFinal(graficos &graf)const{
    graf.PantallaVictoria();
    /* El jugador ha vencido*/
}
void Juego::PantallaAbandono(graficos &graf)const{
    graf.PantallaPerder();
    /* Es usted un cobarde */
}
void Juego::Creditos(graficos &graf)const{
    graf.PantallaCreditos();
    /* Creditos del juego*/
    
}
void Juego::Menu_print(int pos)const{
    this->console_clear(0,3,100,100);
    this->Menu_head();
    if(pos==0){
        cout<<"                    |"<<"NEW GAME"<<char(17)<<"                   "<<"LOAD GAME  |"
            <<"\n                    |"<<"CREDITOS"<<"                    "<<"EXIT       |"<<endl;
    }
    else if(pos==1){
        cout<<"                    |"<<"NEW GAME"<<"                    "<<"LOAD GAME"<<char(17)<<" |"
            <<"\n                    |"<<"CREDITOS"<<"                    "<<"EXIT       |"<<endl;        
    }
    else if(pos==2){
        cout<<"                    |"<<"NEW GAME"<<"                    "<<"LOAD GAME  |"
            <<"\n                    |"<<"CREDITOS"<<char(17)<<"                   "<<"EXIT       |"<<endl;         
    }   
    else{
        cout<<"                    |"<<"NEW GAME"<<"                    "<<"LOAD GAME  |"
            <<"\n                    |"<<"CREDITOS"<<"                    "<<"EXIT     "<<char(17)<<" |"<<endl;         
    }
    cout<<"                     ";
    for(int i=0;i<40;i++)cout<<"-";
    cout<<endl;
}
void Juego::Menu_head()const{
    cout<"\n\n\n\n\n\n\n\n";
    cout<<"     "<<"                                 KRANKY"
            <<"     "<<"\n                                        GAME\n"<<endl;
    cout<<"                     ";  
    for(int i=0;i<40;i++)cout<<"-";
    cout<<endl;
}
int Juego::Calc_estado(int x,int y)const{
    int caso=0;
    if(x==0 && y==0) caso=0;
    else if(x==0) caso =1;
    else if(y==0) caso=2;
    else caso=3;
    return caso;
}int* Juego::Array_index()const{
    int * index =new int[NUMFILE-2],aleatorio;
    for(int j=0;j<NUMFILE-2;++j) index[j]=-1;
    for(int i=0;i<NUMFILE-2;i++){
        aleatorio= rand()%(NUMFILE-2);
        for(int j=0;j<NUMFILE-2;++j){
            if(index[j]==aleatorio){
                aleatorio=rand()%(NUMFILE-2);
                j=-1;
            }
            else if(index[j]==-1){
                index[j]=aleatorio;
                break;
            }
        }
    }
    return index;    
}
bool Juego::Batalla(Avatar& heroe, Monstruo& mon)const{
    int vidaHeroe = heroe.GetVidaActual();
    int vidaMonstruo = mon.GetVidaActual();
    int danho1 = heroe.obtenDanho(1);
    int danho2 = heroe.obtenDanho(2);
    while ((vidaHeroe != 0) && (vidaMonstruo != 0)){
        int accion; //Selecciona si Ataco, Uso saco o Huyo
        int selAtk; //Selecciona cual de los 2 ataques del arma usare
        //Que desea hacer?
        //Si desea atacar
        if (accion == 0){ //ATaco
            //Que ataque desea uasar?
            //Imprime el ataque que usa
            //Usa ataque
            if (selAtk == 1){ //Ataque 1
                if (heroe.verificaMana(1))
                    heroe.disminuyeMana(1);
                mon.recibeDanio(danho1); //Disminuir vida monstruo
            }
            else if (selAtk == 2){ //Ataque 2
                if (heroe.verificaMana(2))
                    heroe.disminuyeMana(2);
                mon.recibeDanio(danho2); //Disminuir vida monstruo
            }
            if (mon.GetVidaActual() == 0) break;
            //Monstruo ataca
            int danhoMons = mon.GetAtaque();
            //Disminuir vida heroe
            heroe.recibeDanio(danhoMons);
        }
        //Si desea usar pocion
        if (accion ==1){
            //Sacar elemento del saco
            int pos;
            Artefacto* art = heroe.retiraArtefacto(pos);
            //Usarlo en el heroe
            art->usar(heroe);
        }
        //Si desea huir
        else if (accion == 2){
            return 2;
        }
        if (heroe.GetVidaActual() == 0) return 1;
        else{
            int pos;
            Artefacto* artMon = mon.retiraArtefacto(pos);
            heroe.recogeArtefacto(artMon);
            return 0;
        }
    }
}
