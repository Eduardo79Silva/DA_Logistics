//
// Created by Afonso Martins on 30/03/2022.
//

#ifndef DA_LOGISTICS_DATA_H
#define DA_LOGISTICS_DATA_H


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <tuple>

using namespace std;

/**
     * Classe que representa os dados relativos a encomendas e carrinhas da empresa de logística, para que os mesmos possam ser usados globalmente por outras classes que contêm os algoritmos que solucionam os vários problemas propostos.
     */

class Data {

private:

    list<vector<int>> parcels;
    list<vector<int>> vans;

    vector<double> coefP;
    vector<double> coefV;

    vector<tuple<double,int,int,int,int>> parcelsC;
    vector<tuple<double,int,int,int>> vansC;

public:

    const list<vector<int>> &getParcels() const;
    const list<vector<int>> &getVans() const;
    const vector<double> &getCoefP() const;
    const vector<double> &getCoefV() const;
    const vector<tuple<double, int, int, int, int>> &getParcelsC() const;
    const vector<tuple<double, int, int, int>> &getVansC() const;

public:

    Data();

    /**
     * Lê para as listas de vetores parcels e vans todos os dados da empresa de logística para poderem ser usados pelo programa.
     * @param parcels Lista de vetores em que serão guardados internamente os dados relativos às encomendas.
     * @param vans Lista de vetores em que serão guardados internamente os dados relativos às carrinhas.
     */
    void readData(list<vector<int>> & parcels, list<vector<int>> & vans);
    /**
     * Calcula o coeficiente de "importância" associado a cada carrinha.
     * @param vans Lista de vetores em que estão guardados os dados relativos às carrinhas.
     */
    vector<double> coefVans(list<vector<int>> & vans);
    /**
     * Calcula o coeficiente de "importância" associado a cada encomenda.
     * @param vans Lista de vetores em que estão guardados os dados relativos às encomendas.
     */
    vector<double> coefParcels(list<vector<int>> & parcels);
    /**
     * Junta as informações das encomendas e das carrinhas com os seus respetivos coeficientes num tuplo.
     * @param parcels Lista de vetores em que estão guardados os dados relativos às encomendas.
     * @param vans Lista de vetores em que estão guardados os dados relativos às carrinhas.
     * @param coefparcels Vetor com os coeficientes das encomendas.
     * @param coefvans Vetor com os coeficientes das carrinhas.
     */
    void addCoefs(list<vector<int>> & parcels, list<vector<int>> & vans, vector<double> coefparcels,vector<double> coefvans);

};


#endif //DA_LOGISTICS_DATA_H
