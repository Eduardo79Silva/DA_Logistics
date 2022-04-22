//
// Created by admin on 4/19/2022.
//

#include "Profit.h"


bool sortByCostVans(const tuple<double,int,int,int,int>& a, const tuple<double,int,int,int,int>& b) {
    return (get<4>(a)/get<0>(a)*100 < get<4>(b))/get<0>(b)*100;  // Ordena as carrinhas pelo custo menor e que tenham ao mesmo tempo maior capacidade de transporte
}


// retorna o número máximo

int Profit::max(int a, int b) {
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
    //int total=0;

    profit.push_back(0);
    coeficient.push_back(0);
    parcelsId.push_back(0);

    for(int i=0; i<parcels.size(); i++) {
        coeficient.push_back(get<0>(parcels[i]));
        profit.push_back(get<3>(parcels[i]));
        parcelsId.push_back(get<5>(parcels[i]));
    }

    // Percorre todas as carrinhas vendo qual é a capacidade máxima de encomendas que é possivel colocar em cada carrinha

    for(int q=0; q<vans.size();q++) {
        if(parcels.size()!=parcelsId.size())
            usedVans+=1;
        int n = profit.size();
        int vanC = get<0>(vans[q]);
        int  knapsack[n+1][vanC+1];
        for(int i=0; i<=n; i++) {  // Começa a contruir a tabela para o knapsack
            for(int c=0; c<=vanC; c++) {
                if(i==0 || c==0)
                    //  Se estivermos na primeira linha ou coluna da tabela, o valor da tabela é zero
                    knapsack[i][c] = 0;
                else if(coeficient[i-1] <= c)
                    //  Se o coeficiente da encomenda atual for menor do que o coeficiente, calcule o lucro


                    knapsack[i][c] = Profit::max(profit[i-1]+knapsack[i-1][c-coeficient[i-1]],knapsack[i-1][c]);
                else
                    knapsack[i][c] = knapsack[i-1][c];
            }
        }

        int op = knapsack[n][vanC];

        // Se o lucro total de encomendas que é possível colocar na carrinha for superior ao custo da carrinha, calcula-se a subtração e remove-se as encomendas que foram posta na carrinha da lista de encomendas

        if(op > get<3>(vans[q])) {
            cout << "The van number " << get<4>(vans[q])  << " gets a profit of " << op-get<3>(vans[q]) << '\n';
            //total+=op-get<3>(vans[q]);
            int i=n,j=vanC;
            while(i>0 && j>0) {
                if(knapsack[i][j] == knapsack[i-1][j])
                    i--;
                else {
                    // remoção das encomendas que já foram postas na carrinha
                    parcelsId.erase(parcelsId.begin()+i-1);
                    profit.erase(profit.begin()+i-1);
                    coeficient.erase(coeficient.begin()+i-1);
                    j=j-coeficient[i];
                    i--;
                    n--;
                }
            }
        }

    }

   cout << "There are " << vans.size()-usedVans << " unused vans" << '\n';
    //cout << "The total profit is " << total << '\n';
}
