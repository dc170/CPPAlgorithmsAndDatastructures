#include <iostream>
using namespace std;

#include "ArbreBinari.h"


ArbreBinari::ArbreBinari()
{
	arrel = NULL;
}

ArbreBinari::ArbreBinari(ArbreBinari * a, ArbreBinari * b, char c){
	arrel=new node;
	arrel->c=c;
	arrel->fe=a->arrel;
	arrel->fd=b->arrel;
}

int ArbreBinari::iArbreBinari(char * cadena, int i){
	if(cadena[i] == ')'){
		return i;
	}
	else{
		//crear arbre nou i anar pujant l'arrel
		if(cadena[i] != '('){
			ArbreBinari * arb = new ArbreBinari;
			arb->arrel = arrel;
			arrel->c = cadena[i-1]; // tenim arrel per tant el seguent sera un node
			i++;
			node * n = new node;
			n->c = cadena[i];
			arb->arrel->fe=n;
			i++;
			if(cadena[i] >= 'A' and cadena[i] <= 'Z'){
				node * n = new node;
				n->c = cadena[i];
				arb->arrel->fd=n;
				i++;
				if(cadena[i]=='('){
					i++;
					i = iArbreBinari(cadena, i);
				}
				else{
					return i;
				}
			}
			else{
				i++;
				i = iArbreBinari(cadena, i);
				n->fe = arrel;
				i++;
				if(cadena[i]=='('){
					i++; i = iArbreBinari(cadena, i);
				}
				else{
					return i;
				}
			}
		}

	}
}

ArbreBinari::ArbreBinari(char * cadena){
	int i = 0;
	char ant = cadena[i];
	ArbreBinari * ar = new ArbreBinari;
	ar->arrel = new node;
	ar->arrel->c = cadena[i];
	i++;
	while((cadena[i] >= 'A' and cadena[i] <= 'Z') or ( cadena[i] == ')' or cadena[i] == ')' ) ){
		if(cadena[i] == '('){
			i++;
			i = iArbreBinari(cadena,i);
			ar->arrel->fe = arrel;
			if(cadena[i] >= 'A' and cadena[i] <= 'Z'){
				node * n = new node;
				n-> c = cadena[i];
				n->fd = NULL; n->fe = NULL;
				ar->arrel->fd = n;
			}
		}
		else{
			node * n = new node;
			n-> c = cadena[i];
			n->fd = NULL; n->fe = NULL;
			ar->arrel->fe = n;
			i++;
			if(cadena[i] >= 'A' and cadena[i] <= 'Z'){
				node * n = new node;
				n-> c = cadena[i];
				n->fd = NULL; n->fe = NULL;
				ar->arrel->fd = n;
			}
			else if(cadena[i]=='('){
				i++;
				i = iArbreBinari(cadena, i);
				ar->arrel->fd = arrel;
			}
		}
		ant = cadena[i];
		i++;
	}
	arrel = ar->arrel;

	// ar2 pasa a ser arrel, per tant, ajustem l'arbre

}



bool ArbreBinari::arbre_buit() const {
	return arrel ==  NULL;

}

char ArbreBinari::contingut() const {
	return arrel->c;
}

ArbreBinari * ArbreBinari::fill_dret() const {
	ArbreBinari * a = new ArbreBinari;
	a->arrel = arrel->fd;
	return a;
}

ArbreBinari * ArbreBinari::fill_esquerre() const {
	ArbreBinari * a = new ArbreBinari;
	a->arrel = arrel->fe;
	return a;
}
