#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player(sf::Color color, float xPos, float yPos);
	~Player();
	void mover(float x, float y, float delta_time);
	void MakeJump();
	void ResetJumping();
	void jumper(float delta_time);
	void level_checker();
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape player_hitbox;
	float player_speed;
	float player_jumpSpeed;
	bool isJumping = false;
	float horizontal_multiplier = 1;
};

