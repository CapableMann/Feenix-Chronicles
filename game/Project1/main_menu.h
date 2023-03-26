#pragma once
#include <SFML/Graphics.hpp>

#define NO_OF_BUTTONS 3

class main_menu
{
public:
	main_menu(float width, float height);
	void draw_elements(sf::RenderWindow& window);
	void move_up();
	void move_down();
	int Get_item_index();
	void mouse_pressed(sf::RenderWindow & window);
private:
	int selected_item_index;
	sf::Font title_font;
	sf::Font button_font;
	sf::Text menu_buttons[NO_OF_BUTTONS];
	sf::Text title;
};

