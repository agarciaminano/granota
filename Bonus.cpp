#include "Bonus.h"
/*Constructor de la clase Bonus, asigna el grafic i coloca el bonus a la seva posici� per defecte*/
Bonus::Bonus(Grafic grafic){
	m_grafic = grafic;
	m_posX = -100;
	m_posY = -100; // Posici� per defecte
}
Bonus::Bonus() {

}
Bonus::~Bonus(){

}
/*Asigna una posici� x pel bonus*/
void Bonus::setX(int x){
	m_posX = x;
}
/*Asigna una posici� Y pel bonus*/
void Bonus::setY(int y){
	m_posY = y;
}
/* Pinta el objecte bonus, si no es trova a la posici� per defecte*/
void Bonus::dibuixa(){
	if (m_posX != -100 && m_posY != -100)
		m_grafic.dibuixa(m_posX, m_posY);
}
/* Retorna el area ocupada de l'objecte */
Area Bonus::getAreaOcupada()
{
	return Area(m_posX, m_posX + m_grafic.getScaleX(), m_posY, m_posY + m_grafic.getScaleY()); 
}
