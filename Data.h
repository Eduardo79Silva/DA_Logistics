//
// Created by Afonso Martins on 30/03/2022.
//

#ifndef DA_LOGISTICS_DATA_H
#define DA_LOGISTICS_DATA_H


#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

/**
     * Classe que representa os dados telativos a encomendas e carrinhas da empresa de logística, para que os mesmos possam ser usados globalmente por outras classes que contêm os algoritmos que solucionam os vários problemas propostos.
     */

class Data {

private:

    list<vector<int>> parcels;
    list<vector<int>> vans;
public:
    const list<vector<int>> &getParcels() const;

    const list<vector<int>> &getVans() const;

public:

    Data();

    /**
     * Lê para as listas de vetores parcels e vans todos os dados da empresa de logística para poderem ser usados pelo programa.
     * @param parcels Lista de vetores em que serão guardados internamente os dados relativos às encomendas.
     * @param vans Lista de vetores em que serão guardados internamente os dados relativos às carrinhas.
     */
    void readData(list<vector<int>> & parcels, list<vector<int>> & vans);









};


#endif //DA_LOGISTICS_DATA_H
