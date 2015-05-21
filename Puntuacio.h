#pragma once
#include <stdio.h> 
#include <conio.h> 

#include "Area.h"
#include "lib\Grafic.h"

class Puntuacio {
public:
	Puntuacio();
	~Puntuacio();
	void dibuixa(int puntuacio);
private:
	Grafic m_grafics[10];
	int m_digit1;
	int m_digit2;
	int m_digit3;
};