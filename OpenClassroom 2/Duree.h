#pragma once
#ifndef DEF_DUREE
#define DEF_DUREE
#include <iostream>

class Duree
{
public:
	Duree(int heures = 0, int minutes = 0, int secondes = 0);
	void afficher() const;
	void afficher(std::ostream& flux) const;
	bool estEgal(Duree const& b) const;
	bool estPlusPetitQue(Duree const& b) const;
	Duree& operator+=(Duree const& a);
	Duree& operator+=(int secondes);
	Duree& operator-=(Duree const& a);
	Duree& operator-=(int secondes);
	
private:
	int m_heures;
	int m_minutes;
	int m_secondes;
};

Duree operator+(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, int secondes);
Duree operator-(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, int secondes);
bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator<=(Duree const& a, Duree const& b);
bool operator>=(Duree const& a, Duree const& b);
std::ostream& operator<<(std::ostream& flux, Duree const& duree);

#endif