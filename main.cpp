#include <iostream>
#include "Express.h"
#include <algorithm>
#include "Data.h"
#include "NStaff.h"
#include "Profit.h"
#include "Interface.h"

using namespace std;

int main() {

    Data data = Data();  //read data from files
    Interface interface(data);  //initialize the interface of the application
    interface.menu();

    return 0;
}
