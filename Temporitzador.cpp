#include "Temporitzador.h"
Temporitzador::Temporitzador() {

}
Temporitzador::Temporitzador(Grafic grafics[],int seconds1,int seconds2) {
	time_t tiempo = time(0);
	struct tm tstruct;
	m_seconds1Inici = seconds1;
	tstruct = *localtime(&tiempo);
	m_tInici = tstruct.tm_sec;
	for (int i = 0; i < MAX_TEMP; i++)
		m_grafics[i] = grafics[i];
	inicialitza();
}
Temporitzador::~Temporitzador() {

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
	m_grafics[m_seconds1].dibuixa(POS_X_SEGONS, POS_Y_SEGONS);
	m_grafics[m_seconds2].dibuixa(POS_X_SEGONS + 30, POS_Y_SEGONS);
}
void Temporitzador::inicialitza() {
	m_seconds1 = m_seconds1Inici;
	m_seconds2 = 0;
	tempsAcabat = false;
}

bool Temporitzador::haAcabatElTemps() {
	return tempsAcabat;
}