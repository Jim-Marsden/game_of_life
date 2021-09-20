//
// Created by james on 9/19/2021.
//

#ifndef GAME_OF_LIFE_MAIN_H
#define GAME_OF_LIFE_MAIN_H

#include <vector>

namespace bol::rules::test{
    void test_print();
    std::vector<std::vector<char>> update_rules(std::vector<std::vector<char>> rules);
}

#endif //GAME_OF_LIFE_MAIN_H
