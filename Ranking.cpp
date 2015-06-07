#include "Ranking.h"

/**
* Constructor per defecte
*
*/
Ranking::Ranking()
{
	//cout << "\n Creacio del ranking. \n";
	if (!carregarRanking())
		inicialitza();
	
}
/**
* Destructor
*
*/
Ranking::~Ranking()
{
	cout << "Guardant ranking jugadors...";
	guardarRanking();
	cout << "Guardat.";
	cout << "\nRanking temporal destruit.\n";
}

/**
* Metode que comprova si es pot afegir un jugador al ranking i si es aixi ho afegeix.
* @param Jugador nouJugador Objecte jugador que li passem per comparar puntuacions
* @return True si s'ha afegit, false si no.
*/
bool Ranking::afegirJugador(Jugador nouJugador)
{
	bool afegit = false;

	int posicio = haMilloratPuntuacio(nouJugador.getPuntuacio());
	if (posicio >= 0) // Ha millorat puntuacio
	{
		desplacaArray(posicio);
		emplenaPosicioArray(posicio, nouJugador);
		afegit = true;
	}
	return afegit;
}

void Ranking::mostrar() const
{
	cout << "\n\n";
	cout << "\n----------- RANKING DE JUGADORS -----------\n";
	cout << "\n    Nom                           Puntuacio\n";
	cout << "\n------------                    -----------\n";
	for (int i = 0; i < MAX_JUGADORS; i++)
	{
		//cout << "\n-------------------------------------------\n";
		cout << "\n"<< i+1 << ".- " << m_taula[i].getNom() << "                             " << m_taula[i].getPuntuacio() << "\n";
		//cout << "\n-------------------------------------------\n";\n

	}
	cout << "\n\n";
}



/*******************METODES PRIVATS*******************************/


/***
* Comprova si la tecla introduida està permesa(per descartar els caràcters que no ens interessin).
* @param char tecla Li passem la tecla a verificar.
* @return bool Si es valida o no.
*/
bool Ranking::teclaValida(char tecla) {
	bool valida = false;
	// Es comprova primer les lletres minuscules, ja que són més frequents.
	if ((tecla >= INICI_MINUS) && (tecla <= FI_MINUS)){
		valida = true;
	}
	else if
		((tecla >= INICI_MAYUS && (tecla <= FI_MAYUS))){
		valida = true;
	}
	else if (tecla == ESPAI){
		valida = true;
	}

	return valida;
}


/***
* Funció que ens permet llegir el nom d'un jugador, i controlar tot els esdeveniments de teclat.
* @param int filaGotoXY Coordenada vertical per colocar el scanner a la pantalla.
* @return string retorna la cadena completa.
*/
string Ranking::llegirNom() {
	char tecla;
	int i = 0;
	string nom;
	HANDLE pantalla = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	do {
		//Llegim la tecla pulsada
		tecla = _getch();
		//Si la tecla es valida i no hem arribat al final de la cadena,
		//la incluim en el nostre array y la pintem per pantalla.
		if ((teclaValida(tecla)) && (i < MAX_LONG_NOM - 1)){
			nom.push_back(tecla);
			cout << tecla;
			i++;
		}

		else if (tecla == BACKSPACE){
			//Si borrem una lletra, hem de tornar enrere a l'array i,a més
			//ens hem de situar en la posició anterior per pantalla per poder
			//mostrar-li a l'usuari que la lletra ha estat esborrada.
			if (i > 0){

				/*i--;
				GotoXY(i, 1, pantalla);
				printf(" ");
				GotoXY(i, 1, pantalla);*/
				i--;
				//Agafem la posicio actual del cursor.
				GetConsoleScreenBufferInfo(pantalla, &SBInfo);
				//Ens posicionem a la fila y columna de la consola.
				GotoXY(i, SBInfo.dwCursorPosition.Y, pantalla);
				
				printf(" ");
				GotoXY(i, SBInfo.dwCursorPosition.Y, pantalla);
				//Treu un caracter
				nom.pop_back();

			}

		}
		//Intro per acabar.
	} while (tecla != INTRO || i < MIN_LONG_NOM);
	//Emplenem els espais buits amb caràcters en blanc per alinear tots els noms
	for (i; i < MAX_LONG_NOM - 1; i++) {
		nom.push_back(' ');
	}
	/*	//Indiquem el final de cadena.
	frase[i] = '\0';*/
	return nom;
}


int Ranking::castPuntuacio(string puntuacioText)
{
	int puntuacioNumerica = 0;

	int i = 0;
	while (i<puntuacioText.length())
	{
		puntuacioNumerica += (puntuacioText[2 - i] - CARACTER_ZERO)*pow(10, i);
		i++;
	}
	return puntuacioNumerica;
}

