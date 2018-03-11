void GrafEtiquetatVMap::bfs(){
	vector<int> q;
	int ord[_nVertexs];
	int pred[_nVertexs];
	int k = 1;
	int inici = 3;
	for(int i = 0; i < _nVertexs; i++){
		if(i == inici-1){
			pred[i] = inici;
			ord[i] = k;
		}
		else{
			pred[i] = 0;
			ord[i] = 0;
		}
	}
	q.push_back(inici);
	int act =0;
	while(!q.empty()){
		mostraq(q);
		act = q.front();
		k++;
		ord[act-1] = k;
		cout << "VALOR ACTUAL: " << act << endl;
		map<int, etiqueta>::iterator it2;
		it2 = _arestes[act-1].begin();
		for(int i = 0; i <_nVertexs; i++){
			cout << i+1 << "| " << ord[i]-1  << " " << pred[i] << endl;
		}
		while(it2 != _arestes[act-1].end()){
			if(pred[(it2->first)]==0 and !enq(q,it2->first+1)){
				pred[(it2->first)] = act;
				q.push_back((it2->first)+1);
				cout << "Afegim ";
				cout << it2->first+1;
				cout << " ";
			}
			it2++;
		}
		q.erase(q.begin());


	}
}
void GrafEtiquetatVMap::mostraq(vector<int> q){
	vector<int>::iterator it;
	it = q.begin();
	cout << "Estat de la cua" << endl;
	while(it != q.end()){
		cout <<*it << " ";
		it++;
	}
	cout << endl;
}
bool GrafEtiquetatVMap::enq(vector<int> q, int val){
	bool res = false;
	vector<int>::iterator it;
	it = q.begin();
	while(it != q.end() and !res){
		res = *it == val;
		it++;
	}
	return res;
}