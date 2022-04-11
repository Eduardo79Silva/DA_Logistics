
//
// Created by Afonso Martins on 04/12/2021.
//

#ifndef PROJETOAED_MAINMENU_H
#define PROJETOAED_MAINMENU_H

#include<iostream>
#include<ctime>
#include "list"
#include <string>
#include "TextTable.h"
#include <algorithm>
#include "Data.h"
#include "NStaff.h"

/**
     * Classe que representa o menu da aplicação.
     */

class Interface {
private:
    Data data;
public:
    /**
     * Construtor que inicia a aplicação
     */
    Interface(Data data);
    /**
     * Mostra a página principal do menu.
     */
    void menu();

    void parcelsPage();
    void vansPage();
    void minStaffPage();
};


#endif //PROJETOAED_MAINMENU_H

