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




// CONSTANTS PEL COTXE
//========================================================================
const int VELOCITAT_COTXE = 2;
// VIDES DE LA GRANOTA

int juga(int Nivell);


