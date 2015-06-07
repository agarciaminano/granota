#include "Ranking.h"

/**
* Constructor per defecte
*
*/
Ranking::Ranking()
{
	//cout << "\n Creacio del ranking. \n";

	//Si no carrega el ranking del fitxer, inicialitzem l'array.
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
	//Mirem si el jugador passat per parametre te millor puntuacio que els que hi ha al ranking.
	//Retorna -1 si no ha millorat, i si ha millorat, la posicio on l'hem de col·locar.
	int posicio = haMilloratPuntuacio(nouJugador.getPuntuacio());
	
	if (posicio >= 0) // Ha millorat puntuacio
	{
		//Tirem cap avall tots els jugadors "pitjors" que el nou.
		desplacaArray(posicio);
		//Fiquem el nou jugador.
		emplenaPosicioArray(posicio, nouJugador);
		afegit = true;
	}
	return afegit;
}

/**
* Metode que mostra per pantalla tots els jugadors amb la seva puntuacio corresponent.
* @return void 
*/
void Ranking::mostrar() const
{
	cout << "\n\n";
	cout << "\n----------- RANKING DE JUGADORS -----------\n";
	cout << "\n    Nom                           Puntuacio\n";
	cout << "\n------------                    -----------\n";
	for (int i = 0; i < MAX_JUGADORS; i++)
	  cout << "\n"<< i+1 << ".- " << m_taula[i].getNom() << "\t\t\t\t\t" << m_taula[i].getPuntuacio() << "\n";
	cout << "\n\n";
}



/*******************METODES PRIVATS*******************************/




/** 
* Metode que serveix per agafar les puntuacions dels fitxers i passar-les a enters, 
* per poder fer les comprovacions pertinents.
* @param string puntuacioText cadena de caracters que es troben al fitxer ranking.txt.
* @return int Puntuacio en forma numerica.
*/

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

/** Metode que serveix guardar la puntuacio al fitxer en el format de 3 digits.
* @param int puntuacioText puntuacio numerica que rep del joc.
* @return int Puntuacio en format NNN.
*/
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
* @return bool Si s'ha carregat o si no.
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
		
	}
	else
	{
		cout << "\n El fitxer (" << RUTA_FITXER << ") no s'ha pogut obrir.\n";
		carregat = false;
	}

	return carregat;
	
}

/**
* Metode que inicialitza tots els jugadors del ranking.
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
		//Comparem el nou jugador amb cadascun de la taula del ranking.
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


/**
* Metode que introdueix un jugador a la posicio pasada per parametre.
* @param int posicio
* @param Jugador jugadorNou
* @return void
*/
void Ranking::emplenaPosicioArray(int posicio, Jugador jugadorNou)
{
	cout << "\n\n\nIntrodueix el teu nom: ";
	string nouNom;
	cin >> nouNom;
	jugadorNou.setNom(nouNom);
	m_taula[posicio] = jugadorNou;

}
