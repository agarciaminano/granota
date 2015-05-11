typedef struct
{
	char nom[15];
	int puntuacio;
} TipusJugador;

#define MAX_MILLORSJUGADORS 5

void iniciaTaulaMillorJugadors(TipusJugador TMillorsJugadors[]);
int haMilloratPuntuacio(TipusJugador TMillorsJugadors[], int punts);
void desplacaArray(TipusJugador TMillorsJugadors[], int posicio);
void emplenaPosicioArray(TipusJugador &TMillorsJugadors, int punts);
void escriuRanking(TipusJugador TMillorsJugadors[]);
