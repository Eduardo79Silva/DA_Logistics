//
// Created by Afonso Martins on 30/03/2022.
//

#include "Data.h"

void Data::readData(list<vector<int>> &parcels, list<vector<int>> &vans) {

    ifstream parcel, van;

    //Parcels

    int volume, weight, reward, duration;
    string svolume, sweight, sreward, sduration;

    parcel.open(".././dataset/encomendas.txt");
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

    van.open(".././dataset/carrinhas.txt");
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

}

Data::Data() {
    readData(this->parcels, this->vans);
    this->coefP = coefParcels(this->parcels);
    this->coefV = coefVans(this->vans);
    addCoefs(parcels,vans,coefP,coefV);
}

const list<vector<int>> &Data::getParcels() const {
    return parcels;
}

const list<vector<int>> &Data::getVans() const {
    return vans;
}

const vector<double> &Data::getCoefP() const {
    return coefP;
}

const vector<double> &Data::getCoefV() const {
    return coefV;
}

const vector<tuple<double, int, int, int, int,int>> &Data::getParcelsC() const {
    return parcelsC;
}

const vector<tuple<double, int, int, int,int>> &Data::getVansC() const {
    return vansC;
}

vector<double> Data::coefVans(list<vector<int>> & vans) {

    int maxVolume = 0;
    int maxWeight = 0;

    for (auto v:vans) {
        if (v[0] > maxVolume) maxVolume=v[0];
        if (v[1] > maxWeight) maxWeight=v[1];
    }

    vector<double> coefficients;

    for (auto v:vans) {
        double coefV = (double)v[0] / (double)maxVolume;
        double coefW = (double)v[1] / (double)maxWeight;

        double vanPriority = coefV + coefW;
        coefficients.push_back(vanPriority);
    }

    return coefficients;
}

vector<double> Data::coefParcels(list<vector<int>> & parcels) {

    int maxVolume = 0;
    int maxWeight = 0;

    for (auto p:parcels) {
        if (p[0] > maxVolume) maxVolume=p[0];
        if (p[0] > maxWeight) maxWeight=p[0];

    }

    vector<double> coefficients;

    for (auto p:parcels) {
        double coefV = (double)p[0] / (double)maxVolume;
        double coefW = (double)p[1] / (double)maxWeight;

        double parcelPriority = coefV + coefW;
        coefficients.push_back(parcelPriority);
    }

    return coefficients;
}

void Data::addCoefs(list<vector<int>> &parcels, list<vector<int>> &vans, vector<double> coefparcels,vector<double> coefvans) {

    int nparcel = 0;
    for (auto p:parcels) {
        tuple<double, int, int, int, int,int> parcel {coefparcels[nparcel], p[0], p[1], p[2], p[3],nparcel};
        this->parcelsC.push_back(parcel);
        nparcel++;
    }

    int nvan = 0;
    for (auto v:vans) {
        tuple<double, int, int, int,int> van {coefvans[nvan], v[0], v[1], v[2], nvan};
        this->vansC.push_back(van);
        nvan++;
    }

}
