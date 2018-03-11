/*
 * GrafEtiquetatVMap.h
 *
 *  Created on: 25/11/2015
 *      Author: ly0n
 */
#include <vector>
#include <map>
#include <fstream>

using namespace std;

typedef float etiqueta;
//typedef string etiqueta;
const float etiqNula = -1;
//const string etiqNula = “”;
const int MIDA_DEFECTE = 1000;

#ifndef GRAFETIQUETATVMAP_H_
#define GRAFETIQUETATVMAP_H_

class GrafEtiquetatVMap{
public:
	GrafEtiquetatVMap();//Constructors amb parametres
	GrafEtiquetatVMap(int nVertexs = MIDA_DEFECTE, bool dirigit = false);
	GrafEtiquetatVMap(int nVertexs, bool dirigit,int arestes, int valorMax);
	GrafEtiquetatVMap(const char * nomFitxerTGF, bool dirigit);
	~GrafEtiquetatVMap();
	int nVertexs() const;
	//Pre: --
	//Post: retorna n. vertex del graf
	int nArestes() const;
	//Pre: --
	//Post: retorna n. arestes del graf
	bool esDirigit() const;
	//Pre: --
	//Post: retorna si el graf es dirigit o no
	void AfegirAresta(int v1, int v2, etiqueta e);
	//Pre: --
	//Post: Afegim una aresta al graf amb valor e
	bool ExisteixAresta(int v1, int v2);
	//Pre: --
	//Post: retorna si existeix o no una aresta entre 2 nodes
	void EsborrarAresta ( int v1, int v2);
	//Pre: --
	//Post: Esborrem una aresta del graf
	etiqueta EtiquetaAresta(int v1, int v2);
	//Pre: --
	//Post: retorna la etiqueta entre 2 arestes
	void escriureGraf(const char * nomFitxerTGF) const;
	//Pre: nom valid de fitxer
	//Post: Escrivim el graf al disc dur
	void mostrar();
private:
	int _nVertexs; // = _ arestes.size()- 1 (despreciem element 0)
	int _nArestes;
	bool _dirigit;
	bool esValid(int v1);
	//Pre: --
	//Post: sabem si un valor donat es valid per ser node
	void omple(int nMax, int valorMax);
	//Pre: --
	//Post: Omplim el graf amb valors en un rang
	void connecta();
	//Pre: --
	//Post: convertim el graf en connex
	void inicia();
	//Pre: --
	//Post: inicialitzem el graf
	vector< map<int,etiqueta> > _arestes;

};

#endif /* GRAFETIQUETATVMAP_H_ */
