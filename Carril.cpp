#include "Carril.h"

Carril::Carril() {}
	

Carril::Carril(bool orientacio, Grafic vehicle, int posY,int vel_carril,int nivell)
{
	
	m_posY = posY;
	m_orientation = orientacio;
	m_tipusVehicle = vehicle;
	m_velocitat = vel_carril;
	m_tempsAturat = false;
	m_nivell = nivell;
	Vehicle v = Vehicle(vehicle, vel_carril * nivell);
	m_generador = Aleatori();
	m_freqAparicio = FREQ_APARICIO - MULT_APARICIO*(nivell);
	m_vehicles = Cua();
	mouIniciCarril(v);
	m_vehicles.afegeix(v);
	
}

Carril::~Carril()
{
}
	
/*
* Retorna la orientació del carril (Dreta o esquerra)
*/
bool Carril::getOrientation() {
	return m_orientation;
}

/*
* Retorna la coordenada Y del carril.
*/
int Carril::getY() {
	return m_posY;
}
/*
* Aquest mètode s'ha de cridar quan el primer vehicle de la cua ha arribat fins al final del carril,
* En cas de que no quedin més vehicles, moura el vehicle que ha arribat fins al final i el tornarà a afegir a la cua.
*/
void Carril::haArribatAlFinal()
{
	Vehicle v = m_vehicles.treu();	
	if (m_vehicles.esBuida()){
		mouIniciCarril (v);
		m_vehicles.afegeix(v);
	
	}
}
/*
* Envia el vehicle que rep com a parametre al inici del carril
*/
void Carril::mouIniciCarril(Vehicle& v) 
{
	if (m_orientation == CARRIL_DRET)
		v.mou(FINAL_PANTALLAX, m_posY);
	else
		{
		v.mou(0 - (v.getAreaOcupada().getMaxX() - v.getAreaOcupada().getMinX()), m_posY);
		}
	
	}

/* Elimina tots els cotxes de la cua fins buidar-la*/
void Carril::destrueixCua() {
	while (!m_vehicles.esBuida()){
		m_vehicles.treu();
		
	}
}
/* Aquest mètode actualitza l'estat dels carrils, més concretament,
genera un numero aleatori entre 0 i la frecuencia d'aparició fixada, i en cas de ser possible,
afegeix un nou cotxe al carril*/
void Carril::actualitzaEstat() {

		// si el num aleatori ha estat 0
		if (m_generador.generaAleatori(0, m_freqAparicio) == 0)
		{
			Vehicle v = Vehicle(m_tipusVehicle, m_velocitat * m_nivell);
			mouIniciCarril(v); // Afegim el vehicle sempre que no solapi amb l'ultim de la cua
			if (!(v.getAreaOcupada().solapa(m_vehicles.getUltim().getAreaOcupada())))
			{
				m_vehicles.afegeix(v);
			
			}
			
		}

	
}

/*Mou tots els vehicles de la cua de vehicles*/
void Carril::mouVehicle() {
	//Si el temps està aturat(bonus) no movem els vehicles.
	if (!m_tempsAturat)
	{
		Iterador it = m_vehicles.getInici();
		while (!it.esNul())
		{
			it.getElement().mou(!m_orientation);
			it.seguent();
		}
	}
}
/* Retorna la cua de vehicles del carril
@return cua*/
Cua Carril::getVehicle()
{
	
	return m_vehicles;
}
/* Retorna si el temps es troba aturat o no*/
bool Carril::getTempsAturat() {
	return m_tempsAturat;
}

/*Permet possar en marxa o aturar el temps, segons sigui necessari.*/
void Carril::setTempsAturat(bool b) {
	m_tempsAturat = b;
}