#include "Jugador.h"
/**
* Constructor per defecte
*/
Jugador::Jugador()
{
	m_nom = SENSE_NOM;
	m_puntuacio = 0;
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
* Constructor per afegir un jugador a la taula
* @param string nouNom
* @param int novaPuntuacio 
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


/**
* Get que retorna el string nom
* @return string retorna el nom.
*/
string Jugador::getNom() const
{
	return m_nom;
}

/**
* Set que posa un nou nom al jugador
* @param string nouNom
* @return void.
*/
void Jugador::setNom(string nouNom)
{
	m_nom = nouNom;
}


/**
* Get que retorna la puntuacio del jugador
* @return int puntuacio.
*/
int Jugador::getPuntuacio() const
{
	return m_puntuacio;
}

/**
* Set que posa un nou nom al jugador
* @param int novaPuntuacio
* @return void.
*/
void Jugador::setPuntuacio(int novaPuntuacio)
{
	m_puntuacio = novaPuntuacio;
}

