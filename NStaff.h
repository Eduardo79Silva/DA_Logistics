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

/**
     * Classe que contém os algoritmos nescessários para o cenário 1, minimizar o número de staff a fazer entregas (ou seja, o número de carrinhas em atividade.
     */

class NStaff {

public:

    /**
     * Lê para as listas de vetores parcels e vans todos os dados da empresa de logística para poderem ser usados pelo programa.
     * @param parcels Vetor de tuplos que contêm as informações das encomendas assim como o s coeficientes de "importância" calculados para as mesmas.
     * @param vans Vetor de tuplos que contêm as informações das carrinhas assim como o s coeficientes de "importância" calculados para as mesmas.
     * @return Um vetor com as encomendas que são atribuídas a cada carrinha.
     */
    static vector<vector<int>> minStaff(vector<tuple<double,int,int,int,int,int>> parcels, vector<tuple<double,int,int,int,int>> vans);


};


#endif //DA_LOGISTICS_NSTAFF_H
