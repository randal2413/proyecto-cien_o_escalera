#ifndef UNJUGADOR_H_INCLUDED
#define UNJUGADOR_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <algorithm>

using namespace std;

COORD coord={0,0};
//-------INTERFAZ----------------------------------

void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void linea(){
    cout<<"________________________________________________________";
}
void recuadro(){
    int j;
    for (j = 1; j < 80; j++) {
        gotoxy(j, 1);
        printf("%c", 177);

        gotoxy(j, 24);
        printf("%c", 177);
    }

    int d;
    for (d = 2; d < 24; d++) {
        gotoxy(1, d);
        printf("%c", 178);

        gotoxy(79, d);
        printf("%c", 178);
    }
        gotoxy(1, 1);
        printf("%c", 02);

        gotoxy(79, 1);
        printf("%c", 02);

        gotoxy(1, 24);
        printf("%c", 01);

        gotoxy(79, 24);
        printf("%c", 01);
}

void lanzarDados(int dados[6]) {
    for (int i = 0; i < 6; i++) {
        dados[i] = 1 + (rand() % 6);
    }
}


int calcularPuntaje(int dados[6]) {

    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++){
                if(dados[i]>dados[j]){
                    int temp = dados[i];
                    dados[i] = dados[j];
                    dados[j] = temp;
            }
        }
    } /// metodologia vista en clase si o si. metodo burbuja

    bool escalera = true;
    for (int i = 0; i < 6; i++) {
        if (dados[i] != i + 1) {
            escalera = false;
            break;
        }
    }

    cout << "Dados lanzados: ";
    for (int i = 0; i < 6; i++) {
        cout << dados[i] << " ";
    }
    cout << endl;

    if (escalera) {
        cout << "Combinacion obtenida: Escalera" << endl;
        return 9999;  //  OPCION DE RETURN retornar el puntaje
    } else {

        int puntaje = 0;
        for (int i = 0; i < 6; i++) {
            puntaje += dados[i];
        }
        cout << "Combinacion obtenida: Suma de dados" << endl;
        cout << "Puntaje obtenido: " << puntaje << endl;
        return puntaje;
    }
       system("pause");
}

//////// MODO SIMULADO ////////
void lanzarDados2(int dados[6]) {
    for (int i = 0; i < 6; i++) {
            cout<<"Ingrese el valor del dado "<<i+1<<": "<<endl;
            cin>>dados[i];
    }
}

int unJugador(){ //se añadió la de 1 jugador
	srand(time(0));
	string nombreJugador1;


	cout << "Ingrese su nombre: " << endl;
	cin >> nombreJugador1;
	system("cls");
    int puntajeTotalJugador1 = 0;
    int ronda = 1;

    while (true) {
        //  jugador 1
        cout << "Turno de " << nombreJugador1 << endl;
        cout << "Ronda: " << ronda << endl;
        cout << "Puntaje: " << puntajeTotalJugador1 << endl;
        linea();
        cout<< endl;

        int puntajeMaximoRondaJugador1 = 0;
        for (int lanzamiento = 0; lanzamiento < 3; ++lanzamiento) {
            cout << "Lanzamiento " << lanzamiento + 1 << endl;
            int dados[6];
            lanzarDados(dados);
            int puntajeLanzamiento = calcularPuntaje(dados);


            if (puntajeLanzamiento > puntajeMaximoRondaJugador1) {
                puntajeMaximoRondaJugador1 = puntajeLanzamiento;
            }
            if (puntajeMaximoRondaJugador1 == 9999){
                cout<<"Sacaste ESCALERA, ganaste!"<< endl;
                break;
                }
                system("pause");
                system("cls");
        cout << "Turno de " << nombreJugador1 << endl;
        cout << "Ronda: " << ronda << endl;
        cout << "Puntaje: " << puntajeTotalJugador1 << endl;
        linea();
        cout<< endl;
        }

        puntajeTotalJugador1 += puntajeMaximoRondaJugador1;

                system("cls");

        cout << "Resumen del turno de " << nombreJugador1 << ":" << endl;
        cout << "Ronda: " << ronda << endl;
        linea();
        cout<< endl << endl;
        cout << "Puntaje final de la ronda: " << puntajeMaximoRondaJugador1 << endl;
        cout << "Puntaje total: " << puntajeTotalJugador1 << endl;



        if (puntajeTotalJugador1 >= 100) {
            cout << "¡" << nombreJugador1 << " ha ganado la partida! en un total de "<<ronda<<" rondas" << endl;
            break;
        }
        system("pause");
          system("cls");

     ronda++;


	}
}

int puntajeMaximo = 0;

int mostrarPuntajeMax(){
    	if (puntajeMaximo > 0){
    		cout << "El puntaje maximo de la ronda es: " << puntajeMaximo << endl;
    	}
    }

