#include "Animation.h"
#include <iostream>

Animation::Animation(sf::Texture* texture, sf::Vector2u image_count, float switch_time)
{
	this->image_count = image_count;
	this->switch_time = switch_time;
	total_time = 0.0f;
	current_image.y = 0;

	uv_rect.width = texture->getSize().x / float(image_count.x);
	uv_rect.height = texture->getSize().y / float(image_count.y);
}

Animation::~Animation()
{
}


void Animation::Translate(int column, float delta_time)
{
	current_image.x = column;
	total_time += delta_time;
	if (total_time >= switch_time) {
		total_time -= switch_time;
		current_image.y++;
		if (current_image.y >= 3) {
			current_image.y = 0;
		}
	}
	uv_rect.left = current_image.x * uv_rect.width;
	uv_rect.top = current_image.y * uv_rect.height;

}

bool Animation::Punch(int column, float delta_time)
{	
	current_image.x = column;
	total_time += delta_time;
	float new_switch_time = total_time / 4; 
	std::cout << current_image.y << std::endl;
	if (total_time >= new_switch_time) {
		total_time -= new_switch_time;
		current_image.y++;
		if (current_image.y == 4) {
			current_image.y = 0;
			return true;
		}
	}
	uv_rect.left = current_image.x * uv_rect.width;
	uv_rect.top = current_image.y * uv_rect.height;
	return false;
}





