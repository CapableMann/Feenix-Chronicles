#include  <SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Feenix Chronicles",sf::Style::Close);
    sf::RectangleShape main_background(sf::Vector2f(1280, 720));
    sf::Texture main_background_texture;
    main_background_texture.loadFromFile("backgrounds/main_menu.jpg");
    main_background.setTexture(&main_background_texture);

    sf::Text title;
    sf::Font title_font;
    title.setCharacterSize(90);
    title.setPosition(sf::Vector2f(150, 150));
    title.setString("FEENIX\nCHRONICLES");
    if (!title_font.loadFromFile("fonts/ELEGANT  Personal use.ttf")) {
        std::cout << "Fuck Meh" << std::endl;
    }
    title.setFont(title_font);
    title.setFillColor(sf::Color::White);
    
    sf::Event event;

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }
        window.clear();
        window.draw(main_background);
        window.draw(title);
        window.display();
    }

    return 0;
}