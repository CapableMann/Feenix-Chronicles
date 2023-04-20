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

};

