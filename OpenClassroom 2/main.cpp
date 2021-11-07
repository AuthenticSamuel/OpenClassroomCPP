#include <iostream>
#include "Duree.h"
using namespace std;

int main()
{
	Duree duree1(1, 45, 50), duree2(1, 44, 59);
	Duree resultat;

	duree1.afficher();
	cout << " et " << endl;
	duree2.afficher();

	resultat = duree1 - duree2;

	cout << " donne " << endl;
	cout << duree1 + duree2 << endl;

	return 0;
}