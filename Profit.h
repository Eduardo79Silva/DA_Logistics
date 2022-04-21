//
// Created by admin on 4/19/2022.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#ifndef DA_LOGISTICS_PROFIT_H
#define DA_LOGISTICS_PROFIT_H


class Profit {
public:
    //bool sortByCostVans(const tuple<double,int,int,int,int>& a, const tuple<double,int,int,int,int>& b);

    //int max(int a, int b);

    static void maxProfit(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans);

};


#endif //DA_LOGISTICS_PROFIT_H
