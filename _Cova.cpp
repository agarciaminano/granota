#include "Cova.h"

/**
 * Constructor per defecte.
 */
Cova::Cova()
{
}

/**
 * Constructor de la cova.
 * Nota: Aquesta cova �s imagin�ria. El seu interior ocupa tota l'amplada de la pantalla, no t� cap paret que faci d'obstacle per accedir-hi.
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
 * Dibuixa la cova a la seva posici�.
 */
void Cova::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
}

/**
 * Comprova si una �rea donada no es solapa amb cap paret de la cova.
 * @param area Area a comprovar
 * @returns true si l'�rea no es solapa amb cap parets de la cova.
 */
bool Cova::esAccessible(Area area)
{
	return true;
}

/**
 * Comprova si l'�rea donada es troba totalment a l'interior de la cova.
 * @param area Area a comprovar
 * @returns true si l'�rea es troba totalment dins la cova i false si no �s aix�.
 */
bool Cova::esDins(Area area)
{
	return m_interior.inclou(area);
}