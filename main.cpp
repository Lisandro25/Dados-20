#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;
#include "rlutil.h"
#include "Funciones.h"

int main() {

srand(time(NULL));
    int  opc, opcSUB, rondas, apuesta;
    char jugador [15], jugador1[15], jugador2[15], jugadorS[15], jugador1S[15], jugador2S[15];
    int ResAlea[5], maximoTIRADAS[5], puntajeTOTAL[2]={0},MayorPunt[6]={0};
    int sumaDADOS=0, puntajeTOTAL1=0, puntajeTOTAL2=0, perdidaPUNTOS=0,puntajeTOTALS=0, puntajeTOTAL1S=0, puntajeTOTAL2S=0;

     while (true){
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);

     gotoxy(51,7);
     cout<<"JUEGO DE DADOS 20"<<endl;
     gotoxy(43,8);
     cout<<"--------------------------------"<<endl;
     gotoxy(43,9);
     cout<<"1. MODO PARA UN JUGADOR"<<endl;
     gotoxy(43,10);
     cout<<"2. MODO PARA DOS JUGADORES"<<endl;
     gotoxy(43,11);
     cout<<"3. MOSTRAR PUNTUACION MAS ALTA"<<endl;
     gotoxy(43,12);
     cout<<"4. MODO SIMULADO "<<endl;
     gotoxy(43,13);
     cout<<"--------------------------------"<<endl;
     gotoxy(43,14);
     cout<<"0. FIN DEL PROGRAMA"<<endl<<endl;
     gotoxy(27,16);
     cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
     textcolor(cGRIS_CLARO);
     cin>>opc;

switch (opc){
       case 1: BIENVENIDOS(1);
               jugadorSolo(jugador);
               rondas=rondasJUGAR();
               if(rondas==-1){
               gotoxy(27,13);
               textcolor(cROJO);
               cout<<"EL NUMERO DE RONDAS INGRESADOS NO PERMITIDO";
               break;
               }
               clrscr();

               for(int i=1;i<=rondas;i++){
               rondaYjugador(i,jugador);
               apuesta=apostar();
               if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
               sumaDADOS=CincoTiradas(i,jugador,apuesta);
               perdidaPUNTOS=FINALpuntoTotal(sumaDADOS,apuesta,puntajeTOTAL,perdidaPUNTOS);
               sumaDADOS=0;
               pause();
               clrscr();
               MayorPunt[0]=puntajeTOTAL[0];
               }
               if(apuesta==-1) break;
               ResumenFinal(jugador,puntajeTOTAL,perdidaPUNTOS);
               ponerCero(puntajeTOTAL,2);
               perdidaPUNTOS=0;
               break;


             ///--JUGADOR N°1--///
       case 2: BIENVENIDOS(0);
               jugadores(jugador1, jugador2);
               rondas=rondasJUGAR();
               if(rondas==-1){
               gotoxy(27,13);
               textcolor(cROJO);
               cout<<"EL NUMERO DE RONDAS INGRESADOS NO PERMITIDO";
               break;
               }
               clrscr();

               for(int i=1;i<=rondas;i++){
               rondaYjugador(i,jugador1);
               apuesta=apostar();
               if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
               sumaDADOS=CincoTiradas(i,jugador1,apuesta);
               puntajeTOTAL1=FINALpuntosTotalesAUTO(sumaDADOS,apuesta,puntajeTOTAL1);
               sumaDADOS=0;
               pause();
               clrscr();
               MayorPunt[1]=puntajeTOTAL1;

             ///--JUGADOR N°2--///
              rondaYjugador(i,jugador2);
              apuesta=apostar();
              if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
              sumaDADOS=CincoTiradas(i,jugador2,apuesta);
              puntajeTOTAL2=FINALpuntosTotalesAUTO(sumaDADOS,apuesta,puntajeTOTAL2);
              sumaDADOS=0;
              pause();
              clrscr();
              MayorPunt[2]=puntajeTOTAL2;
              }
              if(apuesta==-1) break;

              Ganador2Jugadores(puntajeTOTAL1,puntajeTOTAL2,jugador1,jugador2);
              puntajeTOTAL1=0;
              puntajeTOTAL2=0;
              break;


      case 3: jugadorMAYORpunto(MayorPunt, jugador, jugador1, jugador2, jugadorS, jugador1S, jugador2S);
              break;


      case 4: clrscr();
              recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
              textcolor(cCIAN);
              gotoxy(51,7);
              cout<<"MODO SIMULADO"<<endl;
              gotoxy(43,8);
              cout<<"--------------------------------"<<endl;
              gotoxy(43,9);
              cout<<"1. MODO UN JUGADOR"<<endl;
              gotoxy(43,10);
              cout<<"2. MODO DOS JUGADORES"<<endl;
              gotoxy(43,11);
              cout<<"0. VOLVER ATRAS"<<endl<<endl;
              gotoxy(27,13);
              cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
              textcolor(cGRIS_CLARO);
              cin>>opcSUB;

switch(opcSUB){
      case 1: BIENVENIDOS(0);
              jugadorSolo(jugadorS);
              rondas=rondasJUGAR();
              if(rondas==-1){
               gotoxy(27,13);
               textcolor(cROJO);
               cout<<"EL NUMERO DE RONDAS INGRESADOS NO PERMITIDO";
               break;
               }
              clrscr();

              for(int i=1;i<=rondas;i++){
              rondaYjugador(i,jugadorS);
              apuesta=apostar();
              if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
              sumaDADOS=CincoTiradasManuales(i,jugadorS,apuesta);

              puntajeTOTALS=FINALpuntosTotalesMANO(sumaDADOS,apuesta,puntajeTOTALS);
              sumaDADOS=0;
              pause();
              clrscr();
              MayorPunt[3]=puntajeTOTALS;
              }
              if(apuesta==-1) break;
              GanadorSOLOmano(jugadorS,puntajeTOTALS);
              puntajeTOTALS=0;
              break;


            ///--JUGADOR N°1--///
      case 2: BIENVENIDOS(0);
              jugadores(jugador1S, jugador2S);
              rondas=rondasJUGAR();
              if(rondas==-1){
               gotoxy(27,13);
               textcolor(cROJO);
               cout<<"EL NUMERO DE RONDAS INGRESADOS NO PERMITIDO";
               break;
               }
              clrscr();

              for(int i=1;i<=rondas;i++){
              rondaYjugador(i,jugador1S);
              apuesta=apostar();
              if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
              sumaDADOS=CincoTiradasManuales(i,jugador1S,apuesta);
              puntajeTOTAL1S=FINALpuntosTotalesMANO(sumaDADOS,apuesta,puntajeTOTAL1S);
              sumaDADOS=0;
              pause();
              clrscr();
              MayorPunt[4]=puntajeTOTAL1S;

            ///--JUGADOR N°2--///
              rondaYjugador(i, jugador2S);
              apuesta=apostar();
              if(apuesta==-1){
               gotoxy(27,10);
               textcolor(cROJO);
               cout<<"CANTIDAD APOSTADA NO PERMITIDA";
               pause();
               break;
               }
              sumaDADOS=CincoTiradasManuales(i,jugador2S,apuesta);
              puntajeTOTAL2S=FINALpuntosTotalesMANO(sumaDADOS,apuesta,puntajeTOTAL2S);
              sumaDADOS=0;
              pause();
              clrscr();
              MayorPunt[5]=puntajeTOTAL2S;
              }
              if(apuesta==-1) break;
              Ganador2JugadoresMANO(puntajeTOTAL1S, puntajeTOTAL2S,jugador1S,jugador2S);
              puntajeTOTAL1S=0;
              puntajeTOTAL2S=0;
              break;

      case 0:
              break;

     default: gotoxy(59,13);
              textcolor(cROJO);
              cout<<"OPCION INCORRECTA";
              }
              break;


            ///--FIN DEL PROGRAMA--///
      case 0: clrscr();
              recuadro(25, 3, 67, 6, cGRIS, cNEGRO);
              gotoxy(50,6);
              textcolor(cCIAN);
              cout<<"FIN DEL PROGRAMA"<<endl;
              gotoxy(1,20);
              return 0;
              break;

    default: gotoxy(59,16);
             textcolor(cROJO);
             cout<<"OPCION INCORRECTA";
             }
             pause();
             }
             return 0;
}



