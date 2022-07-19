#ifndef FUNCIONES_DADOS_H_INCLUDED
#define FUNCIONES_DADOS_H_INCLUDED

///PROTOTIPOS ///
void ponerCero(int v[], int tam);
void  cargarAleatorio ( int v [], int tam, int limite);
void  mostrarVector(int v[], int tam);
void mostrarVectorMAXIMOS(int v[], int tam);
int  maximoVector ( int v [], int tam);
int  contarNumerosRepetidos ( int v [], int tam, int numero);
void  cargaManual (int v[],int tam);



void BIENVENIDOS(int i);
void jugadorSolo(char v1[]);
void jugadores (char v[], int tam);
int rondasJUGAR ();
void rondaYjugador(int i, char jugador[]);
int apostar ();
int CincoTiradas(int i, char jug[],int Ap);
int muestraSUMA (int i,char jug [],int apuesta,int suma,int MAXtirada[]);
int FINALpuntoTotal(int SD, int Ap, int pT[],int pP);
void PUNTOStotal (int sumaDADOS,int apuesta, int puntajeTOTAL[]);
void NumGenDePuntos( int i, int sumaDADOS, int apuesta, int puntajeTOTAL[]);
void ResumenFinal(char Jug[], int pT[],int pP, int PTL[]);


int CincoTiradasManuales(int i, char jug[], int apuesta);
int NumGenDePuntosAUTO(int i, int sumaDADOS,int apuesta, int puntajeTOTAL);
int PUNTOStotalAUTO (int sumaDADOS,int apuesta, int puntajeTOTAL);
int NumGenDePuntosMANO(int i, int sumaDADOS,int apuesta, int puntajeTOTAL);
int PUNTOStotalMANO (int sumaDADOS,int apuesta, int puntajeTOTAL);

int FINALpuntosTotalesAUTO(int sumaDADOS, int apuesta, int puntajeTOTAL);
int FINALpuntosTotalesMANO(int sumaDADOS, int apuesta, int puntajeTOTAL);

void jugadorMAYORpunto (int Mp[],char jug[],char jug1[],char jug2[]);


void Ganador2Jugadores(int Pt1, int Pt2, char jug[], char jug2);
void Ganador2JugadoresMANO(int Pt1, int Pt2, char jug[], char jug2[]);
void GanadorSOLOmano(char jug[], int Pt);

///DESARROLLO DE FUNCIONES///



void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}


void cargarAleatorio(int v[], int tam, int limite){
     for(int i=0; i<tam; i++ ){
      v[i]=(rand()%limite)+1;
  }
}


void mostrarVector(int v[], int tam){


    for(int i=0;i<tam;i++){
            gotoxy(27+(i*10),10);
        textcolor(cGRIS_CLARO);
        cout<<v[i]<<"\t";
    }
}

void mostrarVectorMAXIMOS(int v[], int tam){
    for(int i=0;i<tam;i++){
            gotoxy(50+(i*10),5);
        textcolor(cGRIS_CLARO);
        cout<<v[i]<<"\t";
    }
}


int maximoVector(int v[], int tam){
    int posMax=0;
    for(int i=1;i<tam;i++){
        if(v[i]>v[posMax]){
                posMax=i;
        }
    }
    return posMax;
}


