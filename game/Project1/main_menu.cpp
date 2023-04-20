#include "main_menu.h"
#include <iostream>

main_menu::main_menu(float width, float height)
{
	if (!title_font.loadFromFile("fonts/ELEGANT  Personal use.ttf")) {
		std::cout << "Font could not be loaded" << std::endl;
	}

	if (!button_font.loadFromFile("fonts/Silverglow.ttf")) {
		std::cout << "Font could not be loaded" << std::endl;
	}

	//Title
	title.setCharacterSize(90);
	title.setPosition(sf::Vector2f(150, 150));
	title.setString("FEENIX\nCHRONICLES");
	title.setFont(title_font);
	title.setFillColor(sf::Color::White);

	//Story Mode
	menu_buttons[0].setCharacterSize(70);
	menu_buttons[0].setPosition(sf::Vector2f(150, 350));
	menu_buttons[0].setString("STORY MODE");
	menu_buttons[0].setFont(button_font);
	menu_buttons[0].setFillColor(sf::Color::Red);

	//PvP
	menu_buttons[1].setCharacterSize(70);
	menu_buttons[1].setPosition(sf::Vector2f(150, 450));
	menu_buttons[1].setString("PvP");
	menu_buttons[1].setFont(button_font);
	menu_buttons[1].setFillColor(sf::Color::White);

	//Exit
	menu_buttons[2].setCharacterSize(70);
	menu_buttons[2].setPosition(sf::Vector2f(150, 550));
	menu_buttons[2].setString("EXIT");
	menu_buttons[2].setFont(button_font);
	menu_buttons[2].setFillColor(sf::Color::White);

}

main_menu::~main_menu()
{
}

void main_menu::draw_elements(sf::RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		window.draw(menu_buttons[i]);
	}
}

void main_menu::move_up()
{
	menu_buttons[selected_item_index].setFillColor(sf::Color::White);
	if (selected_item_index - 1 >= 0) {
		selected_item_index--;
	}
	else {
		selected_item_index = NO_OF_BUTTONS - 1;
	}
	menu_buttons[selected_item_index].setFillColor(sf::Color::Red);
}

void main_menu::move_down()
{
	menu_buttons[selected_item_index].setFillColor(sf::Color::White);
	if (selected_item_index + 1 < NO_OF_BUTTONS) {
		selected_item_index++;
	}
	else {
		selected_item_index = 0;
	}
	menu_buttons[selected_item_index].setFillColor(sf::Color::Red);
}

