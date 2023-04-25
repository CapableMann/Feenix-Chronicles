#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, float xPos, float yPos, bool face_right);
	~Player();
	void mover(float x, float y, float delta_time);
	void MakeJump();
	void ResetJumping();
	void jumper(float delta_time);
	void level_checker();
	void draw(sf::RenderWindow& window);
	int attack_set(int n);
	bool attacker(int x, float delta_time);
	bool face_right;
	bool is_attacking= false;
	void simple_punch(float delta_time);
	sf::RectangleShape player_hitbox;
private:
	float player_speed;
	float player_jumpSpeed;
	bool isJumping = false;
	float horizontal_multiplier = 1;
	Animation animation;
};

