#pragma once
#include <SFML/Graphics.hpp>

#define NO_OF_BUTTONS 3

class main_menu
{
public:
	main_menu(float width, float height);
	~main_menu();
	void draw_elements(sf::RenderWindow& window);
	void move_up();
	void move_down();
	int selected_item_index = 0;

private:
	sf::Font title_font;
	sf::Font button_font;
	sf::Text menu_buttons[NO_OF_BUTTONS];
	sf::Text title;
};

