#pragma once
#include <SFML/Graphics.hpp>

class pvpscreen
{
public:
	pvpscreen(float width, float height);
	~pvpscreen();
	void draw_elements(sf::RenderWindow& window);
	void player_one_right();
	void player_one_left();
	void player_two_right();
	void player_two_left();     

private:
	int player_one_index = 0;
	int player_two_index = 0;
	sf::Font title_font;
	sf::Font player_name_font;
	sf::Text title_text;
	sf::Text player1_name;
	sf::Text player2_name;
};

