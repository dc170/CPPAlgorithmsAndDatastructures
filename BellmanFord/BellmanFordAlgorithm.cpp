void GrafEtiquetatVMap::bellmanford(){
	etiqueta dist[_nVertexs];
	int pred[_nVertexs];
	int n = 0;
	int inici = 1;
	for(int i = 0 ; i <_nVertexs; i++){
		if(i==inici-1){
			dist[i] = 0;
		}
		else{
			dist[i] = LIM;
		}
		pred[i]=0;

	}
	int passades = 0;
	int mod = 1;
	while(mod==1 and passades <= _nVertexs){
		passades++;
		mod = 0;
		for(int i = 0; i <_nVertexs; i++){
			map<int,etiqueta>::iterator it;
			it = _arestes[i].begin();
			while(it != _arestes[i].end()){
				if (dist[it->first]>dist[i]+it->second){
					dist[it->first] = dist[i] + it->second;
					pred[it->first] = i+1;

					mod = 1;
				}
				it++;
			}
		}
	}
	for(int i = 0; i < _nVertexs; i++){
		cout << i+1 << "| " << pred[i] << " " << dist[i];
		cout << endl;
	}
}