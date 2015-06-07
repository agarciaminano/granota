#include "Carril.h"

Carril::Carril() {}
	

Carril::Carril(bool orientacio, Grafic vehicle, int posY,int vel_carril,int nivell)
{
	
	m_posY = posY;
	m_orientation = orientacio;
	m_tipusVehicle = vehicle;
	m_velocitat = vel_carril;
	m_nivell = nivell;
	Vehicle v = Vehicle(vehicle, vel_carril * nivell);
	m_generador = Aleatori();
	m_freqAparicio = 1000 - 250*(nivell);
	m_vehicles = Cua();
	mouIniciCarril(v);
	m_vehicles.afegeix(v);
	
}

Carril::~Carril()
{
}
	
bool Carril::getOrientation() {
	return m_orientation;
}

int Carril::getY() {
	return m_posY;
}

void Carril::haArribatAlFinal()
{
	Vehicle v = m_vehicles.treu();	
	if (m_vehicles.esBuida()){
		mouIniciCarril (v);
		m_vehicles.afegeix(v);
	
	}
}
void Carril::mouIniciCarril(Vehicle& v) 
{
	if (m_orientation == CARRIL_DRET)
		v.mou(FINAL_PANTALLAX, m_posY);
	else
		{
		v.mou(0 - (v.getAreaOcupada().getMaxX() - v.getAreaOcupada().getMinX()), m_posY);
		}
	
	}

void Carril::destrueixCua() {
	while (!m_vehicles.esBuida()){
		m_vehicles.treu();
		
	}
}
void Carril::actualitzaEstat() {

		// si el num aleatori ha estat 0
		if (m_generador.generaAleatori(0, m_freqAparicio) == 0)
		{
			Vehicle v = Vehicle(m_tipusVehicle, m_velocitat * m_nivell);
			mouIniciCarril(v);
			if (!(v.getAreaOcupada().solapa(m_vehicles.getUltim().getAreaOcupada())))
			{
				m_vehicles.afegeix(v);
			
			}
			
		}

	
}


void Carril::mouVehicle() {
	Iterador it = m_vehicles.getInici();
	while (!it.esNul())
	{
		it.getElement().mou(!m_orientation);
		it.seguent();
	}
}
Cua Carril::getVehicle()
{
	
	return m_vehicles;
}

