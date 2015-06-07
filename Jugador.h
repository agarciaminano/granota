#include <iostream>
#include <string>

using namespace std;

class Jugador
{
public:
	Jugador();
	Jugador(int puntuacio);
	Jugador(string nom, int puntuacio);
	~Jugador();

	string getNom() const;
	void setNom(string nouNom);

	int getPuntuacio() const;
	void setPuntuacio(int novaPuntuacio);
private:
	string m_nom;
	int m_puntuacio;

	
	
};
