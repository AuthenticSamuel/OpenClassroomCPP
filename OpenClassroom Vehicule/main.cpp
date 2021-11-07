#include <iostream>
#include <vector>
#include "Vehicule.h"
#include "Voiture.h"
#include "Moto.h"
#include "Camion.h"
using namespace std;

int main() {
	vector<Vehicule*> listeVehicules;

	listeVehicules.push_back(new Voiture(15000, 2002, 5));
	listeVehicules.push_back(new Voiture(12000, 2018, 3));
	listeVehicules.push_back(new Moto(2000, 1989, 212.5));

	listeVehicules[0]->affiche();
	listeVehicules[2]->affiche();
	listeVehicules[1]->annee();

	for (int i(0); i < listeVehicules.size(); ++i) {
		delete listeVehicules[i];
		listeVehicules[i] = 0;
	}

	return 0;
}