#pragma once
#include  <SFML/Graphics.hpp>
#include  <SFML/System.hpp>
#include <iostream>
#include "Player.h"
#include "Collider.h"

void pvparena() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Feenix Chronicles", sf::Style::Close);
    sf::RectangleShape arena_background(sf::Vector2f(1280, 720));
    sf::Texture arena_background_texture;
    arena_background_texture.loadFromFile("backgrounds/battleground1.jpg");
    arena_background.setTexture(&arena_background_texture);
    window.setFramerateLimit(60);

    //Creating players
    sf::Texture player1_texture;
    if (!player1_texture.loadFromFile("sprites/karatake.png")) {
        std::cout << "unable to load texture" << std::endl;
    }
    sf::Texture player2_texture;
    if (!player2_texture.loadFromFile("sprites/karatake.png")) {
        std::cout << "unable to load texture" << std::endl;
    }
    Player player1(&player1_texture, 200, 500, true);
    Player player2(&player2_texture, 1080, 500, false);

    //Collision System
    Collider collider1(player1.player_hitbox);
    Collider collider2(player2.player_hitbox);

    sf::Clock clock;

    int attack_type1 = 100;
    int attack_type2 = 100;
    while (window.isOpen()) {
        float delta_time = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event _event;
        while (window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {

                window.close();
            }

            if (_event.type = sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::J) {
                    attack_type1 = player1.attack_set(0);
                }
                if (_event.key.code == sf::Keyboard::Num1) {
                    attack_type2 = player2.attack_set(0);
                }
            }

        }
        if (player1.is_attacking) {
            if (attack_type1 == 0) {
                player1.is_attacking = player1.attacker(0, delta_time);
            }
        }
        else {
            player1.ResetJumping();
            player1.jumper(delta_time);

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

        }
        if (player2.is_attacking) {
            if (attack_type2 == 0) {
                player2.is_attacking = player2.attacker(0, delta_time);
            }
        }
        else {
            //Jump checking
            player2.ResetJumping();
            player2.jumper(delta_time);

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
            if (collider1.CheckCollision(collider2)) {
                std::cout << "They are close" << std::endl;
            }
        }
        window.clear();
        window.draw(arena_background);
        player1.draw(window);
        player2.draw(window);
        window.display();
    }
}
