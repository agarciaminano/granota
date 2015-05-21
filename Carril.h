#include "Vehicle.h"
#include "Cua.h"
const bool CARRIL_ESQUERRA = 0;
const bool CARRIL_DRET = 1;

class Carril 
{
	
	
	enum TIPUS_VEHICLE{COTXE_1, COTXE_2, COTXE_3, COTXE_4, COTXE_5};
	
	private:
		int m_delay;
		bool m_orientation;
		int m_posY;
		Cua m_vehicles;
		int m_cont;
		

	public:
		Carril();
		Carril(int delay, bool orientacio, Grafic vehicle, int posY);
		~Carril();
		Vehicle getVehicle();
		bool getOrientation();
		int getY();
		void mouIniciCarril(int fi_pantalla);
		void actualitzaEstat();
		bool potCircular();
		void mouVehicle();
		void dibuixaVehicle();
		
};