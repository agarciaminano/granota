#include "Jugador.h"

Jugador::Jugador()
{
	//cout << "\nConstructor per defecte\n";
	
	m_nom = "";
	m_puntuacio = 0;
	
	//cout << "\nJugador creat constructor defecte\n";
}

Jugador::Jugador(int puntuacio)
{
	//cout << "\nConstructor (int puntuacio)\n";
	m_nom = "";
	m_puntuacio = puntuacio;
}

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

