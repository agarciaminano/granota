#include "Temporitzador.h"
Temporitzador::Temporitzador() {
	time_t tiempo = time(0);
	struct tm tstruct;
	tstruct = *localtime(&tiempo);
	m_tInici = tstruct.tm_sec;
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
	inicialitza();
}
Temporitzador::~Temporitzador() {
	for (int i=0; i < 10; i++)
		m_grafics[i].destrueix();
}
void Temporitzador::pintaTemps() {
	dibuixa();
	time_t tiempo = time(0);
	struct tm tstruct;
	tstruct = *localtime(&tiempo);
	int tActual = tstruct.tm_sec;
	if (m_tInici - tActual != 0){
		m_tInici = tActual;
		m_seconds2--;
		if (m_seconds2 < 0){
			m_seconds1--;
			m_seconds2 = 9;
			if (m_seconds1 < 0)
				
				tempsAcabat = true;
			

		}

		
	}
	

	

}

void Temporitzador::dibuixa() {
	m_grafics[m_seconds1].dibuixa(250, 480);
	m_grafics[m_seconds2].dibuixa(280, 480);
}
void Temporitzador::inicialitza() {
	m_seconds1 = 6;
	m_seconds2 = 0;
	tempsAcabat = false;
}

bool Temporitzador::haAcabatElTemps() {
	return tempsAcabat;
}