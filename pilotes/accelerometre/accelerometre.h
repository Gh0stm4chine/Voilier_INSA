#ifndef ACCELERO_H
#define ACCELERO_H

/**
*	Permet d'initialiser l'acceleromètre.
**/
void init_accelero();

/**
* Permet de récupérer la valeur de l'inclinaison du bateau compris en 0 et 360 degrès.
* Le bateau est parfaitement droit à 180 degrès.
**/
float get_angle_accelero();

#endif