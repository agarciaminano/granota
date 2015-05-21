#pragma once
#include "Area.h"
#include "Cova.h"
#include "Vehicle.h"
#include "Carril.h"
#include "Granota.h"
#include "lib\Grafic.h"
#include "Puntuacio.h"
// Inici del taulell respecte la cantonada superior esquerre
#define INICI_X 0
#define INICI_Y 0

// Fi del taulell respecte la cantonada superior esquerre
#define FI_X 600
#define FI_Y 450
const int INICI_Y_GRANOTA = FI_Y - 55;
const int MAX_CARRILS = 5;
const int MAX_COVES = 5;
const int MAX_VIDES = 3;
const int INICI_Y_VIDES = FI_Y + 30;
const int INICI_X_VIDES = 30;

#define AMUNT 0
#define AVALL 1
#define DRETA 2
#define ESQUERRA 3

class Pantalla
{
public:
	Pantalla();
	~Pantalla();
	void inicialitzacioNivell(int nivell);
	void inicialitzacioGranota();
	void dibuixa(int puntuacio);
	void mouGranota(int direccio);
	bool esGranotaDinsCova();
	bool esGranotaDinsCoves();
	void mouVehicle();
	bool haMortLaGranota();
	bool nivellSuperat();
	void actualitza();
	void pintaVides(int vides);
	int getGranotaActual() const;
private:
	//Elements de fons
	Area m_areaTotal;
	Grafic m_graficFons;
	
	//Coves
	Grafic m_graficCova;
	Cova m_cova[MAX_COVES];
	
	//Granotes
	Grafic m_graficsGranota[MAX_ESTATS][MAX_GRAFICS];
	Granota m_granota[MAX_COVES];
	Granota m_vides[MAX_VIDES];
	int m_granotaActual;
	

	Puntuacio m_numeros;

	//Vehicles
	Grafic m_graficVehicle[5];
	Carril m_carrils[MAX_CARRILS];
	int m_iniciCarrilsY;
	int m_nCarrils;

	/**METODES PRIVATS**/
	int triaCarril();
	bool espaiPermes(Area area);
	bool espaiPermesVehicles(Area area);
	void creaGrafics();
	void creaCarrils();
	void creaCoves();
	
	
};