int dosJugadores() {
    srand(time(0));

    string nombreJugador1, nombreJugador2;
    cout << "Ingrese el nombre del Jugador 1: ";
    cin >> nombreJugador1;
    cout << "Ingrese el nombre del Jugador 2: ";
    cin >> nombreJugador2;

        system("cls");
    int puntajeTotalJugador1 = 0;
    int puntajeTotalJugador2 = 0;
    int ronda = 1;

    while (true) {
        //  jugador 1
        cout << "Turno de " << nombreJugador1 << endl;
        cout << "Ronda: " << ronda << endl;
        linea();
        cout<< endl;
        cout << "Puntaje: " << puntajeTotalJugador1 << endl;
        int puntajeMaximoRondaJugador1 = 0;
        for (int lanzamiento = 0; lanzamiento < 3; ++lanzamiento) {
            cout << "Lanzamiento " << lanzamiento + 1 << endl;
            int dados[6];
            lanzarDados(dados);
            int puntajeLanzamiento = calcularPuntaje(dados);


            if (puntajeLanzamiento > puntajeMaximoRondaJugador1) {
                puntajeMaximoRondaJugador1 = puntajeLanzamiento;
            }
        } system("pause");
          system("cls");


        puntajeTotalJugador1 += puntajeMaximoRondaJugador1;


        cout << "Resumen del turno de " << nombreJugador1 << ":" << endl;
        cout << "Ronda: " << ronda << endl;
        cout << "Puntaje final de la ronda: " << puntajeMaximoRondaJugador1 << endl;
        cout << "Puntaje total: " << puntajeTotalJugador1 << endl;



        if (puntajeTotalJugador1 >= 100) {
            cout << "¡" << nombreJugador1 << " ha ganado la partida!" << endl;
            break;
        }
        system("pause");
          system("cls");

        cout << "Turno de " << nombreJugador2 << endl;
        cout << "Ronda: " << ronda << endl;
        linea();
        cout<< endl;
        cout << "Puntaje: " << puntajeTotalJugador2 << endl;
        int puntajeMaximoRondaJugador2 = 0;
        for (int lanzamiento = 0; lanzamiento < 3; ++lanzamiento) {
            cout << "Lanzamiento " << lanzamiento + 1 << endl;
            int dados[6];
            lanzarDados(dados);
            int puntajeLanzamiento = calcularPuntaje(dados);


            if (puntajeLanzamiento > puntajeMaximoRondaJugador2) {
                puntajeMaximoRondaJugador2 = puntajeLanzamiento;
            }
        }system("pause");
          system("cls");




        //Pide nuevamente el puntaje maximo pero en el jugador 2

        puntajeTotalJugador2 += puntajeMaximoRondaJugador2;
        if (puntajeMaximoRondaJugador2 > puntajeMaximo){
        	puntajeMaximo = puntajeMaximoRondaJugador2;
        }


        cout << "Resumen del turno de " << nombreJugador2 << ":" << endl;
        cout << "Ronda: " << ronda << endl;
        cout << "Puntaje final de la ronda: " << puntajeMaximoRondaJugador2 << endl;
        cout << "Puntaje total: " << puntajeTotalJugador2 << endl;

        if (puntajeTotalJugador2 >= 100) {
            cout << "¡" << nombreJugador2 << " ha ganado la partida!" << endl;
            break;
        }system("pause");
          system("cls");


        ronda++;
    }system("pause");
          system("cls");
    return 0;
}
/// MODO SIMULADO <<<<<<<<<<<<<<<<<<<

int simulado(){ //se añadió la de 1 jugador

	string nombreJugador1;


	cout << "Ingrese su nombre: " << endl;
	cin >> nombreJugador1;
	system("cls");
    int puntajeTotalJugador1 = 0;
    int ronda = 1;

    while (true) {
        //  jugador 1
        cout << "Turno de " << nombreJugador1 << " ||||| ";
        cout << "Ronda: " << ronda << " ||||| ";
        cout << "Puntaje total: " << puntajeTotalJugador1 << endl;
        linea();
        cout<< endl;

        int puntajeMaximoRondaJugador1 = 0;
        for (int lanzamiento = 0; lanzamiento < 3; ++lanzamiento) {
            cout << "Lanzamiento " << lanzamiento + 1 << endl;
            int dados[6];
            lanzarDados2(dados);
            int puntajeLanzamiento = calcularPuntaje(dados);


            if (puntajeLanzamiento > puntajeMaximoRondaJugador1) {
                puntajeMaximoRondaJugador1 = puntajeLanzamiento;
            }

            if (puntajeMaximoRondaJugador1 == 9999){
                cout<<"Sacaste ESCALERA, ganaste!"<< endl;
                system("pause");
                break;
                }
                system("cls");

        cout << "Turno de " << nombreJugador1 << " ||||| ";
        cout << "Ronda: " << ronda << " ||||| ";
        cout << "Puntaje total: " << puntajeTotalJugador1 << endl;
        linea();
        cout<< endl;
        }

        puntajeTotalJugador1 += puntajeMaximoRondaJugador1;

                system("cls");

        cout << "Resumen del turno de " << nombreJugador1 << " ||||| ";
        cout << "Ronda: " << ronda << " ||||| ";
        cout << "Puntaje total: " << puntajeTotalJugador1 << endl;
        cout << "Puntaje final de la ronda: " << puntajeMaximoRondaJugador1 << endl;
        linea();
        cout<< endl;





        if (puntajeTotalJugador1 >= 100) {
            cout << "¡" << nombreJugador1 << " ha ganado la partida! en un total de "<<ronda<<" rondas" << endl;
            break;
        }
        system("pause");
          system("cls");

     ronda++;


	}
}

#endif // FUNCIONES_H_INCLUDED
