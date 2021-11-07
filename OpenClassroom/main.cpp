#include <iostream>
#include "Personnage.h"
using namespace std;

int main()
{
	Personnage david, goliath("Burston", 20);

	goliath.attaquer(david);
	david.boirePotionDeVie(20);
	goliath.attaquer(david);
	david.attaquer(goliath);
	goliath.changerArme("Fulmin", 40);
	goliath.attaquer(david);

	cout << "David" << endl;
	david.afficherEtat();
	cout << "Goliath" << endl;
	goliath.afficherEtat();

	return 0;
}