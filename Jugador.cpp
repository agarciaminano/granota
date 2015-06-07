#include "Jugador.h"
/**
* Constructor per defecte
*/
Jugador::Jugador()
{
	//cout << "\nConstructor per defecte\n";
	
	m_nom = SENSE_NOM;
	m_puntuacio = 0;
	
	//cout << "\nJugador creat constructor defecte\n";
}

/**
* Constructor per inicialitzar el jugador quan no hi ha fitxer creat.
* @param int puntuacio
*/
Jugador::Jugador(int puntuacio)
{
	//cout << "\nConstructor (int puntuacio)\n";
	m_nom = SENSE_NOM;
	m_puntuacio = puntuacio;
}

/**
* Constructor per
*/
Jugador::Jugador(string nouNom, int novaPuntuacio)
{
	m_nom = nouNom;
	m_puntuacio = novaPuntuacio;
}
Jugador::~Jugador()
{
	//cout << "\nObjecte jugador destruit\n";
}

string Jugador::getNom() const
{
	return m_nom;
}

void Jugador::setNom(string nouNom)
{
	m_nom = nouNom;
}

int Jugador::getPuntuacio() const
{
	return m_puntuacio;
}


void Jugador::setPuntuacio(int novaPuntuacio)
{
	m_puntuacio = novaPuntuacio;
}

