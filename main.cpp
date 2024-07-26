#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <windows.h>
#include "funciones.h"



using namespace std;

int main(){

    int x;
    string jugadorUno="---",jugadorDos="---",jugadorTres="---",jugadorMax="---";
    int puntUno=0, puntDos=0, puntTres=0;
    int may=0;
    bool h=true;


    while(h==true){

    recuadro();

    gotoxy(24,4);cout<< " ¡BIENVENIDO AL JUEGO DE DADOS ESCALERA!"<<endl<<endl<<endl;
    gotoxy(14,8);cout<< "   ================================================" <<endl;
    gotoxy(14,9);cout<< "   =            1 - UN JUGADOR                    ="<<endl;
    gotoxy(14,10);cout<< "   =            2 - DOS JUGADORES                 ="<<endl;
    gotoxy(14,11);cout<< "   =            3 - PUNTUACION MAS ALTA           =" <<endl;
    gotoxy(14,12);cout<< "   =            4 - MODO SIMULADO                 =" <<endl;
    gotoxy(14,13);cout<< "   =            5 - SALIR                         ="<<endl;
    gotoxy(14,14);cout<< "   ================================================"<<endl<<endl;
    gotoxy(14,16);cout<< "   Seleccion: ";


    cin>>x;

    system("cls");

    switch(x){
        case 1:
            unJugador();
            system("pause");
            system("cls");
            ///puntMax;
            break;

        case 2:
            dosJugadores();
            //puntMax;
            break;

        case 3:///se agregó la opción de puntaje maximo (funciona para los dos jugadores)
        	mostrarPuntajeMax();
           /// puntuacion;
            system("pause");
            system("cls");
            break;

        case 4:
            simulado();//jugadorTres);
           /// puntMax;
            system("pause");
            system("cls");
            break;

        case 5:
        cout<<endl<<endl<<"¿Seguro que desea salir?"<<endl<< "1 - SI   |   0 - NO"<<endl<<endl<< "Selección: ";
        cin>>x;
        if(x==1){
            system("cls");
            h=false;
           }
            system("cls");
            break;

        default: cout<<endl<<"Ha ingresado una opción incorrecta. Inténtelo de nuevo."<<endl<<endl;
        system("pause");
        system("cls");
        break;
        }
    }
        system("cls");

return 0;
}
/// Escalera / Sexteto / case3: que de bien la puntuacion maxima. 18 de Julio
/// MODO SIMULADO (agregar a mano valor a los dados)
