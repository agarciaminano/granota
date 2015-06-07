#include "Puntuacio.h"

/***
* Constructor per defecte
*
*/
Puntuacio::Puntuacio()
{
	m_grafics[0].crea("Program/data/numeros/numero0000.png");
	m_grafics[1].crea("Program/data/numeros/numero0001.png");
	m_grafics[2].crea("Program/data/numeros/numero0002.png");
	m_grafics[3].crea("Program/data/numeros/numero0003.png");
	m_grafics[4].crea("Program/data/numeros/numero0004.png");
	m_grafics[5].crea("Program/data/numeros/numero0005.png");
	m_grafics[6].crea("Program/data/numeros/numero0006.png");
	m_grafics[7].crea("Program/data/numeros/numero0007.png");
	m_grafics[8].crea("Program/data/numeros/numero0008.png");
	m_grafics[9].crea("Program/data/numeros/numero0009.png"); 
}

/***
* Constructor que rep els grafics ja creats abans pels digits del temporitzador i els asigna al atribut de la clase
* @param Grafic grafics[] Array de grafics
*/

Puntuacio::Puntuacio(Grafic grafics[])
{
	for (int i = 0; i < MAX_DIGITS; i++)
	{
		m_grafics[i] = grafics[i];
	}
	
}

/**
* Destructor de la classe
*/
Puntuacio::~Puntuacio()
{
	
}

/**
* Metode que passant-li una puntuacio numerica, tracta aquesta puntuacio, i li posa els numeros corresponents al panell de puntuacio.
* @param int puntuacio
* @return void 
*/
void Puntuacio::dibuixa(int puntuacio)
{
	int digit1 = 0;
	int digit2 = 0;
	int digit3 = 0;

	if(puntuacio<10)
	{
		digit3=puntuacio;
		
	}
	else if (puntuacio<100)
	{
		digit2=puntuacio/10;
		digit3=puntuacio % (digit2*10);
	}
	else
	{
		digit1=puntuacio / 100;
		digit2=(puntuacio % (digit1 * 100)) / 10;
		digit3=(puntuacio % (digit1 * 100 + (digit2 * 10)));
	}



	m_grafics[digit1].dibuixa(400, 480);
	m_grafics[digit2].dibuixa(430, 480);
	m_grafics[digit3].dibuixa(460, 480);


}