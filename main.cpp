#include <iostream>
#include <algorithm>
#include "Data.h"
#include "NStaff.h"

using namespace std;

int main() {

    Data data = Data();  //read data from files



    /*vector<int> parcelsg = {19,24, 27, 30, 30, 36, 36, 36, 42, 42 ,48};
    sort(parcelsg.rbegin(), parcelsg.rend());
    vector<int> vansg = {100, 100, 100, 100, 100};
    vector<vector<int>> vansitemsg = NStaff::minStaff(parcelsg, vansg);

    vector<int> parcels = {100, 40, 35, 30, 25, 18, 17, 16, 15, 10, 8, 3};
    vector<int> vans = {70, 80, 90, 100};
    vector<vector<int>> vansitems = NStaff::minStaff(parcels, vans);*/







    cout << "Debug" << endl;

    list<vector<int>> enc = data.getParcels();
    list<vector<int>> car = data.getVans();
    vector<int> encomendas;
    vector<int> carrinhas;

    for (auto v:enc) {
        encomendas.push_back(v[0]);
    }
    for (auto v:car) {
        carrinhas.push_back(v[0]);
    }

    sort(encomendas.begin(), encomendas.end());
    sort(carrinhas.rbegin(), carrinhas.rend());
    vector<vector<int>> distribuicao = NStaff::minStaff(encomendas, carrinhas);

    int carr = 0;
    for (auto v:distribuicao) {
        int tot = 0;
        cout << carr << " ";
        for (auto it:v) {
            cout << encomendas[it] << " " ;
            tot += encomendas[it];
        }
        cout << "-" << tot;
        cout << "-" << carrinhas[carr];

        cout << endl;
        carr++;
    }

    return 0;
}
