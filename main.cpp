#include <iostream>
#include <algorithm>
#include "Data.h"
#include "NStaff.h"
#include "Interface.h"

using namespace std;

int main() {

    Data data = Data();  //read data from files

    Interface interface(data);  //initialize the interface of the application
    interface.menu();

    /*
    vector<tuple<double, int, int, int, int>> encomendas = data.getParcelsC();
    vector<tuple<double, int, int, int>> carrinhas = data.getVansC();

    sort(encomendas.begin(), encomendas.end());
    sort(carrinhas.rbegin(), carrinhas.rend());

    vector<vector<int>> distribuicao = NStaff::minStaff(encomendas, carrinhas);

    int carr = 0;
    for (auto v:distribuicao) {
        int totV = 0;
        int totW = 0;
        cout << "Carrinha " << carr << ": ";
        for (auto it:v) {
            cout << get<1>(encomendas[it]) << "/" << get<2>(encomendas[it]) << " " ;
            totV += get<1>(encomendas[it]);
            totW += get<2>(encomendas[it]);
        }
        cout << "Totais: " << totV << "/" << totW << " ";
        cout << "Capacidades: " << get<1>(carrinhas[carr]) << "/" << get<2>(carrinhas[carr]);
        cout << endl;
        carr++;
    }
     */

    return 0;
}
