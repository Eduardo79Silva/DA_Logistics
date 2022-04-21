//
// Created by eduardo on 05/04/22.
//

#include <algorithm>
#include "Express.h"

bool cmp (int a, int b){
    return a>b;
}

void Express::sortParcels(vector<vector<int>> &parcels) {
    sort(parcels.begin(), parcels.end(), [](const auto &a, const auto &b){return a[3]<b[3];});
}

int Express::chooseParcels(vector<vector<int>> sortedParcels) {
    int nineAM = 32400;
    int fivePM = 61200;
    int total = 0;
    for (auto & sortedParcel : sortedParcels) {
        if((nineAM + total + sortedParcel[3]) < fivePM){
            chosenParcels.push_back(sortedParcel);
            total += sortedParcel[3];
        }
        else {
            return chosenParcels.size();
        }
    }
    return chosenParcels.size();

}

vector<vector<int>> Express::getChosenParcels() {
    return chosenParcels;
}
