#pragma once
#include "Area.h"
#include "Cova.h"
#include "Carril.h"
#include "Granota.h"
#include "lib\Grafic.h"
#include "Puntuacio.h"
#include "Bonus.h"
#include "Temporitzador.h"

// Inici del taulell respecte la cantonada superior esquerre
const int INICI_X = 0;
const int INICI_Y = 0;

// Fi del taulell respecte la cantonada superior esquerre
const int FI_X = 600;
const int FI_Y = 450;
const int INICI_Y_GRANOTA = FI_Y - 55;
const int FI_Y_CARRILS = FI_Y - 100;
const int MAX_CARRILS = 5;
const int MAX_COVES = 5;
const int MAX_VIDES = 3;
const int MAX_TEMPOS = 3;
const int INICI_Y_VIDES = FI_Y + 30;
const int INICI_X_VIDES = 30;
const int TEMP_JOC = 0;
const int TEMP_SORPRESA = 1;
const int TEMP_COTXES = 2;
const int MAX_BONUS = 3;
const int MULT_ESPAI_CARRILS = 60;
const int NUM_ORIENTACIONS = 2;
const int AMUNT = 0;
const int AVALL = 1;
const int DRETA = 2;
const int ESQUERRA = 3;

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
	bool getBonusPunts();
	void setBonusPunts();
	int getGranotaActual() const;
	bool getBonusVides();
	void setBonusVides();
private:
	//Elements de fons
	Area m_areaTotal;
	Grafic m_graficFons;
	Grafic m_graficTemp[MAX_TEMP];
	Grafic m_graficSorpresa;
	//Coves
	Grafic m_graficCova;
	Cova m_cova[MAX_COVES];
	bool m_bonusPunts;
	bool m_bonusVides;
	
	//Granotes
	Grafic m_graficsGranota[MAX_ESTATS][MAX_GRAFICS];
	Granota m_granota[MAX_COVES];
	Granota m_vides[MAX_VIDES];
	Bonus m_bonus;
	int m_granotaActual;
	Temporitzador m_tempo[MAX_TEMPOS];
	Aleatori m_generador;

	Puntuacio m_numeros;

	//Vehicles
	Grafic m_graficVehicle[MAX_CARRILS];
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
	bool comprovaColisio(Area a1, Area a2);
	void colisioBonus();
	
	
};

