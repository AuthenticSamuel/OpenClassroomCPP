#include <iostream>
#include "Moto.h"
using namespace std;

Moto::Moto(int prix, int annee, double vitesseMax) : Vehicule(prix, annee), m_vitesse(vitesseMax)
{

}

void Moto::affiche() const
{
	cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

Moto::~Moto()
{

}