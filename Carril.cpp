#include "Carril.h"

Carril::Carril() {}
	

Carril::Carril(int delay, bool orientacio, Grafic vehicle, int posY){
	
	m_delay = delay;
	m_cont = delay;
	m_posY = posY;
	m_orientation = orientacio;
	Vehicle v = Vehicle(vehicle, DESPLACAMENT_COTXE);
	
	m_vehicles = Cua();
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

void Carril::mouIniciCarril(int fi_pantalla) 
{
	
	Iterador it = m_vehicles.getInici();
	
	m_cont = m_delay;
	if (m_orientation == CARRIL_DRET)
		it.getElement().mou(fi_pantalla, m_posY);
	else{
		
		it.getElement().mou(0 - (it.getElement().getAreaOcupada().getMaxX() - it.getElement().getAreaOcupada().getMinX()), m_posY);
	}
	
	}

void Carril::destrueixCua() {
	while (!m_vehicles.esBuida())
		m_vehicles.treu();
}
void Carril::actualitzaEstat() {
	m_cont--;
	
}

bool Carril::potCircular(){
	bool pot;
	if (m_cont == 0)
	{
		pot = true;
		
	}
	else pot = false;
	return pot;
}
void Carril::mouVehicle() {
	m_vehicles.getPrimer().mou(!m_orientation);
}
Vehicle Carril::getVehicle()
{
	return m_vehicles.getPrimer();
}