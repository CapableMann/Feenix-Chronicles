#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u image_count, float switch_time);
	~Animation();

	void Translate(int column, float delta_time);
	bool Punch(int column, float delta_time);
	sf::IntRect uv_rect;

private:
	sf::Vector2u image_count;
	sf::Vector2u current_image;
	float total_time;
	float switch_time;
};

