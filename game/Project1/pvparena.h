#pragma once
#include  <SFML/Graphics.hpp>
#include  <SFML/System.hpp>
#include <iostream>
#include "Player.h"

void pvparena() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Feenix Chronicles", sf::Style::Close);
    sf::RectangleShape arena_background(sf::Vector2f(1280, 720));
    sf::Texture arena_background_texture;
    arena_background_texture.loadFromFile("backgrounds/battleground1.jpg");
    arena_background.setTexture(&arena_background_texture);
    window.setFramerateLimit(60);

    //Creating players
    Player player1(sf::Color::Red, 200, 500);
    Player player2(sf::Color::Blue, 1080, 500);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event _event;
        while (window.pollEvent(_event)) {

            if (_event.type == sf::Event::Closed) {

                window.close();
            }
            
        }

        float delta_time = clock.getElapsedTime().asSeconds();
        clock.restart();
        
        //Jump checking
        player1.ResetJumping();
        player2.ResetJumping();
        player1.jumper(delta_time);
        player2.jumper(delta_time);
        
        //Move player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player1.MakeJump();
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player1.mover(0.f, 1.f, delta_time);
        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player1.mover(-1.f, 0.f, delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player1.mover(1.f, 0.f, delta_time);
        }

        //Move player 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player2.MakeJump();
        }
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player2.mover(0.f, 1.f, delta_time);
        }*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player2.mover(-1.f, 0.f, delta_time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player2.mover(1.f, 0.f, delta_time);
        }


        window.clear();
        window.draw(arena_background);
        player1.draw(window);
        player2.draw(window);
        window.display();
    }
}
