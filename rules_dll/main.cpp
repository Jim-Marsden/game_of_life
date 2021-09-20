//
// Created by james on 9/19/2021.
//

#include "main.hpp"
#include <iostream>

void bol::rules::test::test_print() {
    std::cout << "bol::rules::test::test_print()\n";
}

std::vector<std::vector<char>> bol::rules::test::update_rules(std::vector<std::vector<char>> rules) {

    /*
     *     Any live cell with fewer than two live neighbours dies, as if by underpopulation.
        Any live cell with two or three live neighbours lives on to the next generation.
        Any live cell with more than three live neighbours dies, as if by overpopulation.
        Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
     */
//    int x{}, y{};
    int life_counter{};
    auto result{std::move(rules)};
    const auto max_size_x = result.size(), max_size_y = result[0].size();
    for (int x{}; x < result.size(); ++x) {
        auto x_min = (x - 1) < 0 ? max_size_x - 1 : x - 1;
        auto x_max = (x + 1) >= max_size_x ? 0 : x + 1;
//        std::cout << "x: " << '\t' << x_min << '\t' << x << '\t' << x_max << '\n';

        for (int y{}; y < result[x].size(); ++y) {

            life_counter = 0;
            auto y_min = (y - 1) < 0 ? result[x].size() - 1 : y - 1;
            auto y_max = (y + 1) >= result[x].size() ? 0 : y + 1;

//            std::cout << "y: " << '\t' << y_min << '\t' << y << '\t' << y_max << '\n';

            /**
             *  [ x_min, y_min]  [ x_min, y]     [ x_min, y_max]
             *  [x, y_min]       [x, y]          [x, y_max]
             *  [x_max, y_min]  [x_max, y]      [x_max, y_max]
             */
            if (result[x_min][y_min] == 'a') life_counter++;
            if (result[x_min][y] == 'a') life_counter++;
            if (result[x_min][y_max] == 'a') life_counter++;

            if (result[x][y_min] == 'a') life_counter++;
            if (result[x][y_max] == 'a') life_counter++;

            if (result[x_max][y_min] == 'a') life_counter++;
            if (result[x_max][y] == 'a') life_counter++;
            if (result[x_max][y_max]  == 'a') life_counter++;

            /*
             * Any live cell with fewer than two live neighbours dies, as if by underpopulation.
             * Any live cell with two or three live neighbours lives on to the next generation.
             * Any live cell with more than three live neighbours dies, as if by overpopulation.
             * Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                    */


            if ( result[x][y] == 'a') {
                result[x][y] = ( life_counter > 1 && life_counter < 4 ) ? 'a' : 'd';
            }
            else {
                result[x][y] =  ( life_counter == 3 ) ? 'a' : 'd' ;
            }
//            if(life_counter) std::cout << 'n' << life_counter << 'x' << x << 'y' << y  << "status: " << result[x][y] << '\n';
//            if (3 == life_counter) result[x][y] = true;
//            else if (life_counter > 3)result[x][y] = false;
//            else if (life_counter < 2)result[x][y] = false;
//            std::cout << life_counter << '\n';

        }
    }
    return result;
}


std::vector<std::vector<char>> cool_but_wrong(std::vector<std::vector<char>> rules) {

    /*
     *     Any live cell with fewer than two live neighbours dies, as if by underpopulation.
        Any live cell with two or three live neighbours lives on to the next generation.
        Any live cell with more than three live neighbours dies, as if by overpopulation.
        Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
     */
//    int x{}, y{};
    int life_counter{};
    auto result{std::move(rules)};
    const auto max_size_x = result.size(), max_size_y = result[0].size();
    for (int x{}; x < result.size(); ++x) {
        auto x_min = (x - 1) < 0 ? max_size_x - 1 : x - 1;
        auto x_max = (x + 1) >= max_size_x ? 0 : x + 1;

        for (int y{}; y < result[x].size(); ++y) {

            life_counter = 0;
            auto y_min = (y - 1) < 0 ? max_size_y - 1 : y - 1;
            auto y_max = (y + 1) >= max_size_y ? 0 : y + 1;


            if (result[x_min][y_min] != false) life_counter++;
            if (result[x_min][y] != false) life_counter++;
            if (result[x_min][y_max] != false) life_counter++;

            if (result[x][y_min] != false) life_counter++;
            if (result[x][y_max] != false) life_counter++;

            if (result[x_min][y_min] != false) life_counter++;
            if (result[x][y_min] != false) life_counter++;
            if (result[x_max][y_min] != false) life_counter++;


            if (life_counter < 2) result[x][y] = false;
            if (life_counter > 4) result[x][y] = false;
            if (life_counter == 3) result[x][y] = true;
//            std::cout << life_counter << '\n';

        }
    }
    return result;
}
