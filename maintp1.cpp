#include <iostream>
#include "juegotp1.h"
#define TAMANIO_TABLERO 10
using namespace std;


int main(){

	cout<<"BIENVENIDO A LA BATALLA CAMPAL\n";
	juegoPrincipal juego = juegoPrincipal();
		
	char turno='1';
	juego.mostrar();
    juego.posicionamientoInicial();
    juego.mostrar();
    
    while ((juego.contadores('1')>0) && (juego.contadores('2')>0)){ // se repite el juego hasta que algun jugador se quede sin soldados
        juego.iniciarJuego(turno);
        juego.archivoJugadas(turno);
        
        if (turno=='1'){ // cambia de turno cada vez que termina de ejecutar la funcion y se repite la funcion pero con otro turno
            turno='2';
        }
        else if (turno=='2'){
            turno='1';
        }
    }
    
    if((juego.contadores('1'))==0 && (juego.contadores('2'))==0) {
    	cout<<"EMPATE"<<endl;
    }
    else if((juego.contadores('1'))==0){
        cout<<"Gana el jugador 2"<<endl;
    }
    else if ((juego.contadores('2'))==0){
        cout<<"Gana el jugador 1"<<endl;
    }
    
    return 0;
}
