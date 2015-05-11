#include "Cova.h"

/**
 * Constructor per defecte.
 */
Cova::Cova()
{
}

/**
 * Constructor de la cova.
 * Nota: Aquesta cova és imaginària. El seu interior ocupa tota l'amplada de la pantalla, no té cap paret que faci d'obstacle per accedir-hi.
 * @param grafic Grafic ilustrant la cova
 * @param posicioX Coordenada horitzontal de la cova
 * @param posicioY Coordenada vertical de la cova
 */
Cova::Cova(Grafic grafic, int posicioX, int posicioY)
{
	m_posicioX = posicioX;
	m_posicioY = posicioY;
	m_grafic = grafic;
	m_interior = Area(m_posicioX, m_posicioX + m_grafic.getScaleX(), m_posicioY, m_posicioY + m_grafic.getScaleY());
}

/**
 * Destructor per defecte.
 */
Cova::~Cova(void)
{
}

/**
 * Dibuixa la cova a la seva posició.
 */
void Cova::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
}

/**
 * Comprova si una àrea donada no es solapa amb cap paret de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea no es solapa amb cap parets de la cova.
 */
bool Cova::esAccessible(Area area)
{
	return true;
}

/**
 * Comprova si l'àrea donada es troba totalment a l'interior de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea es troba totalment dins la cova i false si no és així.
 */
bool Cova::esDins(Area area)
{
	return m_interior.inclou(area);
}