string Ranking::castPuntuacio(int puntuacio)
{
	string puntuacioText;

	if (puntuacio < 10)
	{
		puntuacioText.push_back('0');
		puntuacioText.push_back('0');
		puntuacioText.push_back(puntuacio + CARACTER_ZERO);
	}
	else
		if (puntuacio < 100)
		{
			int digit2 = puntuacio / 10;
			int digit3 = puntuacio % (digit2 * 10);
			puntuacioText.push_back('0');
			puntuacioText.push_back(digit2 + CARACTER_ZERO);
			puntuacioText.push_back(digit3 + CARACTER_ZERO);
		}
		else
		{
			int digit1 = puntuacio / 100;
			int digit2 = (puntuacio % (digit1 * 100)) / 10;
			int digit3 = (puntuacio % (digit1 * 100 + (digit2 * 10)));

			puntuacioText.push_back(digit1 + CARACTER_ZERO);
			puntuacioText.push_back(digit2 + CARACTER_ZERO);
			puntuacioText.push_back(digit3 + CARACTER_ZERO);
		}
	return puntuacioText;
}
	

/***
* Guarda tots els jugadors a un fitxer de text.
* @return void
*/
void Ranking::guardarRanking()
{
	ofstream fitxer;
	
	fitxer.open(RUTA_FITXER, std::ofstream::out | std::ofstream::trunc);
	if (fitxer.is_open())
	{
				
		for (int i = 0; i < MAX_JUGADORS; i++)
			fitxer << m_taula[i].getNom() << " " << castPuntuacio(m_taula[i].getPuntuacio()) << "\n";
		fitxer.close();
	
	}
	else
		cout << "\n El fitxer (" << RUTA_FITXER << ") no s'ha pogut obrir.\n";
	
}

/***
* Funcio que a partir d'un fitxer, carrega els jugadors, els prepara per ficar-los a la taula i posteriorment els fica.
*
*/
bool Ranking::carregarRanking()
{
	ifstream fitxer;
	bool carregat = false;
	string nomJugador;
	string puntuacioText;

	fitxer.open(RUTA_FITXER);
	if (fitxer.is_open())
	{
		//Comprovem que el fitxer no estigui buit.
		//fitxer.seekg(0, ios::end);
		//if (fitxer.tellg() > 0) 
		//{
			fitxer >> nomJugador >> puntuacioText;
			int puntuacio;
			int i = 0;
			while (!fitxer.eof() && i<MAX_JUGADORS)
			{
				puntuacio=castPuntuacio(puntuacioText);
				Jugador nouJugador = Jugador(nomJugador, puntuacio);
				m_taula[i] = nouJugador;
				fitxer >> nomJugador >> puntuacioText;
				i++;
			}
			carregat = true;
		//}
		
		
	}
	else
	{
		cout << "\n El fitxer (" << RUTA_FITXER << ") no s'ha pogut obrir.\n";
		carregat = false;
	}

	return carregat;
	
}

/***
*
*/
void Ranking::inicialitza()
{
	for (int i = 0; i < MAX_JUGADORS;i++)
	{
		m_taula[i] = Jugador("------", 0);
	}
}


/***
* Metode que passat un jugador nou, si te millor puntuacio que algun dels que hi ha al ranking actualment.
* @param Jugador nouJugador
* @return int posicio Retorna la posicio on s'ha de afegir aquest nou jugador, en cas de que s'afegeixi.
*/
int Ranking::haMilloratPuntuacio(Jugador nouJugador)
{
	int i = 0;
	int posicio = -1;
	do
	{
		if (m_taula[i].getPuntuacio() < nouJugador.getPuntuacio())
			posicio = i - 1;
		i++;
	} while ((i < MAX_JUGADORS) && posicio == -1);

	return posicio;
}


/***
* Aquest metode passada una posicio per parametre, començant pel final
* sobrescriu el jugador i amb i-1 fins a la posicio donada.
* @param int posicio posicio final on ha de parar de fer overwrite.
*/
void Ranking::desplacaArray(int posicio)
{
	for (int i = MAX_JUGADORS - 1; i > posicio; i--)
		m_taula[i] = m_taula[i - 1];
}

void Ranking::emplenaPosicioArray(int posicio, Jugador jugadorNou)
{
	cout << "\n\n\nIntrodueix el teu nom: ";

	string nouNom = llegirNom();
	jugadorNou.setNom(nouNom);
	m_taula[posicio] = jugadorNou;

}
