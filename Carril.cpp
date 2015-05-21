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
	
	Vehicle v = m_vehicles.treu();
	m_cont = m_delay;
	if (m_orientation == CARRIL_DRET)
		v.mou(fi_pantalla,m_posY);
	else{
		
			v.mou(0 - (v.getAreaOcupada().getMaxX() - v.getAreaOcupada().getMinX()), m_posY);
	}
	m_vehicles.afegeix(v);
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