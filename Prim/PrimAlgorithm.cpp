void GrafEtiquetatVMap::prim(){
    struct aux{
        bool solucio;
        int proper;
        etiqueta dist;
    };
    int comptador = 0;
    aux t[_nVertexs];
    t[0] = {true, 0, 0.0};
    for(int i = 1; i < _nVertexs; i++){
        t[i] = {false, -1, numeric_limits<float>::max()};
    }

    while(comptador<_nVertexs){
        int min = numeric_limits<float>::max();
        int pos = 0;
        for(int i = 0; i < _nVertexs; i++){
            if(t[i].dist>min and !t[i].solucio){
                pos = i;
            }
        }
        t[pos].solucio=true;
        map<int,etiqueta>::iterator it;
        it = _arestes[pos].begin();
        while(it != _arestes[pos].end()){
            t[it->first] = {false, pos, it->second};
            it++;
        }
        comptador++;
    }
    for(int i = 0; i < _nVertexs; i++){
        cout << t[i].proper;
        cout << " ";
        cout << t[i].dist << endl;
    }

}
