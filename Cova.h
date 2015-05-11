#pragma once
#include "Area.h"
#include "lib\Grafic.h"

const int MAX_X_PARET_COVA=5;
const int MAX_Y_PARET_COVA=80;

const int MIN_Y_INTERIOR_COVA = 5;


class Cova
{
public:
	Cova();
	Cova(Grafic grafic, int posicioX, int posicioY);
	~Cova();

	bool getOcupada() const;
	void setOcupada(bool ocupada);

	Area getInterior();
	void setInterior(Area nouInterior);

	Area getParetEsquerra();
	void setParetEsquerra(Area novaParet);

	Area getParetDreta();
	void setParetDreta(Area novaParet);

	void Cova::dibuixa();
	bool esAccessible(Area area);
	bool esDins(Area area);
	
	

private:
	int m_posicioX;
	int m_posicioY;
	bool m_ocupada;
	Grafic m_grafic;
	Area m_interior;
	Area m_paretEsquerra;
	Area m_paretDreta;
};

