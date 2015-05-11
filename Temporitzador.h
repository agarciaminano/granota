#pragma once
#include <stdio.h> 
#include <conio.h> 
#include <time.h>

#include "Area.h"
#include "lib\Grafic.h"

class Temporitzador {
public:
	Temporitzador();
	~Temporitzador();
	void pintaTemps();
	bool haAcabatElTemps();
	void inicialitza();
private:
	int m_tInici;
	Grafic m_grafics[10];
	int m_seconds1;
	int m_seconds2;
	void dibuixa();
	bool tempsAcabat;
	
};