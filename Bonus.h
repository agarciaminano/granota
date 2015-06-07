#include "lib\Grafic.h"
#include "Area.h"
class Bonus {
public:
	Bonus();
	Bonus(Grafic grafic);
	~Bonus();
	void setX(int x);
	void setY(int y);
	void dibuixa();
private:
	int m_posX;
	int m_posy;
	Grafic m_grafic;

};