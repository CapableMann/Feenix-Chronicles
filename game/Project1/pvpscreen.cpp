#include "pvpscreen.h"
#include <iostream>

pvpscreen::pvpscreen(float width, float height)
{
	if (!title_font.loadFromFile("fonts/ELEGANT  Personal use.ttf")) {
		std::cout << "Font could not be loaded" << std::endl;
	}

	if (!player_name_font.loadFromFile("fonts/Silverglow.ttf")) {
		std::cout << "Font could not be loaded" << std::endl;
	}
	//Title
	title_text.setCharacterSize(90);
	title_text.setPosition(sf::Vector2f(580, 150));
	title_text.setString("PvP Arena");
	title_text.setFont(title_font);

}
