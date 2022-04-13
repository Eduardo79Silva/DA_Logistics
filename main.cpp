#include <iostream>
#include "Express.h"
#include <algorithm>
#include "Data.h"
#include "NStaff.h"
#include "Interface.h"

using namespace std;

int main() {

    Data data = Data();  //read data from files
    Express express;
    vector<vector<int>> newParcels;
    for(auto v : data.getParcels()){
        newParcels.push_back(v);
    }

    cout << "Debug" << endl;

    express.sortParcels(newParcels);

    Interface interface(data);  //initialize the interface of the application
    interface.menu();

    return 0;
}
