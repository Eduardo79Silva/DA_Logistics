//
// Created by Afonso Martins on 30/03/2022.
//

#include "Data.h"

void Data::readData(list<vector<int>> &parcels, list<vector<int>> &vans) {

    ifstream parcel, van;

    //Parcels

    int volume, weight, reward, duration;
    string svolume, sweight, sreward, sduration;

    parcel.open("..\\.\\dataset\\encomendas.txt");
    parcel.ignore(1000, '\n');

    while (getline(parcel, svolume, ' ')) {
        getline(parcel, sweight, ' ');
        getline(parcel, sreward, ' ');
        getline(parcel, sduration, '\n');
        volume = stoi(svolume);
        weight = stoi(sweight);
        reward = stoi(sreward);
        duration = stoi(sduration);
        vector<int> tempParcel = {volume, weight, reward, duration};
        parcels.push_back(tempParcel);
    }


    //Vans

    int maxVol, maxWeight, cost;
    string smaxVol, smaxWeight, scost;

    van.open("..\\.\\dataset\\carrinhas2.txt");
    van.ignore(1000, '\n');

    while (getline(van, smaxVol, ' ')) {
        getline(van, smaxWeight, ' ');
        getline(van, scost, '\n');
        maxVol = stoi(smaxVol);
        maxWeight = stoi(smaxWeight);
        cost = stoi(scost);
        vector<int> tempVan = {maxVol, maxWeight, cost};
        vans.push_back(tempVan);
    }



    /*cout << "Parcels" << endl;
    for (auto p:parcels) {
        for (auto i:p) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    cout << "Vans" << endl;
    for (auto k:vans) {
        for (auto j:k) {
            cout << j << " ";
        }
        cout << endl;
    }*/

}


Data::Data() {
    readData(this->parcels, this->vans);
}

const list<vector<int>> &Data::getParcels() const {
    return parcels;
}

const list<vector<int>> &Data::getVans() const {
    return vans;
}



