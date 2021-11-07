#pragma once
#pragma once
#ifndef DEF_VOITURE
#define DEF_VOITURE
#include "Vehicule.h"

class Voiture : public Vehicule
{
public:
	Voiture(int prix, int annee, int portes);
	virtual void affiche() const;
	virtual ~Voiture();

private:
	int m_portes;
};

#endif