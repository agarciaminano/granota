#include "Menu.h"
#include "Joc.h"
#include "Ranking.h"

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
	Ranking ranking = Ranking();
	Jugador nouJugador;
	int filaGotoXY=9;

	do
	{
		mostraMenuPrincipal();
		opcio = _getch(); // Llegeix tecla apretada
		switch (opcio)
		{
			case OPCIO_JUGAR:
			
				punts = juga(nivell-'0'); // COMPTE!: aquí hi ha una conversió de char a int
				nouJugador = Jugador(punts);
				if (ranking.afegirJugador(nouJugador))
					cout << "\n Enhorabona!!! Has entrat al ranking dels " << MAX_JUGADORS << "millors jugadors!!\n";
				else
					cout << "\n Llàstima! No has pogut entrar al ranking dels " << MAX_JUGADORS << "millors jugadors. \n";
				break;
			case OPCIO_CONFIGURAR:
				do
				{
					mostraMenuNivellDificultat();
					nivell = _getch(); // Llegeix tecla apretada
					if ((nivell != '1') && (nivell != '2') && (nivell != '3')) // Comprova si tecla es valida
					{
						cout << "Opcio incorrecta.\n"; // Mostra text
						
					}
				} while ((nivell != '1') && (nivell != '2') && (nivell != '3')); // Repeteix mentre tecla no valida
				break;
			case OPCIO_PUNTUACIO:
				ranking.mostrar();
				cout << "Prem una tecla per tornar al menu principal";
				_getch(); // Llegeix tecla apretada
				break;
		}
	} while (opcio != OPCIO_SORTIR);
	
	return 1;
}
