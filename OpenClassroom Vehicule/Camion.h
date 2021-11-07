#pragma once
#ifndef DEF_CAMION
#define DEF_CAMION
#include "Vehicule.h"

class Camion : public Vehicule
{
public:
	Camion(int prix, int annee, int masseTransportable);
	virtual void affiche() const;
	virtual ~Camion();

private:
	int m_masse;
};

#endif