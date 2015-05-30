#include "Aleatori.h"

Aleatori::Aleatori(){
	
}

Aleatori::~Aleatori(){

}

int Aleatori::generaAleatori(int from, int to){
	return (rand() % (to-from)) + from;
}