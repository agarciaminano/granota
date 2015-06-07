#include "Joc.h"


/**
 * Juga una partida de tres vides
 *
 * @param nivell nivell de la partida
 * @return
 */
int juga(int nivell)
{
	t_programStatus estat;
	int vides = MAX_VIDES;
	// Inicialitzacions necessàries
	InitGame(estat);
	srand((unsigned)time(NULL));	
	bool jocGuanyat = false;
	bool esDins;
	int puntuacio = 0;
	Pantalla pantalla = Pantalla();
	// Mostrem la finestra
	Video_ShowWindow();

	//Bucle per determinar si s'ha guanyat el joc o has perdut o has tancat la finestra.
	do {
		pantalla.inicialitzacioNivell(nivell);
		
		//Bucle per ficar les 5 granotes a les coves o si et maten
		do
		{
			esDins = false;
			bool haMort = false;
			
			pantalla.inicialitzacioGranota();
			
			//Bucle per ficar 1 granota a 1 cova).
			do
			{
				ProcessEvents(estat); // Captura els events que s'han produit en el darrer cicle
				pantalla.dibuixa(puntuacio);			
				pantalla.pintaVides(vides);
				pantalla.actualitza();
				pantalla.mouVehicle();
				VideoUpdate(estat); // Actualitza la pantalla
				// Dibuixa els gràfics

				if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
				{
					pantalla.mouGranota(ESQUERRA);
				}
				if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
				{
					pantalla.mouGranota(DRETA);
				}

				if (Keyboard_GetKeyTrg(KEYBOARD_UP))
				{
					pantalla.mouGranota(AMUNT);
					esDins = pantalla.esGranotaDinsCova();
					if (esDins) puntuacio += PUNTS_GRANOTA_ES_DINS_COVA;

				}

				if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
				{
					pantalla.mouGranota(AVALL);
				}

				if (pantalla.haMortLaGranota())
				{
					vides--;
					haMort = true;
				}
				if (pantalla.getBonusPunts())
				{
					puntuacio += PUNTS_BONUS;
					pantalla.setBonusPunts();
				}
				if (pantalla.getBonusVides() && vides < 3)
				{
					vides++;
					pantalla.setBonusVides();
				}

			} while ((!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) && (!estat.bExit) && !(haMort) && (esDins==false));
			


		} while (vides > 0 && !pantalla.nivellSuperat() && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && (!estat.bExit));
		if (pantalla.nivellSuperat())
		{
			nivell++;
			puntuacio += PUNTS_NIVELL;
		}
		
		jocGuanyat = (nivell == 4);
	} while (vides > 0 && !jocGuanyat && !Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && (!estat.bExit));
	

	Video_Release(); // Allibera els recursos
	
	return puntuacio;
}
