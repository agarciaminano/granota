#include "Bonus.h"

Bonus::Bonus(Grafic grafic){
	m_grafic = grafic;
	m_posX = 0;
	m_posy = 0;
}
Bonus::Bonus() {

}
Bonus::~Bonus(){

}
void Bonus::setX(int x){
	m_posX = x;
}
void Bonus::setY(int y){
	m_posy = y;
}
void Bonus::dibuixa(){
	if (m_posX != 0 && m_posy != 0)
		m_grafic.dibuixa(m_posX,m_posy);
}