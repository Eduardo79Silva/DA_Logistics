//
// Created by pedro on 11/04/2022.
//

#include "Profit.h"

bool sortByCost(const tuple<double,int,int,int,int,int>& a, const tuple<double,int,int,int,int,int>& b) {
    return (get<3>(a) < get<2>(b));
}

bool sortByProfit(const tuple<double,int,int,int,int,int>& a, const tuple<double,int,int,int,int,int>& b) {
    return (get<3>(a) > get<2>(b));
}

vector<vector<int>> Profit::maxProfit(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans) {


    int nParcels = parcels.size();
    int nVans = vans.size();

    sort(vans.begin(), vans.end(), sortByCost);
    sort(parcels.begin(), parcels.end(), sortByProfit);

    vector<int> van_remV, van_remW;  //remaining volume and weight on each van
    for (auto v:vans) {
        van_remV.push_back(get<1>(v));
        van_remW.push_back(get<2>(v));
    }

    vector<vector<int>> van_items(nVans);

    for (int i=0; i<nParcels; i++) {
        for (int j=0; j<nVans; j++) {
             if(get<3>(parcels[i]) <= get<3>(vans[j])){
                van_items[j].push_back(i);
                van_remV[j] -= get<1>(parcels[i]);
                van_remW[j] -= get<2>(parcels[i]);
                break;  //se encontrar uma carrinha para por sair do loop
            }
        }
    }

    return van_items;

}

// if((van_remV[j] >= get<1>(parcels[i]) && van_remV[j] - get<1>(parcels[i]) >= 0) && (van_remW[j] >= get<2>(parcels[i]) && van_remW[j] - get<2>(parcels[i]) >= 0) && get<3>(parcels[i]) > get<3>(vans[j]))