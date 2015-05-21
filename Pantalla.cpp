#include "Pantalla.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor de la Pantalla.
 * Aquesta pantalla té una sola cova imaginària ja que no té parets.
 */
Pantalla::Pantalla()
{
	creaGrafics();
	creaCoves();
	// Inicialitzem l'area total de la pantalla, així com l'espai pels carrils, el número de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X, FI_X, INICI_Y, FI_Y);
	m_iniciCarrilsY = INICI_Y + m_graficCova.getScaleY();
	
	for (int i = 0; i < MAX_VIDES; i++) {
		m_vides[i] = Granota(m_graficsGranota, INICI_X_VIDES + (m_graficsGranota[0][0].getScaleX()*i), INICI_Y_VIDES);
	}
	
	// Fixem l'hora actual com a llavor pel generador d'aleatoris.
	std::srand(std::time(0));
}

/**
 * Destructor per defecte
 */
Pantalla::~Pantalla()
{
	m_graficFons.destrueix();
	m_graficCova.destrueix();
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		m_graficVehicle[i].destrueix();
		m_carrils[i].destrueixCua();
	}
	for (int i = 0; i < MAX_ESTATS; i++)
		for (int j = 0; j < MAX_GRAFICS; j++)
			m_graficsGranota[i][j].destrueix();
	
}
/**
* Crea els components gràfics que es faràn servir durant el joc
*/
void Pantalla::creaGrafics() {

	m_graficFons.crea("Program/data/GraficsGranota/Fons.png");
	m_graficCova.crea("Program/data/GraficsGranota/Cova120.png");
	m_graficVehicle[0].crea("Program/data/GraficsGranota/Cotxe_1.png");
	m_graficVehicle[1].crea("Program/data/GraficsGranota/Cotxe_2.png");
	m_graficVehicle[2].crea("Program/data/GraficsGranota/Cotxe_3.png");
	m_graficVehicle[3].crea("Program/data/GraficsGranota/Camio.png");
	m_graficVehicle[4].crea("Program/data/GraficsGranota/Tractor.png");
	m_graficsGranota[0][0].crea("Program/data/GraficsGranota/Granota_Amunt_1.png");
	m_graficsGranota[1][0].crea("Program/data/GraficsGranota/Granota_Amunt_2.png");
	m_graficsGranota[0][1].crea("Program/data/GraficsGranota/Granota_Dreta_1.png");
	m_graficsGranota[1][1].crea("Program/data/GraficsGranota/Granota_Dreta_2.png");
	m_graficsGranota[0][2].crea("Program/data/GraficsGranota/Granota_Avall_1.png");
	m_graficsGranota[1][2].crea("Program/data/GraficsGranota/Granota_Avall_2.png");
	m_graficsGranota[0][3].crea("Program/data/GraficsGranota/Granota_Esquerra_1.png");
	m_graficsGranota[1][3].crea("Program/data/GraficsGranota/Granota_Esquerra_2.png");
}
/**
 * Inicia la pantalla instanciant l'objecte vehicle i colocant la granota i el vehicle a la posició inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicialitzacioNivell(int nivell)
{
	m_granotaActual = 0;
	for (int i = 0; i < MAX_CARRILS; i++) {
		m_cova[i].setOcupada(false);
		m_carrils[i] = Carril(i * 15 + 30, i % 2, m_graficVehicle[i], m_iniciCarrilsY + i * 60);
		if (m_carrils[i].getOrientation() == CARRIL_DRET)
				m_carrils[i].mouIniciCarril(FI_X );
		else
			m_carrils[i].mouIniciCarril(INICI_X);
			
	}
	
}


/**
* Inicialitza posicio granota, vehicles mantenen posicio, coves mantenen granotes.
* Agafa la següent granota a ficar a la següent cova, i la mou a la posicio inicial.
*
*/
void Pantalla::inicialitzacioGranota()
{
	
	m_granota[m_granotaActual].mouAPosicioInicial();
}


/**
* Crea cadascuna de les 5 coves.
*/

