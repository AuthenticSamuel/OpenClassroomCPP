#include <iostream>
#include "Camion.h"
using namespace std;

Camion::Camion(int prix, int annee, int masseTransportable) : Vehicule(prix, annee), m_masse()
{

}

void Camion::affiche() const
{
	cout << "Ceci est un camion pouvant transporter " << m_masse << " kg et coutant " << m_prix << " euros." << endl;
}

Camion::~Camion()
{

}