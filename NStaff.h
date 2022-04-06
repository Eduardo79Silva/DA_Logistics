//
// Created by Afonso Martins on 31/03/2022.
//

#ifndef DA_LOGISTICS_NSTAFF_H
#define DA_LOGISTICS_NSTAFF_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <tuple>

using namespace std;

class NStaff {

public:

    static vector<vector<int>> minStaff(vector<int> parcelsVol, vector<int> vansVol);

    static vector<vector<int>> minStaffNew(vector<tuple<double,int,int,int,int>> parcels, vector<tuple<double,int,int,int>> vans);

};


#endif //DA_LOGISTICS_NSTAFF_H
