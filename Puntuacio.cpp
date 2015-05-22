#include "Puntuacio.h"

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

	m_digit1=0;
	m_digit2=0;
	m_digit3=0;
}


Puntuacio::~Puntuacio()
{
	/*m_grafics[0].destrueix();
	m_grafics[1].destrueix();
	m_grafics[2].crea("Program/data/numeros/numero0002.png");
	m_grafics[3].crea("Program/data/numeros/numero0003.png");
	m_grafics[4].crea("Program/data/numeros/numero0004.png");
	m_grafics[5].crea("Program/data/numeros/numero0005.png");
	m_grafics[6].crea("Program/data/numeros/numero0006.png");
	m_grafics[7].crea("Program/data/numeros/numero0007.png");
	m_grafics[8].crea("Program/data/numeros/numero0008.png");
	m_grafics[9].crea("Program/data/numeros/numero0009.png");*/
}


void Puntuacio::dibuixa(int puntuacio)
{


	if(puntuacio>=100)
	{
		
		m_digit1=puntuacio / 100;
		m_digit2=(puntuacio % (m_digit1 * 100)) / 10;
		m_digit3=(puntuacio % (m_digit1 * 100 + (m_digit2 * 10)));
	}
	else if (puntuacio>10)
	{
		m_digit1=0;
		m_digit2=puntuacio/10;
		m_digit3=puntuacio % (m_digit2*10);
	}
	else
	{
		m_digit1=0;
		m_digit2=0;
		m_digit3=puntuacio % 10;
	}

	m_grafics[m_digit1].dibuixa(400, 480);
	m_grafics[m_digit2].dibuixa(430, 480);
	m_grafics[m_digit3].dibuixa(460, 480);


}