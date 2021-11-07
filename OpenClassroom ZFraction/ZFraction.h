#pragma once
#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION
#include <iostream>

class ZFraction
{
public:
	ZFraction();
	ZFraction(int numerateur);
	ZFraction(int numerateur, int denominateur);
	void afficher() const;
	void afficher(std::ostream& flux) const;
	void simplifie();
	int numerateur() const;
	int denominateur() const;
	double nombreReel() const;
	bool estEgal(ZFraction const& autre) const;
	bool estPlusPetiteQue(ZFraction const& autre) const;
	ZFraction& operator+=(ZFraction const& autre);
	ZFraction& operator-=(ZFraction const& autre);
	ZFraction& operator*=(ZFraction const& autre);
	ZFraction& operator/=(ZFraction const& autre);

private:
	int m_numerateur;
	int m_denominateur;
};

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
ZFraction abs(ZFraction const& a);
ZFraction sqrt(ZFraction const& a);
ZFraction pow(ZFraction const& a, int puissance);
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction);
int pgcd(int a, int b);

#endif