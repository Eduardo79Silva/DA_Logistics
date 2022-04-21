//
// Created by eduardo on 05/04/22.
//

#ifndef DA_LOGISTICS_EXPRESS_H
#define DA_LOGISTICS_EXPRESS_H
#include "Data.h"


class Express {

private:
    inline static vector<vector<int>> chosenParcels;

public:
    static void sortParcels(vector<vector<int>> &parcels);
    static int chooseParcels(vector<vector<int>> sortedParcels);
    static vector<vector<int>> getChosenParcels();

};


#endif //DA_LOGISTICS_EXPRESS_H
