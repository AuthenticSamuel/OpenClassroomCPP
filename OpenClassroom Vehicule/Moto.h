#pragma once
#ifndef DEF_MOTO
#define DEF_MOTO
#include "Vehicule.h"

class Moto : public Vehicule
{
public:
	Moto(int prix, int annee, double vitesseMax);
	virtual void affiche() const;
	virtual ~Moto();

private:
	double m_vitesse;
};

#endif