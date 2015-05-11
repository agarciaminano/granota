#include "Carril.h"

Carril::Carril() {}
	

Carril::Carril(int delay, bool orientacio, Vehicle vehicle, int posY){
	
	m_delay = delay;
	m_cont = delay;
	m_posY = posY;
	m_orientation = orientacio;
	m_vehicle = vehicle;
	


}

Carril::~Carril(){}
	
bool Carril::getOrientation() {
	return m_orientation;
}

int Carril::getY() {
	return m_posY;
}

void Carril::mouIniciCarril(int fi_pantalla) 
{
	m_cont = m_delay;
	if (m_orientation == CARRIL_DRET)
		m_vehicle.mou(fi_pantalla,m_posY);
	else
		m_vehicle.mou(0 - (m_vehicle.getAreaOcupada().getMaxX() - m_vehicle.getAreaOcupada().getMinX()), m_posY);
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
	m_vehicle.mou(!m_orientation);
}
Vehicle Carril::getVehicle()
{
	return m_vehicle;
}