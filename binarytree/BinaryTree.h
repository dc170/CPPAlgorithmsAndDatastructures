/*******************************************************************************
 * Arbre Binari Caracters
 *
 * Conte totes les operacions, pero nomes cal implementar les necessaries
 * Si no es demana el contrari, millor no implementar el destructor.
 *
 * 2008 JSS - Actualitzats els metodes
 * 2009 JSS - arbre_buit
 *******************************************************************************/
#ifndef ARBRE_BINARI_CARACTER_H
#define ARBRE_BINARI_CARACTER_H


#include <cstdlib>
using namespace std;


struct node {
	char c;
	node * fe, * fd;
};

class ArbreBinari{

	node * arrel;

	// metode privat per poder fer el constructor
	int iArbreBinari(char * cadena, int i); // ? pasem punter a cadena i posicio ; fara arbre i retornara posicio?
public:
	ArbreBinari(); // ok
	ArbreBinari(ArbreBinari * a, ArbreBinari * b, char c); // ok
	ArbreBinari(char * cadena); // to do

	// nomes s'ha d'implementar el destructor si el codi ho demana.
	//~ArbreBinari();
	bool arbre_buit() const; // ok
	ArbreBinari * fill_dret() const; //ok
	ArbreBinari * fill_esquerre() const; //ok
	char contingut() const; // ?
	// void arrelar(ArbreBinari * a, ArbreBinari * b, char c);

};


#endif
