#ifndef JUEGOPRINCIPAL_H
#define JUEGOPRINCIPAL_H
#define TAMANIO_TABLERO 10

class juegoPrincipal{
	private:
	char matriz[TAMANIO_TABLERO][TAMANIO_TABLERO];
	
	public:
		juegoPrincipal();
		void mostrar();
		void archivoJugadas(char turno);
		int contadores(char jugador);
		void posicionamientoInicial();
		void iniciarJuego(char turno);
};

#endif
