#include "Vehicle.h"
#include "Cua.h"
#include "Aleatori.h"
const bool CARRIL_ESQUERRA = 0;
const bool CARRIL_DRET = 1;
// Carril necessita coneixer el final de la pantalla
const int FINAL_PANTALLAX = 600;
class Carril 
{
	
	
	
	private:
		bool m_orientation;
		int m_posY;
		Cua m_vehicles;
		int m_freqAparicio;
		Aleatori m_generador;
		void mouIniciCarril(Vehicle& v);
		Grafic m_tipusVehicle;

	public:
		Carril();
		Carril(bool orientacio, Grafic vehicle, int posY);
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