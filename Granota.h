#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// nº de píxels que es desplaça la granota a cada moviment
const int DESPLACAMENT_GRANOTA = 15;
const int MAX_GRAFICS = 4;
const int MAX_ESTATS = 2;
const int DURADA_MOVIMENT = 3;
const int ESTAT_MOVIMENT = 1;
const int ESTAT_REPOS = 0;
class Granota
{
public:
	Granota();
	Granota(Grafic grafic[MAX_ESTATS][MAX_GRAFICS], int posicioInicialX, int posicioInicialY);
	~Granota();
	Area getAreaOcupada();
	void dibuixa();
	void mouAmunt();
	void mouAvall();
	void mouDreta();
	void mouEsquerra();
	void mouAPosicioInicial();
	void actualitzaEstat();
	void mouPosAbs(int x, int y);
	void estatDefecte();

private:
	Grafic m_grafic[MAX_ESTATS][MAX_GRAFICS];
	int m_posicioX;
	int m_posicioY;
	int m_posicioInicialX;
	int m_posicioInicialY;
	int m_estat; // 1 MOVIMENT 0 REPÒS 
	int m_graficNum;
	int m_durada;
};

