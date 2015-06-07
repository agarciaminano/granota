#include "Aleatori.h"

/**
* Constructor de la classe.
*/
Aleatori::Aleatori(){
	
}


/**
* Destructor de la classe.
*/
Aleatori::~Aleatori(){

}


/**
* Metode que rep dos enters i retorna un numero aleatori entre aquests dos enters.
* @param int from Numero minim d'aquest interval.
* @param int to Numero maxim d'aquest interval
* @return int numero aleatori entre aquests dos enters.
*/

int Aleatori::generaAleatori(int from, int to){
	return (rand() % (to-from)) + from;
}