//
// Created by Afonso Martins on 31/03/2022.
//

#include "NStaff.h"

vector<vector<int>> NStaff::minStaff (vector<int> parcelsVol, vector<int> vansVol) {

    //passar o vetor de carrinhas d amenor para a maior
    //passar o vetor de encomendas da maior para a menor

    //usando a técnica best-fit

    int nParcels = parcelsVol.size();
    int nVans = vansVol.size();

    int res;

    vector<int> van_rem = vansVol;
    vector<vector<int>> van_items(nVans);

    for (int i=0; i<nParcels; i++) {

        for (int j=0; j<nVans; j++) {
            if(van_rem[j] >= parcelsVol[i] && van_rem[j] - parcelsVol[i] >= 0) {
                van_items[j].push_back(i);
                van_rem[j] -= parcelsVol[i];
                break;  //se encontrar uma carrinha para por sair do loop
            }
        }
    }

    return van_items;


    //dar sort a lista de carrinhas pelas que podem, em média de peso e volume, levar mais encomendas, e começar a preencher pela maior primeiro e assim sucessivemante, pois minimiza-se o número de estafetas necessários: os primeiros que vão ter encomendas atribuídas vão ser os que podem levar mais - é uma boa aproximação

}





