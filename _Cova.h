#pragma once
#include "Area.h"
#include "lib\Grafic.h"

#define BORDE_COVA 20

class Cova
{
public:
	Cova();
	Cova(Grafic grafic, int posicioX, int posicioY);
	~Cova();
	void Cova::dibuixa();
	bool esAccessible(Area area);
	bool esDins(Area area);
private:
	int m_posicioX;
	int m_posicioY;
	Grafic m_grafic;
	Area m_interior;
};

