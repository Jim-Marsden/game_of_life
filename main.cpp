//
// Created by james on 9/19/2021.
//


#include <iostream>
#include "renderer_lib/main.hpp"
#include "rules_dll/main.hpp"

#include <cstdlib>
#include <chrono>

int main(){

    srand(time(nullptr));
    bol::renderer::test::data_type data {};
    data.reserve(150);
    data.resize(150);
    bool flipper{};
    for(auto & e : data ){
        e.reserve(150);
        e.resize(150);
        for(auto & element : e){
            element = ((rand() % 40)  == 0) ? 'a' : 'd';
        }
    }
    bol::renderer::test::draw(data);


    while(bol::renderer::test::draw(data)){data = bol::rules::test::update_rules(data);
    };

    return {};
}
