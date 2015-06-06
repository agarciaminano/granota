#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// nº de píxels que es desplaça el cotxe a cada moviment del nivell 1
const int VELOCITAT_CAMIO = 1;
const int VELOCITAT_COTXES = 2;
const int VELOCITAT_F1 = 3;

class Vehicle
{
public:
	Vehicle();
	Vehicle(Grafic grafic, int velocitat);
	~Vehicle();
	Area getAreaOcupada();
	void dibuixa();
	void mou(bool dreta);
	void mou(int x, int y);
private:
	Grafic m_grafic;
	int m_posicioX;
	int m_posicioY;
	int m_velocitat;
};

