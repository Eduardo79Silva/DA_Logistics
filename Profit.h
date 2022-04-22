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

/**
 * Classe que contém os algoritmos nescessários para o cenário 2, maximizando o lucro recebido, entregar o máximo de encomendas possíveis
 */

class Profit {
public:

    /**
     * função auxiliar que retorna o máximo entre 2 números
     * @param a primeiro número
     * @param b segundo número
     * @return o máximo entre 2 números
     */

    static int max(int a, int b);

    /**
     * Lê para as listas de vetores parcels e vans todos os dados da empresa de logística para poderem ser usados pelo programa.
     * @param parcels Vetor de tuplos que contêm as informações das encomendas assim como o s coeficientes de "importância" calculados para as mesmas.
     * @param vans Vetor de tuplos que contêm as informações das carrinhas assim como o s coeficientes de "importância" calculados para as mesmas.
     */

    static void maxProfit(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans);

};


#endif //DA_LOGISTICS_PROFIT_H