void Pantalla::creaCoves()
{
	int posicio_X_Inici = 0;
	for (int i = 0; i < MAX_COVES; i++)
	{
		m_cova[i] = Cova(m_graficCova, posicio_X_Inici, INICI_Y);
		posicio_X_Inici += m_cova[i].getParetDreta().getMaxX();
		m_granota[i] = Granota(m_graficsGranota, (FI_X - INICI_X - m_graficsGranota[0][0].getScaleX()) / 2, INICI_Y_GRANOTA);
	}
}
/**
 * Comprova si la granota actual es troba dins la cova.
 * @param area Area a comprovar si es troba dins una cova.
 * @return true si l'àrea es troba dins la cova i false si no s'hi troba. 
 */

/**
*Comprova si la granota esta en algunes de les coves no ocupades.
*
*/


/**
* Mètode que comprova si la granota actual en moviment esta dins d'una de les coves no ocupades.
*/
bool Pantalla::esGranotaDinsCova()
{
	int i = 0;
	bool esDins = false;
	while (i < MAX_COVES && esDins == false){
		esDins = m_cova[i].esDins(m_granota[m_granotaActual].getAreaOcupada());
		i++;
	}

	
	if (esDins) {
		m_cova[i - 1].setOcupada(true);
		m_granota[m_granotaActual].estatDefecte();
		m_granotaActual++;
	}
	
	
	return esDins;
}

/**
*
*/
bool Pantalla::esGranotaDinsCoves()
{
	
	int	i = 0;
	bool ok = true;
	while (i < MAX_COVES && ok){
		ok = m_cova[i].getOcupada();
		i++;
	}


	return ok;
	
}

/**
 * Comprova si la granota es troba dins l'espai permés de moviment (Cova,Pantalla)
 * @param area Area a comprovar si es troba dins l'espai permés de moviment.
 * @return true si l'àrea es troba dins l'espai permés de moviment i false si no és així.
 */
bool Pantalla::espaiPermes(Area area)
{
	bool solapaCova = false;
	int i = 0;
	//Comprovem totes les coves fins que solapi amb alguna o bé les haguem comprovat totes
	while (!solapaCova && i < MAX_COVES)
	{
		//Si estem intentant accedir al interior de una cova pe
		solapaCova = m_cova[i].esAccessible(area);
		i++;
	}

	return (m_areaTotal.inclou(area) && !solapaCova);

}

bool Pantalla::espaiPermesVehicles(Area area)
{
	return ((m_areaTotal.pertany(area.getMaxX(), area.getMinY()))
		|| (m_areaTotal.pertany(area.getMinX(), area.getMinY())));
}

/**
* Mètode que dibuixa tots els elements de la pantalla: fons, coves, cotxes, gespa, granota.
*/
void Pantalla::dibuixa()
{
	// TODO emplenar
	m_graficFons.dibuixa(m_areaTotal.getMinX(), m_areaTotal.getMinY());
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		m_carrils[i].getVehicle().dibuixa();
		m_cova[i].dibuixa();
	}
	for (int i = 0; i <= m_granotaActual;i++)
		m_granota[i].dibuixa();

	
		
}

void Pantalla::pintaVides(int vides)
{
	for (int i = 0; i < vides; i++)
		m_vides[i].dibuixa();
}


/**
 * Mou el vehicle.
 */
void Pantalla::mouVehicle()
{
	
	for (int i = 0; i < MAX_CARRILS; i++) {
		if (m_carrils[i].potCircular())
		{
			if (espaiPermesVehicles(m_carrils[i].getVehicle().getAreaOcupada()))
				m_carrils[i].mouVehicle();
			else
				m_carrils[i].mouIniciCarril(FI_X);
				
		}
		else {
			m_carrils[i].actualitzaEstat();
			
			
						
		}
	}
}

/**
 * Comprova si la granota ha mort.
 * @return true si la granota és morta i false si és viva.
 */
bool Pantalla::haMortLaGranota()
{
	bool colisio = false;
	Area areaGranota = m_granota[m_granotaActual].getAreaOcupada();
	for (int i = 0; i < MAX_CARRILS; i++) {
		Area areaVehicle = m_carrils[i].getVehicle().getAreaOcupada();

		if (areaGranota.solapa(areaVehicle))
			colisio = true;
	}
	return colisio; // TODO modificar
}

