//
// Created by Afonso Martins on 04/12/2021.
//
using namespace std;
#include "Interface.h"

Interface::Interface(Data data) {
    this->data = data;
}
void Interface::menu() {
    //povoarSistema();
    char c;
    while (true) {
        system("CLS");
        std::cout << "\n[FEUP Logistics]\n";
        std::cout << "\n*** Optimization is our passion ***\n";
        std::cout << "\n[1] List parcels for delivery"
                  << "\n[2] List available vans"
                  << "\n[3] Optimize number of staff involved in the deliveries"
                  << "\n[4] Optimize the companys profit"
                  << "\n[5] Optimize the express deliveries"
                  << "\n[0] Sair\n"
                  << "\n>";

        cin.clear();
        std::cin >> c;
        cin.clear();
        switch (c) {
            case '1':
                parcelsPage();
                break;
            case '2':
                vansPage();
                break;
            case '3':
                minStaffPage();
                break;
            case '4':
                //pagClientes();
                break;
            case '5':
                //pagClientes();
                break;
            case '0':
                //outputDados();
                return;
            default:
                std::cout << "Opcao invalida\n";
        }
    }
}


void Interface::parcelsPage() {

    int c;

    TextTable t( '-', '|', '+' );
    t.add("ID");
    t.add("Volume");
    t.add("Weight");
    t.add("Reward");
    t.add("Duration");
    t.endOfRow();
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.endOfRow();

    int id = 0;

    list<vector<int>> parcels = this->data.getParcels();

    for (auto p:parcels) {
        t.add(to_string(id));
        t.add(to_string(p[0]) + " m3");
        t.add(to_string(p[1]) + " kg");
        t.add(to_string(p[2]) + " $");
        t.add(to_string(p[3]) + " s");
        t.endOfRow();
        id++;
    }

    while (true) {
        system("CLS");
        std::cout << "[Parcels for delivery]\n" << "\n";
        std::cout << t;
        std::cout << "\n[0] Sair\n"
                  << "\n>";
        std::cin >> c;
        if (c==0) {
            break;
        }
    }

}

void Interface::vansPage() {

    int c;

    TextTable t( '-', '|', '+' );
    t.add("ID");
    t.add("Volume capacity");
    t.add("Weight capacity");
    t.add("Cost");
    t.endOfRow();
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.endOfRow();

    int id = 0;

    list<vector<int>> vans = this->data.getVans();

    for (auto v:vans) {
        t.add(to_string(id));
        t.add(to_string(v[0]) + " m3");
        t.add(to_string(v[1]) + " kg");
        t.add(to_string(v[2]) + " $");
        t.endOfRow();
        id++;
    }

    while (true) {
        system("CLS");
        std::cout << "[Available vans]\n" << "\n";
        std::cout << t;
        std::cout << "\n[0] Sair\n"
                  << "\n>";
        std::cin >> c;
        if (c==0) {
            break;
        }
    }

}

void Interface::minStaffPage() {

    int c;

    TextTable t( '-', '|', '+' );
    t.add(" ");
    t.add("Encomendas (ID)");
    t.add("Total Weight used/Weight capacity");
    t.add("Total Volume used/Volume capacity");
    t.endOfRow();
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.add(" ");
    t.endOfRow();

    int id = 0;

    vector<tuple<double, int, int, int, int, int>> parcels = this->data.getParcelsC();
    vector<tuple<double, int, int, int, int>> vans = this->data.getVansC();

    sort(parcels.begin(), parcels.end());
    sort(vans.rbegin(), vans.rend());

    vector<vector<int>> distribuicao = NStaff::minStaff(parcels, vans);

    //TextTable version not working well even in fullscreen
    //int carr = 0;
    /*for (auto v:distribuicao) {
        t.add("Carrinha " + to_string(carr));
        int totW = 0;
        int totV = 0;

        string pID = "";
        for (auto it:v) {
            totW += get<2>(parcels[it]);
            totV += get<1>(parcels[it]);
            pID = pID + to_string(get<5>(parcels[it])) + ", ";
        }

        t.add(pID);
        t.add(to_string(totW) + "/" + to_string(get<2>(vans[carr])));
        t.add(to_string(totV) + "/" + to_string(get<1>(vans[carr])));
        t.endOfRow();
        carr++;
    }*/

    while (true) {
        system("CLS");
        std::cout << "[Parcel distribution per van]\n";
        int carr = 0;
        for (auto v:distribuicao) {
            //cout << "\n" << "Van " + to_string(carr) << " - Parcels: \n\n";
            int totW = 0;
            int totV = 0;

            string pID = "";
            for (auto it:v) {
                totW += get<2>(parcels[it]);
                totV += get<1>(parcels[it]);
                pID = pID + to_string(get<5>(parcels[it])) + ", ";
            }

            if (!pID.empty()) {
                pID.pop_back();
                pID.pop_back();
            }

            if (totW == 0 || totV == 0) break;
            cout << "\n" << "VAN " + to_string(carr) << " - Parcels: \n\n";
            cout << pID << "" << "\n\n";
            cout << "Weight balance: " + to_string(totW) + "/" + to_string(get<2>(vans[carr])) << "     ";
            cout << "Volume balance: " + to_string(totV) + "/" + to_string(get<1>(vans[carr])) << "     " << "\n";
            carr++;
        }
        cout << "\nThere are " << to_string(distribuicao.size()-carr) << " unused vans.\n";
        std::cout << "\n[0] Sair\n"
                  << "\n>";
        std::cin >> c;
        if (c==0) {
            break;
        }
    }

}







