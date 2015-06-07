#include "Pantalla.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor de la Pantalla.
 */
Pantalla::Pantalla()
{
	m_numeros = Puntuacio();
	creaGrafics();
	creaCoves();
	m_generador = Aleatori();
	m_bonus = Bonus(m_graficSorpresa);
	// Inicialitzem l'area total de la pantalla, així com l'espai pels carrils, el número de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X, FI_X, INICI_Y, FI_Y);
	m_iniciCarrilsY = INICI_Y + m_graficCova.getScaleY();
	m_bonusPunts = false;
	m_bonusVides = false;
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
	for (int i = 0; i < MAX_TEMP; i++)
		m_graficTemp[i].destrueix();
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
	m_graficSorpresa.crea("Program/data/GraficsGranota/sorpresa.png");
	m_graficTemp[0].crea("Program/data/numeros/numero0000.png");
	m_graficTemp[1].crea("Program/data/numeros/numero0001.png");
	m_graficTemp[2].crea("Program/data/numeros/numero0002.png");
	m_graficTemp[3].crea("Program/data/numeros/numero0003.png");
	m_graficTemp[4].crea("Program/data/numeros/numero0004.png");
	m_graficTemp[5].crea("Program/data/numeros/numero0005.png");
	m_graficTemp[6].crea("Program/data/numeros/numero0006.png");
	m_graficTemp[7].crea("Program/data/numeros/numero0007.png");
	m_graficTemp[8].crea("Program/data/numeros/numero0008.png");
	m_graficTemp[9].crea("Program/data/numeros/numero0009.png");

}
/**
 * Inicia la pantalla instanciant l'objecte vehicle i colocant la granota i el vehicle a la posició inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicialitzacioNivell(int nivell)
{
	m_granotaActual = 0;
	
	m_tempo[TEMP_JOC] = Temporitzador(m_graficTemp, 7 - nivell, 0); // 60,50 y 40 segons pels nivells 1 2 i 3 respectivament.
	m_tempo[TEMP_SORPRESA] = Temporitzador(m_graficTemp, 2 , 0); /// TEMPORITZADOR per els bonus aleatoris cada 20 segons
	m_tempo[TEMP_COTXES] = Temporitzador(m_graficTemp, 0, 5); // Temporitzador per parar els cotxes (bonus)
	for (int i = 0; i < MAX_CARRILS; i++) {
		int velocitat;
		if (i == CARRIL_3)
			velocitat = VELOCITAT_CAMIO;
		else if (i == CARRIL_1)
			velocitat = VELOCITAT_F1;
		else 
			velocitat = VELOCITAT_COTXES;
		m_cova[i].setOcupada(false);
		m_carrils[i] = Carril(i % 2, m_graficVehicle[i], m_iniciCarrilsY + i * 60, velocitat,nivell);
	
			
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
		posicio_X_Inici = m_cova[i].getParetDreta().getMaxX();
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
	i--;
	if (esDins) {
		m_cova[i].setOcupada(true);
		m_granota[m_granotaActual].estatDefecte();
		m_granota[m_granotaActual].mouPosAbs((m_cova[i].getParetEsquerra().getMinX() + m_cova[i].getParetDreta().getMaxX()) / 2 - 20,
			( m_cova[i].getParetDreta().getMaxY()) / 2-10);
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
void Pantalla::dibuixa(int puntuacio)
{
	// TODO emplenar
	m_graficFons.dibuixa(m_areaTotal.getMinX(), m_areaTotal.getMinY());
	for (int i = 0; i < MAX_CARRILS; i++)
	{
		Cua cua = m_carrils[i].getVehicle();
		Iterador it = cua.getInici();
		while (!it.esNul())
		{
			it.getElement().dibuixa();
			it.seguent();
		}
		m_cova[i].dibuixa();
	}
	for (int i = 0; i <= m_granotaActual;i++)
		m_granota[i].dibuixa();

	m_numeros.dibuixa(puntuacio);
	m_bonus.dibuixa();
	if (m_tempo[TEMP_SORPRESA].haAcabatElTemps())
	{
		
		m_bonus.setX(m_generador.generaAleatori(INICI_X + 10, FI_X-m_graficSorpresa.getScaleX()));
		m_bonus.setY(m_generador.generaAleatori(m_iniciCarrilsY, FI_Y_CARRILS));
		m_tempo[TEMP_SORPRESA].inicialitza();
	}
		
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
	
	for (int i = 0; i < MAX_CARRILS; i++)
		{
		m_carrils[i].mouVehicle();
		Cua cua = m_carrils[i].getVehicle();
			if (!espaiPermesVehicles(cua.getPrimer().getAreaOcupada()))
				m_carrils[i].haArribatAlFinal();
			m_carrils[i].actualitzaEstat();
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
		Cua cua = m_carrils[i].getVehicle();
		Iterador it = cua.getInici();
		while (!it.esNul() && !colisio)
		{
			Area areaVehicle = it.getElement().getAreaOcupada();
			colisio = comprovaColisio(areaGranota, areaVehicle);
				
			it.seguent();
		}
	
	}
	bool tempsAcabat = m_tempo[TEMP_JOC].haAcabatElTemps();
	if (tempsAcabat)
		m_tempo[TEMP_JOC].inicialitza();
	return colisio || tempsAcabat; // TODO modificar
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
* També actualitza el temporitzador i comprova si la granota ha colisionat amb l'objecte bonus
* @return void.
*/
void Pantalla::actualitza(){
	m_tempo[TEMP_JOC].dibuixa();
	m_tempo[TEMP_JOC].actualitzaTemps();
	m_tempo[TEMP_SORPRESA].actualitzaTemps();
	m_granota[m_granotaActual].actualitzaEstat();
	if (comprovaColisio(m_granota[m_granotaActual].getAreaOcupada(), m_bonus.getAreaOcupada()))
		colisioBonus();
	if (m_carrils[0].getTempsAturat())
	{
		m_tempo[TEMP_COTXES].actualitzaTemps();
		if (m_tempo[TEMP_COTXES].haAcabatElTemps())
		{
			for (int i = 0; i < MAX_CARRILS; i++)   //// Comprovem si ha pasat el temps que els vehicles han d'estar aturats i els desaturem
				m_carrils[i].setTempsAturat(false);
			m_tempo[TEMP_COTXES].inicialitza();
		}

	}
	
}

