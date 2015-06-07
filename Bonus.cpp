#include "Bonus.h"

Bonus::Bonus(Grafic grafic){
	m_grafic = grafic;
	m_posX = 0;
	m_posY = 0;
}
Bonus::Bonus() {

}
Bonus::~Bonus(){

}
void Bonus::setX(int x){
	m_posX = x;
}
void Bonus::setY(int y){
	m_posY = y;
}
void Bonus::dibuixa(){
	if (m_posX != 0 && m_posY != 0)
		m_grafic.dibuixa(m_posX, m_posY);
}
Area Bonus::getAreaOcupada()
{
	// TODO emplenar
	return Area(m_posX, m_posX + m_grafic.getScaleX(), m_posY, m_posY + m_grafic.getScaleY()); // TODO modificar
}