/**
* Mètode que comprova si totes les granotes estan dins de les coves.
* @return true si estan totes o false si no.
*/
bool Pantalla::nivellSuperat(){
	return esGranotaDinsCoves();
}

/**
* Mètode que actualitza els moviments referents a la granota: estat de repos i moviment.
* @return void.
*/
void Pantalla::actualitza(){
	m_granota[m_granotaActual].actualitzaEstat();
}

/**
 * Mou la granota en la direcció donada.
 * @param direccio Direcció cap on s'ha de moure la granota. Fer servir constants AMUNT, AVALL, DRETA i ESQUERRA.
 */
void Pantalla::mouGranota(int direccio)
{   
	
	int x_min,x_max,y_min,y_max;
	Area novaArea;
		switch (direccio)
		{
		case AMUNT:{
			
			x_min = m_granota[m_granotaActual].getAreaOcupada().getMinX();
			x_max = m_granota[m_granotaActual].getAreaOcupada().getMaxX();
			y_min = m_granota[m_granotaActual].getAreaOcupada().getMinY() - DESPLACAMENT_GRANOTA;
			y_max = m_granota[m_granotaActual].getAreaOcupada().getMaxY() - DESPLACAMENT_GRANOTA;
			novaArea = Area(x_min, x_max, y_min, y_max); 
			if (espaiPermes(novaArea))
				m_granota[m_granotaActual].mouAmunt();
			break;
		}

		case DRETA: {
			/*
			x = m_granota.getAreaOcupada().getMaxX();
			y = m_granota.getAreaOcupada().getMaxY();
			novaArea = Area(x, x + DESPLACAMENT_GRANOTA,y,y);
			*/
			x_min = m_granota[m_granotaActual].getAreaOcupada().getMinX() + DESPLACAMENT_GRANOTA;
			x_max = m_granota[m_granotaActual].getAreaOcupada().getMaxX() + DESPLACAMENT_GRANOTA;
			y_min = m_granota[m_granotaActual].getAreaOcupada().getMinY();
			y_max = m_granota[m_granotaActual].getAreaOcupada().getMaxY();
			novaArea = Area(x_min, x_max,y_min,y_max);
			if (espaiPermes(novaArea))
				m_granota[m_granotaActual].mouDreta();
			break;
		}
		case ESQUERRA:{
			/*
			 x = m_granota.getAreaOcupada().getMinX();
			 y = m_granota.getAreaOcupada().getMaxY();
			 novaArea = Area(x-DESPLACAMENT_GRANOTA, x , y, y);
			*/
			x_min = m_granota[m_granotaActual].getAreaOcupada().getMinX() - DESPLACAMENT_GRANOTA;
			x_max = m_granota[m_granotaActual].getAreaOcupada().getMaxX() - DESPLACAMENT_GRANOTA;
			y_min = m_granota[m_granotaActual].getAreaOcupada().getMinY();
			y_max = m_granota[m_granotaActual].getAreaOcupada().getMaxY();
			novaArea = Area(x_min, x_max, y_min, y_max);
			if (espaiPermes(novaArea))
				m_granota[m_granotaActual].mouEsquerra();
			break;
		}
		case AVALL:{
			/*
			x = m_granota.getAreaOcupada().getMinX();
			y = m_granota.getAreaOcupada().getMaxY();
			novaArea = Area(x , x, y, y + DESPLACAMENT_GRANOTA);
			*/
			x_min = m_granota[m_granotaActual].getAreaOcupada().getMinX();
			x_max = m_granota[m_granotaActual].getAreaOcupada().getMaxX();
			y_min = m_granota[m_granotaActual].getAreaOcupada().getMinY() + DESPLACAMENT_GRANOTA;
			y_max = m_granota[m_granotaActual].getAreaOcupada().getMaxY() + DESPLACAMENT_GRANOTA;
			novaArea = Area(x_min, x_max, y_min, y_max);
			if (espaiPermes(novaArea))
				m_granota[m_granotaActual].mouAvall();
		}
		default:
			break;
		}
	}



int Pantalla::getGranotaActual() const
{
	return m_granotaActual;
}