bool Pantalla::comprovaColisio(Area a1, Area a2)
{
	return a1.solapa(a2);
}

/* Selecciona un bonus entre els disponibles al agafar el objecte bonus del joc.
*/
void Pantalla::colisioBonus() {
	
	switch (m_generador.generaAleatori(0, MAX_BONUS))
	{
	case 0: m_bonusPunts = true;
		break;
	case 1: m_bonusVides = true;
		break;
	case 2:
		for (int i = 0; i < MAX_CARRILS; i++) {
			m_carrils[i].setTempsAturat(true);
		}
		break;
	default:
		break;
	}
	m_bonus.setX(-100);
	m_bonus.setY(-100);
}

bool Pantalla::getBonusPunts() {
	return m_bonusPunts;
}

bool Pantalla::getBonusVides() {
	return m_bonusVides;
}
void Pantalla::setBonusVides() {
	m_bonusVides = false;
}
void Pantalla::setBonusPunts() {
	m_bonusPunts = false;
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
	
		x_min = m_granota[m_granotaActual].getAreaOcupada().getMinX() + DESPLACAMENT_GRANOTA;
		x_max = m_granota[m_granotaActual].getAreaOcupada().getMaxX() + DESPLACAMENT_GRANOTA;
		y_min = m_granota[m_granotaActual].getAreaOcupada().getMinY();
		y_max = m_granota[m_granotaActual].getAreaOcupada().getMaxY();
		novaArea = Area(x_min, x_max, y_min, y_max);
		if (espaiPermes(novaArea))
			m_granota[m_granotaActual].mouDreta();
		break;
	}
	case ESQUERRA:{
		
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

