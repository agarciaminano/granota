/**
 * Joc interactiu de la granota.
 */


#include <conio.h>      /* getch */ 
#include <stdio.h>      /* printf */


#include "lib\event.h"
#include "lib\libreria.h"
#include "lib\Grafic.h"


//#include "lib\libreria.h"
//#include "lib\event.h"
//#include "lib\Grafic.h"
#include "Pantalla.h"





enum ESTAT_ANTERIOR { UP_0, UP_1, DOWN_0, DOWN_1, LEFT_0, LEFT_1, RIGHT_0, RIGHT_1 };

const int PUNTS_GRANOTA_ES_DINS_COVA = 50;
const int PUNTS_NIVELL = 75;
const int PUNTS_BONUS = 25;
int juga(int Nivell);


