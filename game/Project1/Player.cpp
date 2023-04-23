#include "Player.h"



Player::Player(sf::Color color, float xPos, float yPos) : player_hitbox(sf::Vector2f(50.0f, 100.0f))
{
	player_hitbox.setFillColor(color);
	player_hitbox.setPosition(xPos, yPos);
	player_speed = 400.f;
	player_jumpSpeed = 1000.f;
}

Player::~Player()
{
}

void Player::mover(float x, float y, float delta_time)
{
    //Move the player
    player_hitbox.move(x * horizontal_multiplier * player_speed * delta_time, y * horizontal_multiplier * player_speed * delta_time);

	if (player_hitbox.getPosition().x < 0) {
		player_hitbox.setPosition(0, player_hitbox.getPosition().y);
	}
	if (player_hitbox.getPosition().x > 1250) {
		player_hitbox.setPosition(1250, player_hitbox.getPosition().y);
	}
    
}

void Player::MakeJump()
{
	if (player_hitbox.getPosition().y >= 500.f) {
		isJumping = true;
		horizontal_multiplier = 2;
	}
}

void Player::ResetJumping()
{
	if (player_hitbox.getPosition().y < 300.f) {
		isJumping = false;
		horizontal_multiplier = 1;
	}
}

void Player::jumper(float delta_time)
{
	if (isJumping) {
		player_hitbox.move(0, -1 * player_jumpSpeed * delta_time);
	}
	else {
		if (player_hitbox.getPosition().y < 500.f) {
			player_hitbox.move(0, 1 * player_jumpSpeed * delta_time);
		}
	}
}

void Player::level_checker()
{
	//Prevent going below y=500
	if (player_hitbox.getPosition().y > 500) {
		player_hitbox.setPosition(player_hitbox.getPosition().x, 500.f);
	}
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(player_hitbox);
}





