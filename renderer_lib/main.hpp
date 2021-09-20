//
// Created by james on 9/19/2021.
//

#ifndef GAME_OF_LIFE_MAIN_HPP
#define GAME_OF_LIFE_MAIN_HPP

#include <vector>
#include <array>
namespace bol::renderer::test{
    using data_type = std::vector<std::vector<char>>;
    void test_print();
    bool test(int);


   bool draw(data_type data); // I mean to copy, for threadding reasons. a few thousand bools aren't huge;

}

#endif //GAME_OF_LIFE_MAIN_HPP
