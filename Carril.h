#include "Vehicle.h"
#include "Cua.h"
#include "Aleatori.h"
const bool CARRIL_ESQUERRA = 0;
const bool CARRIL_DRET = 1;
// Carril necessita coneixer el final de la pantalla
const int FINAL_PANTALLAX = 600;
const int FREQ_APARICIO = 1000;
const int MULT_APARICIO = 250;
const int CARRIL_1 = 1;
const int CARRIL_2 = 2;
const int CARRIL_3 = 3;
const int CARRIL_4 = 4;
const int CARRIL_5 = 5;
class Carril 
{
	
	
	
	private:
		
		bool m_orientation;
		int m_posY;
		Cua m_vehicles;
		int m_freqAparicio;
		int m_velocitat;
		int m_nivell;
		Aleatori m_generador;
		void mouIniciCarril(Vehicle& v);
		Grafic m_tipusVehicle;

	public:
		Carril();
		Carril(bool orientacio, Grafic vehicle, int posY,int vel_carril, int nivell);
		~Carril();
		Cua getVehicle();
		bool getOrientation();
		int getY();
		void destrueixCua();
		void actualitzaEstat();
		bool potCircular();
		void mouVehicle();
		void dibuixaVehicle();
		void haArribatAlFinal();
		
};