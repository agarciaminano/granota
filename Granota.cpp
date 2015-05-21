#include "Granota.h"

/**
 * Constructor per defecte.
 */
Granota::Granota()
{
}

/**
 * Constructor de la Granota.
 * @param grafic Grafic amb el que ilustrar la granota
 * @param posicioInicialX Posició inicial en coordenada horitzontal
 * @param posicioInicialY Posició inicial en coordenada vertical
 */
Granota::Granota(Grafic grafic[MAX_ESTATS][MAX_GRAFICS], int posicioInicialX, int posicioInicialY)
{
	for (int i = 0; i < MAX_ESTATS; i++)
		for (int j = 0; j < MAX_GRAFICS;j++)
			m_grafic[i][j] = grafic[i][j];
	m_posicioInicialX = posicioInicialX;
	m_posicioInicialY = posicioInicialY;
	m_posicioX = posicioInicialX;
	m_posicioY = posicioInicialY;
	m_estat = ESTAT_REPOS;
	m_graficNum = 0;
	m_durada = DURADA_MOVIMENT;
}

/**
 * Destructor per defecte.
 */
Granota::~Granota()
{
}

/**
 * Obté l'àrea ocupada per la granota.
 * @return Area ocupada
 */
Area Granota::getAreaOcupada()
{
	// TODO emplenar
	return Area(m_posicioX, m_posicioX + m_grafic[ESTAT_REPOS][0].getScaleX(), m_posicioY, m_posicioY + m_grafic[ESTAT_REPOS][0].getScaleY());
}

/**
 * Dibuixa la granota a la posició actual.
 */
void Granota::dibuixa()
{
	m_grafic[m_estat][m_graficNum].dibuixa(m_posicioX, m_posicioY);
}

/**
 * Mou la granota cap a l'esquerra.
 */
void Granota::mouEsquerra()
{
	// Si la posició de la granota és més gran que el límit esquerra + el desplaçament de cada moviment
	
		// Movem la granota cap a l'esquerra
	if (m_estat == ESTAT_REPOS) {
		m_posicioX -= DESPLACAMENT_GRANOTA*2/10;
		m_graficNum = 3;
		m_estat = ESTAT_MOVIMENT;
	}

	
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	// Si la posició de la granota és més gran que el límit esquerra + el desplaçament de cada moviment

		// Movem la granota cap a l'esquerra
	if (m_estat == ESTAT_REPOS) {
		m_posicioX += DESPLACAMENT_GRANOTA;
		m_graficNum = 1;
		m_estat = ESTAT_MOVIMENT;
	}
		
	
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{
	
		// Movem la granota cap a l'esquerra
	if (m_estat == ESTAT_REPOS) {
		m_posicioY -= DESPLACAMENT_GRANOTA*2/10;
		m_graficNum = 0;
		m_estat = ESTAT_MOVIMENT;
	}
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	if (m_estat == ESTAT_REPOS) {
		m_posicioY += DESPLACAMENT_GRANOTA;
		m_graficNum = 2;
		m_estat = ESTAT_MOVIMENT;
	}

}

/**
 * Mou la granota a la seva posició inicial.
 */
void Granota::mouAPosicioInicial()
{
	m_posicioX = m_posicioInicialX;
	m_posicioY = m_posicioInicialY;
	estatDefecte();
	
}
void Granota::estatDefecte() {
	m_estat = ESTAT_REPOS;
	m_graficNum = 0;
}

void Granota::actualitzaEstat() {
	if (m_estat == ESTAT_MOVIMENT)
	{
		m_durada--;
		if (m_durada == 0){
			if (m_graficNum == 0)
				m_posicioY -= DESPLACAMENT_GRANOTA * 8 / 10;
			else if (m_graficNum == 3)
				m_posicioX -= DESPLACAMENT_GRANOTA * 8 / 10;
			m_estat = ESTAT_REPOS;
			m_durada = DURADA_MOVIMENT;
	}
	}
}