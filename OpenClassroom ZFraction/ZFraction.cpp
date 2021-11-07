#include <iostream>
#include <cmath>
#include "ZFraction.h"
using namespace std;

ZFraction::ZFraction() : m_numerateur(0), m_denominateur(1) {}
ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1) {}
ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
	simplifie();
}

void ZFraction::afficher() const
{
	if (m_denominateur == 1) {
		cout << m_numerateur << endl;
	}
	else {
		cout << m_numerateur << "/" << m_denominateur << endl;
	}
}

void ZFraction::afficher(ostream& flux) const
{
	if (m_denominateur == 1) {
		flux << m_numerateur;
	}
	else {
		flux << m_numerateur << "/" << m_denominateur;
	}
}

void ZFraction::simplifie()
{
	int nombre = pgcd(m_numerateur, m_denominateur);
	m_numerateur /= nombre;
	m_denominateur /= nombre;
	if (m_denominateur < 0) {
		m_denominateur = abs(m_denominateur);
		m_numerateur *= -1;
	}
}

int ZFraction::numerateur() const
{
	return m_numerateur;
}

int ZFraction::denominateur() const
{
	return m_denominateur;
}

double ZFraction::nombreReel() const
{
	return (double)m_numerateur / m_denominateur;
}

bool ZFraction::estEgal(ZFraction const& autre) const
{
	return (m_numerateur == autre.m_numerateur && m_denominateur == autre.m_denominateur);
}

bool ZFraction::estPlusPetiteQue(ZFraction const& autre) const
{
	return (m_numerateur * autre.m_denominateur < m_denominateur* autre.m_numerateur);
}

ZFraction& ZFraction::operator+=(ZFraction const& autre)
{
	m_numerateur = autre.m_denominateur * m_numerateur + m_denominateur * autre.m_numerateur;
	m_denominateur = m_denominateur * autre.m_denominateur;
	simplifie();
	return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& autre)
{
	m_numerateur = autre.m_denominateur * m_numerateur - m_denominateur * autre.m_numerateur;
	m_denominateur = m_denominateur * autre.m_denominateur;
	simplifie();
	return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& autre)
{
	m_numerateur *= autre.m_numerateur;
	m_denominateur *= autre.m_denominateur;
	simplifie();
	return *this;
}

ZFraction& ZFraction::operator/=(ZFraction const& autre)
{
	m_numerateur *= autre.m_denominateur;
	m_denominateur *= autre.m_numerateur;
	simplifie();
	return *this;
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie += b;
	return copie;
}

ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie -= b;
	return copie;
}

ZFraction operator-(ZFraction const& a)
{
	ZFraction copie(a);
	copie *= -1;
	return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie *= b;
	return copie;
}

ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie /= b;
	return copie;
}

ZFraction abs(ZFraction const& a)
{
	ZFraction copie(abs(a.numerateur()), abs(a.denominateur()));
	return copie;
}

ZFraction sqrt(ZFraction const& a)
{
	ZFraction copie(sqrt(a.numerateur()), sqrt(a.denominateur()));
	return copie;
}

ZFraction pow(ZFraction const& a, int puissance)
{
	ZFraction copie(pow(a.numerateur(), puissance), pow(a.denominateur(), puissance));
	return copie;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
	return a.estEgal(b);
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
	return !(a.estEgal(b));
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
	return a.estPlusPetiteQue(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
	return b.estPlusPetiteQue(a);
}

bool operator<=(ZFraction const& a, ZFraction const& b)
{
	return !(b.estPlusPetiteQue(a));
}

bool operator>=(ZFraction const& a, ZFraction const& b)
{
	return !(a.estPlusPetiteQue(b));
}

ostream& operator<<(ostream& flux, ZFraction const& fraction)
{
	fraction.afficher(flux);
	return flux;
}

int pgcd(int a, int b)
{
	while (b != 0) {
		const int t = b;
		b = a % b;
		a = t;
	}
	return a;
}