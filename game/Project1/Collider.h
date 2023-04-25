#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& shape);
	~Collider();

	bool CheckCollision(Collider& other);

private:
	sf::RectangleShape& shape_;
};

