#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "juegotp1.h"
#define TAMANIO_TABLERO 10
using namespace std;


// RELLENA LA MATRIZ CON '?' ANTES DE INICIAR EL JUEGO
juegoPrincipal::juegoPrincipal(){
	int i,j;
    char turno ='1';
    for (i=0;i<TAMANIO_TABLERO;i++){
        for (j=0;j<TAMANIO_TABLERO;j++){
            matriz[i][j]='?';
        }
	}
	
	
}

// MUESTRA EL TABLERO
void juegoPrincipal :: mostrar(){
    for (int i=0;i<TAMANIO_TABLERO;i++){
        for (int j=0;j<TAMANIO_TABLERO;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// ESCRITURA DE TABLERO EN ARCHIVO
void juegoPrincipal :: archivoJugadas(char turno){
	if (turno=='1'){
        ofstream archivo("Tablero Jugador 1.txt", std::fstream::app); // si no encuentra un archivo lo crea
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++ ){
                archivo<<matriz[i][j]<<' ';
                }
            archivo<<"\n";
        }
        archivo<<"\n";
        archivo.close();
	}
	if (turno=='2'){
        ofstream archivo("Tablero Jugador 2.txt", std::fstream::app); // si no encuentra un archivo lo crea
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++ ){
                archivo<<matriz[i][j]<<' ';
                }
            archivo<<"\n";
        }
        archivo<<"\n";
        archivo.close();
	}
	
	
}

// CUENTA LOS SOLDADOS DE CADA JUGADOR
int juegoPrincipal :: contadores(char jugador){
    int contador=0;
    for(int i=0;i<TAMANIO_TABLERO;i++){
        for(int j=0;j<TAMANIO_TABLERO;j++){
            if ((matriz[i][j]==jugador)){
                contador++;
            }
        }
    }
    return contador;
}

// SE COLOCAN LOS SOLDADOS
void juegoPrincipal :: posicionamientoInicial(){
    int fila;
    int columna;
    int cont_jugadores=0;
    int jugador=1;
    
    
    for (int i=0;i<6;i++){
        cout<<"Ingrese la posicion del soldado (jugador "<<jugador<<")"<<"\n";
        cout<<"Ingrese la fila: "<<endl;cin>>fila;
        cout<<"Ingrese la columna: "<<endl;cin>>columna;
        while (matriz[fila-1][columna-1]=='2'){
            cout<<"ERROR, no se puede reemplazar al jugador 2"<<endl;
            cout<<"Ingrese la fila: "<<endl;cin>>fila;
            cout<<"Ingrese la columna: "<<endl;cin>>columna;
        }
        while (matriz[fila-1][columna-1]=='1'){
            cout<<"ERROR, no se puede reemplazar al jugador 1"<<endl;
            cout<<"Ingrese la fila: "<<endl;cin>>fila;
            cout<<"Ingrese la columna: "<<endl;cin>>columna;
        }
        if (jugador==1){
            matriz[fila-1][columna-1]='1';
            cont_jugadores++;
        }
        else if (jugador==2){
            matriz[fila-1][columna-1]='2';
            cont_jugadores++;
        }
        if (cont_jugadores==3){
            jugador++;
        }
        
    }

}


void juegoPrincipal :: iniciarJuego(char turno){
    int fila;
    int columna;
    int fila_mov;
    int columna_mov;
    char enemigo;
    char seleccion;
    if (turno=='1'){
        enemigo='2';
    }
    
    else if (turno=='2'){
        enemigo='1';
    }
    int fila_final, columna_final;
    
    cout<<"JUGADOR "<<turno<<" Ingrese a donde desea disparar: "<<endl;
    cout<<"Ingrese la fila: "<<endl;cin>>fila;
    cout<<"Ingrese la columna: "<<endl;cin>>columna;
    while (matriz[fila-1][columna-1]==turno){
            cout<<"FRIENDLY FIRE! No podes matar a tus companieros"<<endl;
            cout<<"Ingrese la fila: "<<endl;cin>>fila;
            cout<<"Ingrese la columna: "<<endl;cin>>columna;
    }
    if (matriz[fila-1][columna-1]==enemigo){
        matriz[fila-1][columna-1]='x';
        cout<<"Mataste a un soldado enemigo"<<endl;
        mostrar();
    }
    else if (matriz[fila-1][columna-1]=='?'){
        cout<<"Fallaste el tiro"<<endl;
        matriz[fila-1][columna-1]='"';
        mostrar();
    }
        
    else if (matriz[fila-1][columna-1]=='x'){
        cout<<"Casilla inactiva"<<endl;
    }
    
    //MOVIMIENTO
    cout<<"Desea mover un soldado ? s para 'si', otro para 'no'"<<endl;cin>>seleccion;
    if (seleccion=='s'){
    
        cout<<"JUGADOR "<<turno<<" ingrese el soldado que desea mover: "<<endl;
        cout<<"Ingrese la fila: "<<endl;cin>>fila;
        cout<<"Ingrese la columna: "<<endl;cin>>columna;
        while(matriz[fila-1][columna-1]!=turno){
            cout<<"No tenes soldados en esas posiciones"<<endl;
            cout<<"Ingrese la fila: "<<endl;cin>>fila;
            cout<<"Ingrese la columna: "<<endl;cin>>columna;
        }
        matriz[fila-1][columna-1]='"';
        
        cout<<"A que posicion desea mover el soldado? "<<endl;
        cout<<"Ingrese la fila: "<<endl;cin>>fila_mov;
        cout<<"Ingrese la columna: "<<endl;cin>>columna_mov;
        
        fila_final=fila_mov-fila;
        columna_final=columna_mov-columna;
    
        while((fila!=fila_mov && columna!=columna_mov) && (abs(fila_final)!=abs(columna_final))){
            cout<<"No te podes mover a esta posicion, unicamente vertical, horizontal o diagonal"<<endl;
            cout<<"Ingrese la fila donde va su soldado: ";cin>>fila_mov;
            cout<<"Ingrese la columna donde va su soldado: ";cin>>columna_mov;
            fila_final=fila_mov-fila;
            columna_final=columna_mov-columna;
        }
        if(matriz[fila_mov-1][columna_mov-1]==turno){
            cout<<"No podes reemplazar a tus jugadores"<<endl;
        }
        else if (matriz[fila_mov-1][columna_mov-1]==enemigo){
            cout<<"Colocaste a tu soldado en la posicion del enemigo"<<endl;cout<<"Ambos mueren por punialadas"<<endl;
            matriz[fila_mov-1][columna_mov-1]='x';
        }
        else if(matriz[fila_mov-1][columna_mov-1]=='?'){
            matriz[fila_mov-1][columna_mov-1]=turno;
        }
        else if (matriz[fila_mov-1][columna_mov-1]=='x'){
            cout<<"No se puede mover a posiciones inactivas"<<endl;
            matriz[fila-1][columna-1]=turno;
        }
        else if (matriz[fila_mov-1][columna_mov-1]=='"'){
            matriz[fila_mov-1][columna_mov-1]=turno;
            matriz[fila-1][columna-1]='"';
        }
    }    
    mostrar();
}
