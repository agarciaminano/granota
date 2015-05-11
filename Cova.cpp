#include "Cova.h"

/**
 * Constructor per defecte.
 */
Cova::Cova()
{
}

/**
 * Constructor de la cova.
 * Nota: Aquesta cova és imaginària.
 * @param grafic Grafic ilustrant la cova
 * @param posicioX Coordenada horitzontal de la cova
 * @param posicioY Coordenada vertical de la cova
 */
Cova::Cova(Grafic grafic, int posicioX, int posicioY)
{
	//Punt inicial (x,y) on ficarem l'imatge de la cova
	m_posicioX = posicioX;
	m_posicioY = posicioY;
	m_grafic = grafic;
	m_ocupada = false;
	/*Coordenades paret Esquerra
		0-10;
		120-130;
		330-340;
		450-460;
		570-580;
		690-700;

	*/
	m_paretEsquerra=Area(m_posicioX,m_posicioX+MAX_X_PARET_COVA,m_posicioY, m_posicioY + m_grafic.getScaleY());
	
	m_interior = Area(m_paretEsquerra.getMaxX(), m_posicioX+(m_grafic.getScaleX()-MAX_X_PARET_COVA), MIN_Y_INTERIOR_COVA, m_posicioY + m_grafic.getScaleY());
	m_paretDreta=Area(m_interior.getMaxX(),m_grafic.getScaleX(),m_posicioY,m_posicioY+m_grafic.getScaleY());
}

/**
 * Destructor per defecte.
 */
Cova::~Cova(void)
{
}

/**
*Get de l'area interior de la cova.
*
*/
bool Cova::getOcupada() const
{
	return m_ocupada;
}

/**
*Set del area interior de la cova.
*/
void Cova::setOcupada(bool ocupada)
{
	m_ocupada = ocupada;
}

/**
*Get de l'area interior de la cova.
*
*/
Area Cova::getInterior()
{
	return m_interior;
}

/**
*Set del area interior de la cova.
*/
void Cova::setInterior(Area nouInterior)
{
	m_interior = nouInterior;
}
/**
*Get de l'area de la paret dreta de la cova.
*/
Area Cova::getParetDreta()
{
	return m_paretDreta;
}

/**
*Set de l'area de la paret dreta de la cova.
*/
void Cova::setParetDreta(Area novaParet)
{
	m_paretDreta = novaParet;
}

/**
*Get de l'area de la paret esquerra de la cova.
*/
Area Cova::getParetEsquerra()
{
	return m_paretEsquerra;
}

/**
*Set de l'area de la paret esquerra de la cova.
*/
void Cova::setParetEsquerra(Area novaParet)
{
	m_paretEsquerra = novaParet;
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

	
	return (m_interior.solapa(area) && m_ocupada)
		|| m_paretDreta.solapa(area)
		|| m_paretEsquerra.solapa(area);
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