int contarNumerosRepetidos(int v[], int numero, int tam){


    int cant=0;
    for(int i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void cargaManual(int v[],int tam){
     for(int i=0;i<tam;i++){
     gotoxy(27+(i*10),10);
     textcolor(cGRIS_CLARO);
     cin>>v[i];
     }
}


///------------------------------------------------------------------------------------///

void BIENVENIDOS(int i){


     clrscr();
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(42,5+i);
     cout<<"BIENVENIDOS AL JUEGO DE DADOS 20"<<endl;
}

void jugadorSolo(char v1[]){


     gotoxy(27,8);
     cout<<"JUGADOR "<<("\t")<< "NOMBRE: ";
     textcolor(cGRIS_CLARO);
     cin>>v1;
}

void jugadores (char v1[], char v2[]){
    for(int x=1;x<=2;x++){
       if(x==1){
        gotoxy(27,7);
       cout<<"JUGADOR 1"<<("\t")<< "NOMBRE: ";
       textcolor(cGRIS_CLARO);
       cin>>v1;
    }
     else{
          gotoxy(27,8);
          textcolor(cCIAN);
          cout<<"JUGADOR 2"<<("\t")<< "NOMBRE: ";
          textcolor(cGRIS_CLARO);
          cin>>v2;
         }
    }
}


int rondasJUGAR (){
    int R;
    textcolor(cCIAN);
    gotoxy(27,10);
    cout<<"CUANTAS RONDAS SE JUGARAN? : ";
    textcolor(cGRIS_CLARO);
    cin>>R;
    if(R<1){
        return -1;
    }
    return R;
}


void rondaYjugador(int i, char jugador[]){
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(27,4);
     cout<<"RONDA: ";
     gotoxy(34,4);
     textcolor(cGRIS_CLARO);
     cout<<i;
     gotoxy(40,4);
     textcolor(cCIAN);
     cout<<"JUGADOR: ";
     gotoxy(49,4);
     textcolor(cGRIS_CLARO);
     cout<<jugador;
}


int apostar (){
    int A;
    gotoxy(27,6);
    textcolor(cCIAN);
    cout<<"CUANTO VAS A APOSTAR? : ";
    textcolor(cGRIS_CLARO);
    cin>>A;
    if(A<1){
        return -1;
    }
    return A;
}


int CincoTiradas(int i, char jug[],int Ap){
    int pos,maximoTIRADAS[5],ResAlea[5], sumaDADOS=0;

    for(int x=5;x>=1;x=x-1){
    if(x<=4){
          recuadro(25, 1, 67, 16, cGRIS, cNEGRO);
    textcolor(cCIAN);
    gotoxy(27,3);
    textcolor(cCIAN);
    gotoxy(27,3);
    cout<<"RONDA: ";
    gotoxy(35,3);
    textcolor(cGRIS_CLARO);
    cout<<i;
    gotoxy(40,3);
    textcolor(cCIAN);
    cout<<"JUGADOR: ";
    gotoxy(50,3);
    textcolor(cGRIS_CLARO);
    cout<<jug;
    gotoxy(65,3);
    textcolor(cCIAN);
    cout<<"APUESTA: ";
    gotoxy(75,3);
    textcolor(cGRIS_CLARO);
    cout<<Ap;

    gotoxy(27,5);
    textcolor(cCIAN);
    cout<<"MAXIMO DE CADA TIRADA: ";
    mostrarVectorMAXIMOS(maximoTIRADAS,5-x);
    cout<<endl<<endl;
    }
    gotoxy(27,8);
    textcolor(cCIAN);
    cout<<"TIRAMOS "<<x<<" DADOS"<<endl;
    cargarAleatorio(ResAlea,5,6);
    mostrarVector(ResAlea,x);
    cout<<endl<<endl;

    pos=maximoVector(ResAlea,x);
    maximoTIRADAS[5-x]=ResAlea[pos];

    gotoxy(27,12);
    textcolor(cCIAN);
    cout<<"TIRADA Nro: ";
    gotoxy(40,12);
    textcolor(cGRIS_CLARO);
    cout<<6-x;
    gotoxy(45,12);
    textcolor(cCIAN);
    cout<<"MAXIMO: ";
    gotoxy(54,12);
    textcolor(cGRIS_CLARO);
    cout<<ResAlea[pos];

    sumaDADOS=sumaDADOS+ResAlea[pos];
    system ("pause>nul");
    system("cls");
 }

    sumaDADOS=muestraSUMA(i,jug,Ap,sumaDADOS,maximoTIRADAS);
    return sumaDADOS;
}


int muestraSUMA (int i,char jug [],int apuesta,int suma,int MAXtirada[]){
    recuadro(23, 1, 73, 16, cGRIS, cNEGRO);
    textcolor(cCIAN);
    gotoxy(27,3);
    cout<<"RONDA: ";
    gotoxy(35,3);
    textcolor(cGRIS_CLARO);
    cout<<i;
    gotoxy(40,3);
    textcolor(cCIAN);
    cout<<"JUGADOR: ";
    gotoxy(50,3);
    textcolor(cGRIS_CLARO);
    cout<<jug;
    gotoxy(65,3);
    textcolor(cCIAN);
    cout<<"APUESTA: ";
    gotoxy(75,3);
    textcolor(cGRIS_CLARO);
    cout<<apuesta;

    gotoxy(27,5);
    textcolor(cCIAN);
    cout<<"MAXIMO DE CADA TIRADA: ";
    mostrarVectorMAXIMOS(MAXtirada,5);
    gotoxy(27,7);
    textcolor(cCIAN);
    cout<<"SUMA DE LOS DADOS: ";
    gotoxy(48,7);
    textcolor(cGRIS_CLARO);
    cout<<suma<<endl;
return suma;
}


int FINALpuntoTotal(int SD, int Ap, int pT[],int pP){
    if(SD>=20){
       PUNTOStotal(SD,Ap,pT);
    }
    else {
      recuadro(27, 10, 65, 5, cROJO, cNEGRO);
                 gotoxy(45,12);
                 textcolor(cROJO);
                 cout<<"NO LLEGASTE AL PUNTAJE MINIMO.";
                 gotoxy(37,13);
                 cout<<"PERDISTE LOS PUNTOS APOSTADOS EN ESTA RONDA";
    pT[0]=pT[0]-Ap;
    pP++;
   }
    return pP;
}


void PUNTOStotal (int sumaDADOS,int apuesta, int puntajeTOTAL[]){

int i;
switch (sumaDADOS){
        case 20:NumGenDePuntos(i=1, sumaDADOS, apuesta, puntajeTOTAL);
                break;

        case 21:NumGenDePuntos(i=2, sumaDADOS, apuesta, puntajeTOTAL);
                break;

        case 22:NumGenDePuntos(i=3, sumaDADOS, apuesta, puntajeTOTAL);
                break;

        case 23:NumGenDePuntos(i=4, sumaDADOS, apuesta, puntajeTOTAL);
                break;

         case 24:NumGenDePuntos(i=5, sumaDADOS, apuesta, puntajeTOTAL);
                 break;

         case 25:NumGenDePuntos(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                 break;

         default:NumGenDePuntos(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                 break;
 }

}
void NumGenDePuntos( int i, int sumaDADOS, int apuesta, int puntajeTOTAL[]){
          int dado5[5],numero,puntaje;
                 gotoxy(27,9);
                textcolor(cCIAN);
                cout<<"NUMERO GENERADOR DE PUNTO: ";
                gotoxy(55,9);
                textcolor(cGRIS_CLARO);
                 cout<<i;
                 system("pause>nul");
                 system("cls");

                 recuadro(23, 1, 80, 16, cGRIS, cNEGRO);
                   gotoxy(26,4);
                 textcolor(cCIAN);
                 cout<<"ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR >>";
                 gotoxy(81,4);
                 textcolor(cGRIS_CLARO);
                 cout<<i;
                 gotoxy(83,4);
                 textcolor(cCIAN);
                 cout<<"<<, SE SUMAN PUNTOS";

                 system("pause>nul");
                 gotoxy(27,8);
                 cout<<"SE VUELVEN A TIRAR 5 DADOS";
                 cargarAleatorio(dado5,5,6);
                 mostrarVector(dado5,5);
                 cout<<endl<<endl;
                 numero=contarNumerosRepetidos(dado5,i,5);
                 puntaje=apuesta*numero;
                 gotoxy(27,14);
                 textcolor(cCIAN);
                 cout<<"PUNTAJE: ";
                 gotoxy(36,14);
                 textcolor(cGRIS_CLARO);
                 cout<<puntaje;
                 puntajeTOTAL[0]=puntajeTOTAL[0]+puntaje;
                 if(puntaje==0){
                 puntajeTOTAL[1]=puntajeTOTAL[1]+1;
                 }
}


void ResumenFinal(char Jug[], int pT[],int pP){
    recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
    textcolor(cCIAN);
    gotoxy(53,6);
    cout<<"RESULTADO FINAL";
     gotoxy(27,8);
     cout<<">> JUGADOR: ";

     gotoxy(39,8);
     textcolor(cGRIS_CLARO);
     cout<<Jug<<endl;

     gotoxy(27,10);
     textcolor(cCIAN);
     cout<<">> TOTAL DE RONDAS SIN PUNTOS: ";

     gotoxy(58,10);
     textcolor(cGRIS_CLARO);
     cout<<pT[1]<<endl;

     gotoxy(27,12);
     textcolor(cCIAN);
     cout<<">> TOTAL DE RONDAS CON PERDIDAS DE PUNTOS: ";

     gotoxy(70,12);
     textcolor(cGRIS_CLARO);
     cout<<pP<<endl;

     gotoxy(27,14);
     textcolor(cCIAN);
     cout<<">> PUNTAJE TOTAL: ";

     gotoxy(45,14);
     textcolor(cGRIS_CLARO);
     cout<<pT[0]<<endl;
}


///---------------------------------------------------------------------------------------///



int CincoTiradasManuales(int i, char jug[], int apuesta){
    int pos,maximoTIRADAS[5],ResAlea[5], sumaDADOS=0;

     for(int x=5;x>=1;x=x-1){
        if(x<=4){
    recuadro(25, 1, 67, 16, cGRIS, cNEGRO);
    textcolor(cCIAN);
    gotoxy(27,3);
    textcolor(cCIAN);
    gotoxy(27,3);
    cout<<"RONDA: ";
    gotoxy(35,3);
    textcolor(cGRIS_CLARO);
    cout<<i;
    gotoxy(40,3);
    textcolor(cCIAN);
    cout<<"JUGADOR: ";
    gotoxy(50,3);
    textcolor(cGRIS_CLARO);
    cout<<jug;
    gotoxy(65,3);
    textcolor(cCIAN);
    cout<<"APUESTA: ";
    gotoxy(75,3);
    textcolor(cGRIS_CLARO);
    cout<<apuesta;


   gotoxy(27,5);
   textcolor(cCIAN);
   cout<<"MAXIMO DE CADA TIRADA: ";
   mostrarVectorMAXIMOS(maximoTIRADAS,5-x);
       cout<<endl<<endl;
   }

   gotoxy(27,8);
   textcolor(cCIAN);
   cout<<"TIRAMOS "<<x<<" DADOS"<<endl<<endl;
   cargaManual(ResAlea,x);

   mostrarVector(ResAlea,x);
   cout<<endl<<endl;

   pos=maximoVector(ResAlea,x);
   maximoTIRADAS[5-x]=ResAlea[pos];

    gotoxy(27,12);
    textcolor(cCIAN);
    cout<<"TIRADA Nro: ";
    gotoxy(40,12);
    textcolor(cGRIS_CLARO);
    cout<<6-x;
    gotoxy(45,12);
    textcolor(cCIAN);
    cout<<"MAXIMO: ";
    gotoxy(54,12);
    textcolor(cGRIS_CLARO);
    cout<<ResAlea[pos];

    sumaDADOS=sumaDADOS+ResAlea[pos];
    system ("pause>nul");
    system("cls");
        }

sumaDADOS=muestraSUMA(i,jug,apuesta,sumaDADOS,maximoTIRADAS);
return sumaDADOS;
}


int NumGenDePuntosAUTO(int i, int sumaDADOS,int apuesta, int puntajeTOTAL){
int  dado5[5],numero,puntaje;
     gotoxy(27,9);
     textcolor(cCIAN);
     cout<<"NUMERO GENERADOR DE PUNTO: ";
     gotoxy(55,9);
     textcolor(cGRIS_CLARO);
     cout<<i;

     system("pause>nul");
     system("cls");

     recuadro(23, 1, 80, 16, cGRIS, cNEGRO);
     gotoxy(26,4);
     textcolor(cCIAN);
     cout<<"ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR >>";
     gotoxy(81,4);
     textcolor(cGRIS_CLARO);
     cout<<i;
     gotoxy(83,4);
     textcolor(cCIAN);
     cout<<"<<, SE SUMAN PUNTOS";

     system("pause>nul");
     gotoxy(27,8);
     cout<<"SE VUELVEN A TIRAR 5 DADOS";


     cargarAleatorio(dado5,5,6);
     mostrarVector(dado5,5);
     cout<<endl<<endl;
     numero=contarNumerosRepetidos(dado5,i,5);
     puntaje=apuesta*numero;
     gotoxy(27,14);
     textcolor(cCIAN);
     cout<<"PUNTAJE: ";
     gotoxy(36,14);
     textcolor(cGRIS_CLARO);
     cout<<puntaje;
     puntajeTOTAL=puntajeTOTAL+puntaje;

    return puntajeTOTAL;
}


int PUNTOStotalAUTO (int sumaDADOS,int apuesta, int puntajeTOTAL){
    int i;

switch (sumaDADOS){
                case 20: puntajeTOTAL=NumGenDePuntosAUTO(i=1, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 21: puntajeTOTAL=NumGenDePuntosAUTO(i=2, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 22: puntajeTOTAL=NumGenDePuntosAUTO(i=3, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 23: puntajeTOTAL=NumGenDePuntosAUTO(i=4, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 24: puntajeTOTAL=NumGenDePuntosAUTO(i=5, sumaDADOS, apuesta, puntajeTOTAL);
                       break;

                case 25: puntajeTOTAL=NumGenDePuntosAUTO(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                default: puntajeTOTAL=NumGenDePuntosAUTO(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                       break;

        }
        return puntajeTOTAL;
}


int NumGenDePuntosMANO(int i, int sumaDADOS,int apuesta, int puntajeTOTAL){
    int  dado5[5],numero,puntaje;
    gotoxy(27,9);
    textcolor(cCIAN);
    cout<<"NUMERO GENERADOR DE PUNTO: ";
    gotoxy(55,9);
    textcolor(cGRIS_CLARO);
    cout<<i;
    system("pause>nul");
    system("cls");
    recuadro(23, 1, 80, 16, cGRIS, cNEGRO);
    gotoxy(26,4);
    textcolor(cCIAN);
    cout<<"ULTIMO TIRO DE LA RONDA. POR CADA DADO CON EL VALOR >>";
    gotoxy(81,4);
    textcolor(cGRIS_CLARO);
    cout<<i;
    gotoxy(83,4);
    textcolor(cCIAN);
    cout<<"<<, SE SUMAN PUNTOS";
    system("pause>nul");
    gotoxy(27,8);
    cout<<"SE VUELVEN A TIRAR 5 DADOS";
    cargaManual(dado5,5);

    mostrarVector(dado5,5);

    numero=contarNumerosRepetidos(dado5,i,5);
    puntaje=apuesta*numero;
    gotoxy(27,14);
    textcolor(cCIAN);
    cout<<"PUNTAJE: ";
    gotoxy(36,14);
    textcolor(cGRIS_CLARO);
    cout<<puntaje;
    puntajeTOTAL=puntajeTOTAL+(puntaje);
    return puntajeTOTAL;
}


int PUNTOStotalMANO (int sumaDADOS,int apuesta, int puntajeTOTAL){


int i;

switch (sumaDADOS){
                case 20: puntajeTOTAL=NumGenDePuntosMANO(i=1, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 21: puntajeTOTAL=NumGenDePuntosMANO(i=2, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 22: puntajeTOTAL=NumGenDePuntosMANO(i=3, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 23: puntajeTOTAL=NumGenDePuntosMANO(i=4, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 24: puntajeTOTAL=NumGenDePuntosMANO(i=5, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                case 25: puntajeTOTAL=NumGenDePuntosMANO(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

                default: puntajeTOTAL=NumGenDePuntosMANO(i=6, sumaDADOS, apuesta, puntajeTOTAL);
                        break;

        }
        return puntajeTOTAL;
   }


int FINALpuntosTotalesAUTO(int sumaDADOS, int apuesta, int puntajeTOTAL ){

if(sumaDADOS>=20){
   puntajeTOTAL=PUNTOStotalAUTO(sumaDADOS,apuesta,puntajeTOTAL);
   }
   else{
        recuadro(27, 10, 65, 5, cROJO, cNEGRO);
        gotoxy(45,12);
        textcolor(cROJO);
        cout<<"NO LLEGASTE AL PUNTAJE MINIMO.";
        gotoxy(37,13);
        cout<<"PERDISTE LOS PUNTOS APOSTADOS EN ESTA RONDA";
        puntajeTOTAL=puntajeTOTAL-apuesta;
    }
        return puntajeTOTAL;
}


int FINALpuntosTotalesMANO(int sumaDADOS, int apuesta, int puntajeTOTAL ){


if(sumaDADOS>=20){
   puntajeTOTAL=PUNTOStotalMANO(sumaDADOS,apuesta,puntajeTOTAL);
   }
   else{
        recuadro(27, 10, 65, 5, cROJO, cNEGRO);
        gotoxy(45,12);
        textcolor(cROJO);
        cout<<"NO LLEGASTE AL PUNTAJE MINIMO.";
        gotoxy(37,13);
        cout<<"PERDISTE LOS PUNTOS APOSTADOS EN ESTA RONDA";
        puntajeTOTAL=puntajeTOTAL-apuesta;
    }
        return puntajeTOTAL;
}


void jugadorMAYORpunto (int Mp[],char jug[],char jug1[],char jug2[],char jugS[],char jug1S[],char jug2S[]){

int pos;
    clrscr();
    recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
    textcolor(cCIAN);

     gotoxy(48,6);
     cout<<">> MEJOR PUNTUACION <<"<<endl;

if((Mp[0] || Mp[1] || Mp[2] || Mp[3] || Mp[4] || Mp[5])!=0){
pos=maximoVector(Mp,6);
switch(pos){
           case 0: gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jug;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[0];
           break;

           case 1:gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jug1;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[1];

                break;

           case 2:gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jug2;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[2];
               break;

           case 3:gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jugS;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[3];
            break;

           case 4:gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jug1S;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[4];
           break;

           case 5:gotoxy(27,10);
                cout<<"JUGADOR CON MAYOR PUNTAJE: ";
                gotoxy(54,10);
                textcolor(cGRIS_CLARO);
                cout<<jug2S;

                gotoxy(27,12);
                textcolor(cCIAN);
                cout<<"PUNTOS TOTALES: ";
                gotoxy(43,12);
                textcolor(cGRIS_CLARO);
                cout<<Mp[5];
            break;

}
}
      else{
        if((Mp[0] && Mp[1] && Mp[2] && Mp[3] && Mp[4] && Mp[5])==0) {
        recuadro(37, 11, 45, 4, cROJO, cNEGRO);
        gotoxy(43,13);
        textcolor(cROJO);
        cout<<"TODAVIA NO SE REGISTRARON PUNTAJES"<<endl;
      }
}
}


void Ganador2JugadoresMANO(int Pt1, int Pt2, char jug[], char jug2[]){
      if(Pt1>Pt2){
        recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
        textcolor(cCIAN);
        gotoxy(50,6);
        cout<<"RESULTADO FINAL";
        gotoxy(27,9);
        cout<<">> JUGADOR GANADOR: ";

        gotoxy(47,9);
        textcolor(cGRIS_CLARO);
        cout<<jug<<endl;


        gotoxy(27,12);
        textcolor(cCIAN);
        cout<<">> PUNTAJE TOTAL: ";

        gotoxy(45,12);
        textcolor(cGRIS_CLARO);
        cout<<Pt1<<endl;
    }
     else{
         recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
         textcolor(cCIAN);
         gotoxy(50,6);
         cout<<"RESULTADO FINAL";
         gotoxy(27,9);
         cout<<">> JUGADOR GANADOR: ";

         gotoxy(47,9);
         textcolor(cGRIS_CLARO);
         cout<<jug2<<endl;


         gotoxy(27,12);
         textcolor(cCIAN);
         cout<<">> PUNTAJE TOTAL: ";

         gotoxy(45,12);
         textcolor(cGRIS_CLARO);
         cout<<Pt2<<endl;
         }
}


void GanadorSOLOmano(char jug[], int Pt){
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(50,6);
     cout<<"RESULTADO FINAL";
     gotoxy(27,9);
     cout<<">> JUGADOR : ";

     gotoxy(41,9);
     textcolor(cGRIS_CLARO);
     cout<<jug<<endl;


     gotoxy(27,12);
     textcolor(cCIAN);
     cout<<">> PUNTAJE TOTAL: ";

     gotoxy(45,12);
     textcolor(cGRIS_CLARO);
     cout<<Pt<<endl;


}


void Ganador2Jugadores(int Pt1, int Pt2, char jug[], char jug2[]){
    if(Pt1 && Pt2 == 0){
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(50,6);
     cout<<"RESULTADO FINAL";
     gotoxy(30,10);
     textcolor(cROJO);
     cout<<"*** NINGUNO DE LOS 2 PARTICIPANTES ACUMULARON PUNTOS ***";
     pause();
     return;
    }

    if(Pt1>Pt2){
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(50,6);
     cout<<"RESULTADO FINAL";
     gotoxy(27,9);
     cout<<">> JUGADOR GANADOR: ";

     gotoxy(47,9);
     textcolor(cGRIS_CLARO);
     cout<<jug<<endl;


     gotoxy(27,12);
     textcolor(cCIAN);
     cout<<">> PUNTAJE TOTAL: ";

     gotoxy(45,12);
     textcolor(cGRIS_CLARO);
     cout<<Pt1<<endl;
    }
     else{
     recuadro(25, 3, 67, 16, cGRIS, cNEGRO);
     textcolor(cCIAN);
     gotoxy(50,6);
     cout<<"RESULTADO FINAL";
     gotoxy(27,9);
     cout<<">> JUGADOR GANADOR: ";

     gotoxy(47,9);
     textcolor(cGRIS_CLARO);
     cout<<jug2<<endl;

     gotoxy(27,12);
     textcolor(cCIAN);
     cout<<">> PUNTAJE TOTAL: ";

     gotoxy(45,12);
     textcolor(cGRIS_CLARO);
     cout<<Pt2<<endl;
     }
}

#endif // FUNCIONES_DADOS_H_INCLUDED
