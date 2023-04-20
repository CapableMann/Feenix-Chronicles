#pragma once
#include  <SFML/Graphics.hpp>
#include <iostream>

void pvparena() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Feenix Chronicles", sf::Style::Close);
    sf::RectangleShape arena_background(sf::Vector2f(1280, 720));
    sf::Texture arena_background_texture;
    arena_background_texture.loadFromFile("backgrounds/battleground1.jpg");
    arena_background.setTexture(&arena_background_texture);


    sf::Event _event;

    while (window.isOpen()) {

        while (window.pollEvent(_event)) {

            if (_event.type == sf::Event::Closed) {

                window.close();
            }
            
        }
        window.clear();
        window.draw(arena_background);
        window.display();
    }
}
