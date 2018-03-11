/*
 * GrafEtiquetatVMap.cpp
 *
 *  Created on: 25/11/2015
 *      Author: ly0n
 */

#include "GrafEtiquetatVMap.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
GrafEtiquetatVMap::GrafEtiquetatVMap() {
	// TODO Auto-generated constructor stub
	_dirigit = false;
	_nVertexs=0;
	_nArestes=0;
	inicia();
}

GrafEtiquetatVMap::~GrafEtiquetatVMap() {


}

GrafEtiquetatVMap::GrafEtiquetatVMap(int nVertexs, bool dirigit ){
	_dirigit = dirigit;
	_nVertexs = nVertexs;
	connecta(); //Si volem que sigui com l'exercici FET A PROBLEMES cal que sigui connex sempre.
	srand(time(NULL));
	int arestesCrear = rand() % (_nVertexs-1) * (_nVertexs-1);
	int val = _nVertexs;
	omple(arestesCrear,val);

	if(_dirigit){
		_nArestes = arestesCrear + _nVertexs*2;
	}
	else{
		_nArestes = arestesCrear + _nVertexs;
	}
}

GrafEtiquetatVMap::GrafEtiquetatVMap(int nVertexs, bool dirigit, int arestes, int valorMax ){
	_dirigit = dirigit;
	_nVertexs = nVertexs;
	//connecta(); //Si volem que sigui com l'exercici FET A PROBLEMES cal que sigui connex sempre.
	inicia();
	int arestesCrear = arestes ;
	omple(arestesCrear,valorMax);
	cout << "omple" << endl;
	if(_dirigit){
		_nArestes = arestesCrear + _nVertexs*2;
	}
	else{
		_nArestes = arestesCrear + _nVertexs;
	}
}

GrafEtiquetatVMap::GrafEtiquetatVMap(const char * nomFitxerTGF, bool dirigit){
	_dirigit = dirigit;
	_nArestes = 0;
	ifstream f;
	string s;
	f.open (nomFitxerTGF, ifstream::in);


	int n = 0;
	f >> s;
	while(s != "#"){
		map<int,etiqueta> m;
		_arestes.push_back(m);
		f>>s;
		n++;
	}
	map<int,etiqueta> m;
	_arestes.push_back(m);
	_nVertexs = n;

	while(!f.eof()){
		int origen = 0;
		int desti = 0;
		etiqueta et = 0;
		f >> origen;
		f >> desti;
		f >>  et;

		if(origen != 0 and desti != 0 and et != 0){
			AfegirAresta(origen-1,desti-1,et);
			if(_dirigit){
				AfegirAresta(desti-1,origen-1,et);
				_nArestes++;
			}
			_nArestes++;
		}

	}

	f.close();
}

int GrafEtiquetatVMap::nVertexs() const{
	//Pre: --
	//Post: retorna n. vertex del graf
	return _nVertexs;
}

int GrafEtiquetatVMap::nArestes() const{
	//Pre: --
	//Post: retorna n. arestes del graf
	return _nArestes;
}

bool GrafEtiquetatVMap::esDirigit() const{
	//Pre: --
	//Post: retorna si el graf es dirigit o no
	return _dirigit;
}

void GrafEtiquetatVMap::AfegirAresta(int v1, int v2, etiqueta e){
	//Pre: --
	//Post: Afegim una aresta al graf amb valor e
	if (not esValid(v1) or not esValid(v2))
		throw "error";
	else if (not ExisteixAresta(v1,v2)) {
		_arestes[v1][v2] = e;
	if ( _dirigit)
		_arestes[v2][v1] = e;
	}
}

bool GrafEtiquetatVMap::esValid(int v1){
	//Pre: --
	//Post: sabem si un valor donat es valid per ser node
	bool res = false;
	res = v1 < _nVertexs and v1 >=0;
	return res;
}

bool GrafEtiquetatVMap::ExisteixAresta(int v1, int v2) {
	//Pre: --
	//Post: retorna si existeix o no una aresta entre 2 nodes
	if (!esValid(v1) or !esValid(v2)){
		return false;
	}
	else{
		return (_arestes[v1].count(v2) == 1);
	}
}

void GrafEtiquetatVMap::EsborrarAresta(int v1, int v2){
	//Pre: --
	//Post: Esborrem una aresta del graf
	_arestes[v1].erase(v2);
}

etiqueta GrafEtiquetatVMap::EtiquetaAresta(int v1, int v2){
	//Pre: --
	//Post: retorna la etiqueta entre 2 arestes
	if (not ExisteixAresta(v1,v2))
		throw "errorr, aresta inexistent";
	else
		return _arestes[v1][v2];
}

void GrafEtiquetatVMap::escriureGraf(const char * nomFitxerTGF) const{
	//Pre: nom valid de fitxer
	//Post: Escrivim el graf al disc dur
	ofstream f;
	f.open (nomFitxerTGF, ifstream::out);
	for(int i = 0; i < _nVertexs; i++){
		f << i+1 << endl;
	}
	f << "#" << endl;
	for(int i = 0; i <_nVertexs; i++){
		map<int,etiqueta>::iterator it;
		map<int,etiqueta> mapa = _arestes[i];
		it = mapa.begin();

		while(it != mapa.end()){
			if(it->second != etiqNula){
				f << i+1 << " " << it->first+1 << " " << it->second<<endl;
			}
			it++;
		}
	}
	f.close();
}

void GrafEtiquetatVMap::mostrar(){
	//Pre: nom valid de fitxer
	//Post: Escrivim el graf al disc dur
		for(int i = 0; i < _nVertexs; i++){
			cout << i+1 << endl;
		}
		cout << "#" << endl;
		for(int i = 0; i <_nVertexs; i++){
			map<int,etiqueta>::iterator it;
			map<int,etiqueta> mapa = _arestes[i];
			it = mapa.begin();

			while(it != mapa.end()){
				if(it->second != etiqNula){
					cout << i+1 << " " << it->first+1 << " " << it->second<<endl;
				}
				it++;
			}
		}
}

void GrafEtiquetatVMap::omple(int nMax, int valorMax){
	//Pre: --
	//Post: Omplim el graf amb valors en un rang
	//Enllaç inicial
	int creades = 0;
	srand(time(NULL));
	while(creades < nMax){
		int origen = rand() % _nVertexs;
		int desti = rand() % _nVertexs;
		while(ExisteixAresta(origen,desti)){
			origen = rand() % _nVertexs;
			desti = rand() % _nVertexs;
		}
		etiqueta et = rand() % valorMax;
		AfegirAresta(origen,desti,et);
		creades++;
	}

}

void GrafEtiquetatVMap::connecta(){
	//Pre: --
	//Post: convertim el graf en connex
	int i = 0;
	etiqueta et =etiqNula;
	map<int, etiqueta> m;
	_arestes.push_back(m);

	for(i = 1; i < _nVertexs; i++){
		etiqueta valor = rand() % 27 ;
		_arestes[i-1].insert(make_pair(i,valor));
		map<int, etiqueta> mapa;
		_arestes.push_back(mapa);
		if(_dirigit){
			_arestes[i].insert(make_pair(i-1,valor));
		}
	}
	_arestes[i-1].insert(make_pair(i-1,et));
}

void GrafEtiquetatVMap::inicia(){
	//Pre: --
	//Post: inicialitzem el graf
	for(int i = 0; i < _nVertexs; i++){
		map<int,etiqueta> m;
		_arestes.push_back(m);
	}
}
