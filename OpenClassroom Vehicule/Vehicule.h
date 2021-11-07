#pragma once
#ifndef DEF_VEHICULE 
#define DEF_VEHICULE

class Vehicule
{
public:
	Vehicule(int prix, int annee);
	virtual void affiche() const;
	void annee() const;
	virtual int nbrRoues() const;
	virtual ~Vehicule();

protected:
	int m_prix;
	int m_annee;
};

#endif