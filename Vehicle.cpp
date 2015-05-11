#include "Vehicle.h"
#include "Pantalla.h"

/**
 * Constructor per defecte.
 */
Vehicle::Vehicle()
{
}

/**
 * Constructor del Vehicle.
 * @param grafic Grafic amb el que ilustrar el vehicle
 * @param velocitat Velocitat de moviment
 */
Vehicle::Vehicle(Grafic grafic, int velocitat)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
}

/**
 * Destructor per defecte.
 */
Vehicle::~Vehicle()
{
}

/**
 * Retorna l'area ocupada pel vehicle.
 */
Area Vehicle::getAreaOcupada()
{
	// TODO emplenar
	return Area(m_posicioX,m_posicioX+m_grafic.getScaleX(),m_posicioY,m_posicioY+m_grafic.getScaleY()); // TODO modificar
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Vehicle::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest.
 */
void Vehicle::mou(bool dreta)
{
	if (dreta)
		m_posicioX += m_velocitat;
	else 
		m_posicioX -= m_velocitat;
	

}

void Vehicle::mou(int x, int y) {
	m_posicioX = x;
	m_posicioY = y;
}