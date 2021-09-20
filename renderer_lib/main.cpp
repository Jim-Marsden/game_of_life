//
// Created by james on 9/19/2021.
//

#include "main.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

void bol::renderer::test::test_print() {
    std::cout << "bol::renderer::test::test_print!\n";
}

bool bol::renderer::test::test(int) {
    std::cout << "fuck you!\n";
    return false;
}

static sf::RenderWindow window{sf::VideoMode{600, 600}, "title"};

bool bol::renderer::test::draw(bol::renderer::test::data_type data) {

    sf::Event event{};
    sf::RectangleShape rectangleShape({5, 5});
    window.pollEvent(event);
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::Resized){
            std::cout << "RESIZED!~\n";
        }
    }

    window.clear();
    for (auto &array: data) {
        for (auto &element: array) {
            if (element == 'a') {
                window.draw(rectangleShape);
            }
            rectangleShape.setPosition(
                    {rectangleShape.getPosition().x, rectangleShape.getPosition().y +5});
        }
        rectangleShape.setPosition(
                {rectangleShape.getPosition().x + 5, 0});
    }
    window.display();
    return window.isOpen();
}



