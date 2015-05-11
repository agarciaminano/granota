#include "Menu.h"
#include "Joc.h"
#include "GestioResultats.h"

#define OPCIO_JUGAR '1'
#define OPCIO_CONFIGURAR '2'
#define OPCIO_PUNTUACIO '3'
#define OPCIO_SORTIR '4'

/**
 * Programa principal que permet jugar al joc de la granota (frog) desant puntuacions
 * @return
 */

int main()
{
	char opcio;
	int punts;
	int posicio = -1;
	char nivell = '1';
	TipusJugador millorsJugadors[MAX_MILLORSJUGADORS];
	iniciaTaulaMillorJugadors(millorsJugadors);

	do
	{
		mostraMenuPrincipal();
		opcio = _getch(); // Llegeix tecla apretada
		switch (opcio)
		{
			case OPCIO_JUGAR:
				punts = juga(nivell-'0'); // COMPTE!: aquí hi ha una conversió de char a int
				posicio = haMilloratPuntuacio(millorsJugadors, punts);
				if (posicio >= 0) // Ha millorat puntuacio
				{
					system("cls"); // Neteja la consola
					desplacaArray(millorsJugadors, posicio);
					emplenaPosicioArray(millorsJugadors[posicio], punts);
				}
				break;
			case OPCIO_CONFIGURAR:
				do
				{
					mostraMenuNivellDificultat();
					nivell = _getch(); // Llegeix tecla apretada
					if ((nivell != '1') && (nivell != '2') && (nivell != '3')) // Comprova si tecla es valida
					{
						printf("Opcio incorrecta.\n"); // Mostra text
						
					}
				} while ((nivell != '1') && (nivell != '2') && (nivell != '3')); // Repeteix mentre tecla no valida
				break;
			case OPCIO_PUNTUACIO:
				escriuRanking(millorsJugadors);
				printf("Prem una tecla per tornar al menu principal");
				_getch(); // Llegeix tecla apretada
				break;
		}
	} while (opcio != OPCIO_SORTIR);
	return 1;
}
