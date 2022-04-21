//
// Created by admin on 4/19/2022.
//

#include "Profit.h"

bool sortByCostVans(const tuple<double,int,int,int,int>& a, const tuple<double,int,int,int,int>& b) {
    return (get<4>(a)/get<0>(a)*100 < get<4>(b))/get<0>(b)*100;
}

int max(int a, int b) {
    if(a>b) {
        return a;
    }
    return b;
}

void Profit::maxProfit(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans) {

    sort(vans.begin(), vans.end(), sortByCostVans);

    vector<double> profit;
    vector<int> coeficient;
    vector<int> parcelsId;
    int usedVans = 0;

    profit.push_back(0);
    coeficient.push_back(0);
    parcelsId.push_back(0);

    for(int i=0; i<parcels.size(); i++) {
        coeficient.push_back(get<0>(parcels[i]));
        profit.push_back(get<3>(parcels[i]));
        parcelsId.push_back(get<5>(parcels[i]));
    }


    for(int q=0; q<vans.size();q++) {
        if(parcels.size()!=parcelsId.size())
            usedVans+=1;
        if(profit.size() == 1)
            break;
        int n = profit.size();
        int vanC = get<0>(vans[q]);
        int  knapsack[n+1][vanC+1];
        for(int i=0; i<n; i++) {
            for(int c=0; c<=vanC; c++) {
                if(i==0 || c==0)
                    //  If we are in the first row or column, put 0 in the table as Weight/Profit are always 0
                    knapsack[i][c] = 0;
                else if(coeficient[i] <= c)
                    //  If the weight of the current object i is <= than w, calculate profit
                    // Example for first case, we have i=1 and w=0, write 0, then i=1, w=1, so Weight[1] = 2. 2 is not <=1 , so just copy Table[1-1][1] = 0
                    // After we have i=1, w=2, so Weight[1] = 2 <=2, it means we take the max between Profit[1]+Table[0][2-2] and Table[1-1][2], which is  Profit[1] = 1

                    knapsack[i][c] = max(profit[i]+knapsack[i-1][c-coeficient[i]],knapsack[i-1][c]);
                else
                    knapsack[i][c] = knapsack[i-1][c];
            }
        }

        int op = knapsack[n][vanC];
        if(op > get<3>(vans[q])) {

            cout << "Optimal solution is : " << op << '\n';
            cout << "The profit is : " << op-get<3>(vans[q]) << '\n';

            int i=n,j=vanC;
            while(i>0 && j>0) {
                if(knapsack[i][j] == knapsack[i-1][j])
                    i--;
                else {
                    parcelsId.erase(parcelsId.begin()+i);
                    profit.erase(profit.begin()+i);
                    coeficient.erase(coeficient.begin()+i);
                    j=j-coeficient[i];
                    i--;
                    n--;
                }
            }
        }

    }

   for(int i =0; i<parcelsId.size(); i++) {
        cout << "Id das encomendas que sobram " << parcelsId[i] << '\n';
    }
    cout << "There are " << vans.size()-usedVans << " unused vans";
}
