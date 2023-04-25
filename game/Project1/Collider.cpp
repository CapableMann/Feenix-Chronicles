#include "Collider.h"

Collider::Collider(sf::RectangleShape& shape) : shape_(shape)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider& other)
{
    sf::Vector2f thisPosition = shape_.getPosition();
    sf::Vector2f otherPosition = other.shape_.getPosition();

    sf::Vector2f thisHalfSize = shape_.getSize() / 2.0f;
    sf::Vector2f otherHalfSize = other.shape_.getSize() / 2.0f;

    float xDistance = abs(thisPosition.x - otherPosition.x);
    float yDistance = abs(thisPosition.y - otherPosition.y);

    float xOverlap = thisHalfSize.x + otherHalfSize.x - xDistance;
    float yOverlap = thisHalfSize.y + otherHalfSize.y - yDistance;

    if (xOverlap > 0 && yOverlap > 0) {
        return true;
    }
    else {
        return false;
    }
}
