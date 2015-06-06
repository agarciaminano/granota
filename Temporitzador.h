#pragma once
#include <stdio.h> 
#include <conio.h> 
#include <time.h>

#include "Area.h"
#include "lib\Grafic.h"
const int POS_X_SEGONS = 250;
const int POS_Y_SEGONS = 480;
const int MAX_TEMP = 10;
class Temporitzador {
public:
	Temporitzador();
	Temporitzador(Grafic grafics[],int seconds1, int seconds2);
	~Temporitzador();
	void pintaTemps();
	bool haAcabatElTemps();
	void inicialitza();
private:
	int m_tInici;
	Grafic m_grafics[MAX_TEMP];
	int m_seconds1;
	int m_seconds2;
	int m_seconds1Inici;
	void dibuixa();
	bool tempsAcabat;
	
};