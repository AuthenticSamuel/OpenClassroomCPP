#pragma once
#ifndef DEF_GARAGE
#define DEF_GARAGE
#include <vector>
#include "Vehicule.h"

class Garage
{
public:
	void affiche(int index);
	void ajouter(Vehicule*);
	void supprimer(int index);

protected:
	std::vector<Vehicule*> liste;
};

#endif