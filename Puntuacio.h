#pragma once
#include <stdio.h> 
#include <conio.h> 

#include "Area.h"
#include "lib\Grafic.h"


const int MAX_DIGITS = 10;

class Puntuacio {
public:
	Puntuacio();
	Puntuacio(Grafic grafics[]);
	~Puntuacio();
	void dibuixa(int puntuacio);
private:
	Grafic m_grafics[MAX_DIGITS];
	
};