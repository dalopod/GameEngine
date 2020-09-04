#include "Entity.h"

Entity::Entity() {
	sf::Texture texture;
	if (!texture.loadFromFile("spriteFront.png"))
	{
		// error...
		//std::cout << "texture error";
	}
	this->frontSprite_ = texture;
	this->isSolid_ = false;
	this->moving = false;
	this->x = 0;
	this->y = 0;

}

Entity::Entity(int x, int y, bool isSolid, sf::Texture texture) {
	this->frontSprite_ = texture;
	this->isSolid_ = isSolid;
	this->moving = false;
	this->x = x;
	this->y = y;
}

sf::Texture* Entity::getFrontSprite() {
	return &this->frontSprite_;
}

bool Entity::hasCollision() {
	return Entity::isSolid_;
}