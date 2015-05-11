#include "Area.h"

/**
 * Constructor per defecte.
 */
Area::Area()
{
}

/**
 * Constructor d'una àrea rectangular no inclinada.
 * @param minX Mínima coordenada horitzontal
 * @param maxX Màxima coordenada horitzontal
 * @param minY Mínima coordenada vertical
 * @param maxY Màxima coordenada vertical
 */
Area::Area(int minX, int maxX, int minY, int maxY)
{
	m_minX = minX;
	m_maxX = maxX;
	m_minY = minY;
	m_maxY = maxY;
}

/**
 * Destructor per defecte.
 */
Area::~Area()
{
}

/**
 * Obté la mínima coordenada horitzontal.
 * @return mínima coordenada horitzontal
 */
int Area::getMinX()
{
	return m_minX;
}

/**
 * Obté la màxima coordenada horitzontal.
 * @return màxima coordenada horitzontal
 */int Area::getMaxX()
{
	return m_maxX;
}

/**
 * Obté la mínima coordenada vertical.
 * @return mínima coordenada vertical
 */
int Area::getMinY()
{
	return m_minY;
}

/**
 * Obté la màxima coordenada vertical.
 * @return màxima coordenada vertical
 */
int Area::getMaxY()
{
	return m_maxY;
}

/**
 * Comprova si un punt donat pertany a l'area.
 * @param x Coordenada horitzontal del punt
 * @param y Coordenada vertical del punt
 * @return true si hi pertany i false si no hi pertany.
 */
bool Area::pertany(int x, int y)
{
	bool pert_ok = false;
	
	if ((x >= getMinX()) && (x <= getMaxX())){
		if (y >= getMinY() && y<= getMaxY()) pert_ok = true;
	}
	return pert_ok;
}

/**
 * Comprova si una àrea donada està inclosa dins l'àrea.
 * @param area L'àrea donada que es vol comprovar.
 * @return true si l'àrea donada està inclosa, false si no.
 */
bool Area::inclou(Area area)
{

	return pertany(area.getMinX(), area.getMinY()) &&
		pertany(area.getMaxX(), area.getMaxY()); 
}

/**
 * Comprova si l'àrea donada es solapa amb l'àrea.
 * Nota: dues àrees se solapen si la intersecció entre elles no és buida.
 * Assumpció: El cas en què dos rectangles formen una creu no cal que el tingueu en compte, no es donarà en aquest projecte.
 * @param area L'àrea a comprovar
 * @return true si es solapen i false si no.
 */
bool Area::solapa(Area area)
{
	bool impacte = false;

	//Comprovem primer que el area B no solapi a la area A mitjançant algun dels punts de l'area que passem per parametre.
	if (pertany(area.getMinX(), area.getMinY()) || pertany(area.getMinX(), area.getMaxY()) || pertany(area.getMaxX(), area.getMinY()) || pertany(area.getMaxX(), area.getMaxY()))
		impacte = true;

	//O si no comprovem que el area A no solapi a l'area B, es a dir a l'inreves.
	else if (area.pertany(m_minX, m_minY) || area.pertany(m_maxX, m_minY) || area.pertany(m_minX, m_maxY) || area.pertany(m_maxX, m_maxY))
		impacte = true;


	return impacte;
}