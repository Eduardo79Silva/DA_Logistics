//
// Created by pedro on 11/04/2022.
//

#ifndef DA_LOGISTICS_PROFIT_H
#define DA_LOGISTICS_PROFIT_H
#include "Data.h"
#include "NStaff.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>

/**
 * Classe que contém os algoritmos necessários para o cenário 2, maximizar o lucro da empresa para a entrega do maior número de pedidos num dia.
 */

class Profit {
public:

    static bool sortByCost(const tuple<double,int,int,int,int,int>& a, const tuple<double,int,int,int,int,int>& b);
    static bool sortByProfit(const tuple<double,int,int,int,int,int>& a, const tuple<double,int,int,int,int,int>& b);
    /**
     * Lê para as listas de vetores parcels e vans todos os dados da empresa de logística para poderem ser usados pelo programa.
     * @param parcels Vetor de tuplos que contêm as informações das encomendas assim como o s coeficientes de "importância" calculados para as mesmas.
     * @param vans Vetor de tuplos que contêm as informações das carrinhas assim como o s coeficientes de "importância" calculados para as mesmas.
     * @return
     */

    static vector<vector<int>> maxProfit(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans);
};


#endif //DA_LOGISTICS_PROFIT_H
