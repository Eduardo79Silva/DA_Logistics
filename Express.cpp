//
// Created by eduardo on 05/04/22.
//

#include <algorithm>
#include "Express.h"

bool cmp (int a, int b){
    return a>b;
}

void Express::sortParcels(vector<vector<int>> parcels) {

    sort(parcels.begin(), parcels.end(), [](const auto &a, const auto &b){return a[3]<b[3];});
    for(auto parcel : parcels){
        cout << parcel[3] ;
        cout << " ";
    }

}
