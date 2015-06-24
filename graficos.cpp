/* 
 * File:   graficos.cpp
 * Author: JuanI
 * 
 * Created on 22 de junio de 2015, 01:43 AM
 */
#include "allegro.h"
#include "winalleg.h"
#include <allegro.h>
#pragma comment(lib, "alleg.lib")
#include <winalleg.h>
#include <conio.h>



#include "graficos.h"
#define TAM 50

graficos::graficos() {
    allegro_init();
    install_timer();
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    
}

graficos::graficos(const graficos& orig) {
}

graficos::~graficos() {
}

int graficos::Movimiento(int& x,int& y)const{

    
    readkey();

 while((key[KEY_ENTER] && key[KEY_UP] && key[KEY_DOWN] && key[KEY_LEFT] && key[KEY_RIGHT])){
        readkey();
    }
    if      (key[KEY_ENTER]){ return 1;}
    else if (key[KEY_UP])   {y-=1;}
    else if (key[KEY_DOWN]) {y+=1;}
    else if (key[KEY_LEFT]) {x-=1;}
    else if (key[KEY_RIGHT]){x+=1;}
    return 0;
}
int  graficos::Recibe_tecla()const{    

    readkey();
    if (key[KEY_Y]) return 1;
    if (key[KEY_N]) return 0;
    return 0;    
}  
void graficos::Dibujar(int posX,int B,int posY,int A,int limFil,int limCol,int **matriz)const{
    int iniFil = posX - B, iniCol = posY - A,  finFil = posX + B, finCol = posY + A;
    
    //BITMAP* backBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP* avatar = load_bitmap("imagenes\\avatar.bmp",NULL);
    BITMAP* pared = load_bitmap("imagenes\\pared.bmp",NULL);
    BITMAP* inicio = load_bitmap("imagenes\\inicio.bmp",NULL);
    BITMAP* fin = load_bitmap("imagenes\\salida.bmp",NULL);
    BITMAP* piso = load_bitmap("imagenes\\piso2.bmp",NULL);
    BITMAP* artefacto = load_bitmap("imagenes\\artefacto.bmp",NULL);
    BITMAP* monstruo = load_bitmap("imagenes\\monstruo2.bmp",NULL);
   
    BITMAP* pucp = load_bitmap("imagenes\\pucp.bmp",NULL);
    
    BITMAP* vida100 = load_bitmap("imagenes\\maxvida.bmp",NULL);
    BITMAP* vida50 = load_bitmap("imagenes\\normalvida.bmp",NULL);
    BITMAP* vida0 = load_bitmap("imagenes\\pocavida.bmp",NULL);
    
    if ((posX - B) < 0) iniFil = 0;
    if ((posX + B) > limFil) finFil = limFil;
    if ((posY - A) < 0) iniCol = 0;
    if ((posY + A) > limCol) finCol = limCol;
    for(int i = iniFil; i <=finFil; i++){
        for(int j = iniCol; j <=finCol; j++){
            int valor = matriz[i][j];
            if (valor == 0){blit(piso,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,piso->w,piso->h);}
            if (valor == 1){blit(pared,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,pared->w,pared->h);}
            if (valor == 2){blit(avatar,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,avatar->w,avatar->h);}
            if (valor == 3){blit(inicio,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,inicio->w,inicio->h);}
            if (valor == 4){blit(fin,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,fin->w,fin->h);} 
            if (valor == 5){blit(artefacto,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,artefacto->w,artefacto->h);}
            if (valor == 6){blit(monstruo,screen,0,0,(i-iniFil)*TAM,(j-iniCol)*TAM,monstruo->w,monstruo->h);}
        }
    }
    blit(pucp,screen,0,0,630,560,pucp->w,pucp->h);
    blit(vida50,screen,0,0,600,400,vida50->w,vida50->h);
//    destroy_bitmap(piso);
//    destroy_bitmap(pared);
//    destroy_bitmap(avatar);
//    destroy_bitmap(inicio);
//    destroy_bitmap(fin);
}

int  graficos::Inicio()const{
    
}

int  graficos::Inventario()const{ /*Dentro debe ir las descripciones */
    
} 
int graficos::Equipamiento()const{ /*Dentro debe ir las descripciones */
    
} 
void graficos::MostrarArtefacto()const{ /*Descripcion */
    
} 
int  graficos::RecogerArtefacto()const{ /*Descripcion */
    
} 

void graficos::PantallaPrologo()const{
    BITMAP* prologo = load_bitmap("imagenes\\prologo.bmp",NULL);
    blit(prologo,screen,0,0,0,0,prologo->w,prologo->h);    
}

void graficos::PantallaNumeros(int i)const{
    if (i == 5){
        BITMAP* cinco = load_bitmap("imagenes\\cinco.bmp",NULL);
        blit(cinco,screen,0,0,0,0,cinco->w,cinco->h);    
    }
    if (i == 4){
        BITMAP* cuatro = load_bitmap("imagenes\\cuatro.bmp",NULL);
        blit(cuatro,screen,0,0,0,0,cuatro->w,cuatro->h);        
    }
    if (i == 3){
        BITMAP* tres = load_bitmap("imagenes\\tres.bmp",NULL);
        blit(tres,screen,0,0,0,0,tres->w,tres->h);        
    }
    if (i == 2){
        BITMAP* dos = load_bitmap("imagenes\\dos.bmp",NULL);
        blit(dos,screen,0,0,0,0,dos->w,dos->h);
        
    }
    if (i == 1){
        BITMAP* uno = load_bitmap("imagenes\\uno.bmp",NULL);
        blit(uno,screen,0,0,0,0,uno->w,uno->h);   
    }
    if (i == 0){
        BITMAP* cero = load_bitmap("imagenes\\fondonegro.bmp",NULL);
        blit(cero,screen,0,0,0,0,cero->w,cero->h);
    }
}

void graficos::PantallaVictoria()const{
    BITMAP* gameover = load_bitmap("imagenes\\gameover.bmp",NULL);
    blit(gameover,screen,0,0,0,0,gameover->w,gameover->h);  
}

void graficos::PantallaPerder()const{
    BITMAP* arrugon = load_bitmap("imagenes\\arrugon.bmp",NULL);
    blit(arrugon,screen,0,0,0,0,arrugon->w,arrugon->h);
    
}

void graficos::PantallaSalida()const{
    BITMAP* seguro = load_bitmap("imagenes\\areyousure.bmp",NULL);
    blit(seguro,screen,0,0,100,100,seguro->w,seguro->h);    
}


void graficos::PantallaCreditos() const{
//    BITMAP* pucp = load_bitmap("imagenes\\pucp.bmp",NULL);   
}
    
    
    /* EL HARD:*/
int graficos::InterfazCombate()const{
    
} /*Descripcion*/
