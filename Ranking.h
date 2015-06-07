#include <fstream>
#include <conio.h>
#include "Jugador.h";


const int MAX_JUGADORS = 5;
const char RUTA_FITXER[] = "ranking.txt";


const int INICI_MAYUS = 65;
const int FI_MAYUS = 90;
const int INICI_MINUS = 97;
const int FI_MINUS = 122;
const int BACKSPACE = 8;
const int INTRO = 13;
const int MAX_LONG_NOM = 16;
const int MIN_LONG_NOM = 3;
const int ESPAI = 32;
const int CARACTER_ZERO = 48;

const int FILA_PANTALLA = 1;
using namespace std;


class Ranking
{
public:
	Ranking();
	~Ranking();
	bool afegirJugador(Jugador nouJugador);
	void mostrar() const;


private:
	Jugador m_taula[MAX_JUGADORS];
	
	/*Metodes privats*/
	int castPuntuacio(string puntuacioText);
	string castPuntuacio(int puntuacio);
	
	void inicialitza();
	bool carregarRanking();
	void guardarRanking();
	
	//Funcionalitat per afegir un jugador al ranking.

	int haMilloratPuntuacio(Jugador jugadorNou);
	void desplacaArray(int posicio);
	void emplenaPosicioArray(int posicio,Jugador jugadorNou);


	
	////////////////////////////////////////////////////////////



};
