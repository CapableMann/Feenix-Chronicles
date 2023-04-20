#include  <SFML/Graphics.hpp>
#include  <iostream>
#include "main_menu.h"
#include "pvparena.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Feenix Chronicles",sf::Style::Close);
    main_menu menu(window.getSize().x, window.getSize().y);
    sf::RectangleShape main_background(sf::Vector2f(1280, 720));
    sf::Texture main_background_texture;
    main_background_texture.loadFromFile("backgrounds/main_menu.jpg");
    main_background.setTexture(&main_background_texture);
   
    
    sf::Event _event;

    while (window.isOpen()) {

        while (window.pollEvent(_event)) {

            if (_event.type == sf::Event::Closed) {

                window.close();
            }
            if (_event.type == sf::Event::KeyReleased) {
                if (_event.key.code == sf::Keyboard::Up) {
                    menu.move_up();
                    break;
                }
                if (_event.key.code == sf::Keyboard::Down) {
                    menu.move_down();
                    break;
                }
                if (_event.key.code == sf::Keyboard::Return) {
                    if (menu.selected_item_index == 0) {
                        std::cout << "story" << std::endl;
                    }
                    else if (menu.selected_item_index == 1) {
                        pvparena();
                    }
                    else if (menu.selected_item_index == 2) {
                        std::cout << "exit" << std::endl;
                    }
                }
            }
        }
        window.clear();
        window.draw(main_background);
        menu.draw_elements(window);
        window.display();
    }

    return 0;
}