#include <iostream>
#include "Vehicule.h"
using namespace std;

Vehicule::Vehicule(int prix, int annee) : m_prix(prix), m_annee(annee)
{

}

void Vehicule::affiche() const
{
	cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

Vehicule::~Vehicule()
{

}