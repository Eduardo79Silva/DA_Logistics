#include <iostream>
#include "Express.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Express express;
    Data data = Data();
    list<vector<int>> parcelsV = data.getParcels();
    vector<vector<int>> parcelsL{make_move_iterator(begin(parcelsV)), make_move_iterator(end(parcelsV))};
    express.sortParcels(parcelsL);
    return 0;
}
