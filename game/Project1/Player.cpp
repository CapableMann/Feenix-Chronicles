#include "Player.h"



Player::Player(sf::Texture* texture, float xPos, float yPos, bool face_right) : player_hitbox(sf::Vector2f(50.0f, 100.0f)), animation(texture, sf::Vector2u(8,7), 1.0f)
{
	player_hitbox.setTexture(texture);
	player_hitbox.setPosition(xPos, yPos);
	player_speed = 400.f;
	player_jumpSpeed = 800.f;
	this->face_right = face_right;

	face_right? player_hitbox.setScale(1, 1): player_hitbox.setScale(-1, 1);
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

	if (x == 1) {
		player_hitbox.setScale( 1, 1);
	}
	else {
		player_hitbox.setScale(-1, 1);
	}
	animation.Translate(0, delta_time);
    
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
	player_hitbox.setTextureRect(animation.uv_rect);
	window.draw(player_hitbox);
}

int Player::attack_set(int n)
{	
	is_attacking = true;
	return n;
}

bool Player::attacker(int x, float delta_time)
{	
	bool cont = false;
	if (x == 0) {
		cont = animation.Punch(5, delta_time);
	}
	return cont;
}






