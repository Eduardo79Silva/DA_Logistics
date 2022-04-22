//
// Created by eduardo on 05/04/22.
//

#ifndef DA_LOGISTICS_EXPRESS_H
#define DA_LOGISTICS_EXPRESS_H
#include "Data.h"


class Express {

private:
    /*
     * Vector of vectors containing the result of the algorithm that chooses the best parcels taking into account their time
     */
    inline static vector<vector<int>> chosenParcels;

public:
    /*
     * Function that sorts the parcels by their time to deliver
     * @param parcels - the vector of vectors that will be sorted
     */
    static void sortParcels(vector<vector<int>> &parcels);
    /*
     * Algorithm in charge of choose the best parcels for that day (from 9AM to 5PM)
     * @return number of chosen parcels
     */
    static int chooseParcels(vector<vector<int>> sortedParcels);
    /*
     * Function that returns the chosen parcels
     */
    static vector<vector<int>> getChosenParcels();

};


#endif //DA_LOGISTICS_EXPRESS_H
