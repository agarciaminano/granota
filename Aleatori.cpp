#include "Aleatori.h"

Aleatori::Aleatori(){
	
}

Aleatori::~Aleatori(){

}

/* 
* Genera un numero aleatori entre els dos que rep com a parametre.
*/
int Aleatori::generaAleatori(int from, int to){
	return (rand() % (to-from)) + from;
}