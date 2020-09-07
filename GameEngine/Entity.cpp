#include "Entity.h"

Entity::Entity(std::string name, bool solid) {
	sf::Texture texture;
	if (!texture.loadFromFile("sprites/" + name + "Front.png"))
	{
		// error...
		//std::cout << "texture error";
	}
	this->frontSprite_ = texture;
	if (!texture.loadFromFile("sprites/" + name + "Right.png"))
	{
		// error...
		//std::cout << "texture error";
	}
	this->rightSprite_ = texture;
	if (!texture.loadFromFile("sprites/" + name + "Back.png"))
	{
		// error...
		//std::cout << "texture error";
	}
	this->backSprite_ = texture;
	if (!texture.loadFromFile("sprites/" + name + "Left.png"))
	{
		// error...
		//std::cout << "texture error";
	}
	this->leftSprite_ = texture;
	this->isSolid_ = solid;
	this->moving = false;
	this->x = 0;
	this->y = 0;
	this->health = 4;
	this->mana = 4;
	this->maxHealth = 4;
	this->maxMana = 4;
	this->direction = 3;
}

Entity::Entity(int x, int y, bool isSolid, sf::Texture texture) {
	this->frontSprite_ = texture;
	this->isSolid_ = isSolid;
	this->moving = false;
	this->x = x;
	this->y = y;
}

sf::Texture* Entity::getSprite() {
	switch (this->direction) {
	case 1:
		return &this->backSprite_;
		break;
	
	case 2:
		return &this->rightSprite_;
		break;
	
	case 3:
		return &this->frontSprite_;
		break;
	case 4:
		return &this->leftSprite_;
		break;

	default:
		return &this->frontSprite_;
		break;
	}
}

bool Entity::hasCollision() {
	return Entity::isSolid_;
}