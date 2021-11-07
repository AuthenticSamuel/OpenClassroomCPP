#include <iostream>
#include <math.h>
#include "Duree.h"
using namespace std;

Duree::Duree(int heures, int minutes, int secondes)
{
	m_secondes = secondes % 60;
	minutes += secondes / 60;
	m_minutes = minutes % 60;
	heures += minutes / 60;
	m_heures = heures;
}

void Duree::afficher() const
{
	cout << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << endl;
}

void Duree::afficher(ostream& flux) const
{
	flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}

bool Duree::estEgal(Duree const& b) const
{
	return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
	if (m_heures < b.m_heures) return true;
	else if (m_heures == b.m_heures && m_minutes < b.m_minutes) return true;
	else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) return true;
	else return false;
}

// Opérateurs
Duree& Duree::operator+=(Duree const& a)
{
	m_secondes += a.m_secondes;
	m_minutes += m_secondes / 60;
	m_secondes %= 60;
	m_minutes += a.m_minutes;
	m_heures += m_minutes / 60;
	m_minutes %= 60;
	m_heures += a.m_heures;
	return *this;
}

Duree& Duree::operator+=(int secondes)
{
	m_secondes += secondes;
	m_minutes += m_secondes / 60;
	m_secondes %= 60;
	m_heures += m_minutes / 60;
	m_minutes %= 60;
	return *this;
}

Duree& Duree::operator-=(Duree const& a)
{
	m_secondes -= a.m_secondes;
	m_minutes -= a.m_minutes;
	m_heures -= a.m_heures;
	if (m_secondes < 0) {
		m_secondes += 60;
		m_minutes--;
	}
	if (m_minutes < 0) {
		m_minutes += 60;
		m_heures--;
	}
	return *this;
}

Duree& Duree::operator-=(int secondes)
{
	m_secondes -= secondes;
	if (m_secondes < 0) {
		m_secondes += 60;
		m_minutes--;
	}
	if (m_minutes < 0) {
		m_minutes += 60;
		m_heures--;
	}
	return *this;
}

Duree operator+(Duree const& a, Duree const& b)
{
	Duree copie(a);
	copie += b;
	return copie;
}

Duree operator+(Duree const& a, int secondes)
{
	Duree copie(a);
	copie += secondes;
	return copie;
}

Duree operator-(Duree const& a, Duree const& b)
{
	Duree copie(a);
	copie -= b;
	return copie;
}

Duree operator-(Duree const& a, int secondes)
{
	Duree copie(a);
	copie -= secondes;
	return copie;
}

bool operator==(Duree const& a, Duree const& b)
{
	return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
	return !(a == b);
}

bool operator<(Duree const& a, Duree const& b)
{
	return a.estPlusPetitQue(b);
}

bool operator>(Duree const& a, Duree const& b)
{
	return !(a < b);
}

bool operator<=(Duree const& a, Duree const& b)
{
	return (a < b) || (a == b);
}

bool operator>=(Duree const& a, Duree const& b)
{
	return (a > b) || (a == b);
}

ostream& operator<<(ostream& flux, Duree const& duree)
{
	duree.afficher(flux);
	return flux;
}