#ifndef ACCELERO_H
#define ACCELERO_H

#include "stm32f10x.h"

/**
*	Permet d'initialiser l'acceleromètre et de lancer l'aquisition de valeurs.
**/
void init_accelero();

/**
* Permet de récupérer la valeur de l'inclinaison du bateau compris en 0 et 360 degrès.
* Le bateau est parfaitement droit à 180 degrès.
**/
float get_angle_accelero();

#endif