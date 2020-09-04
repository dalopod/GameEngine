#include "UserInterface.h"

UserInterface::UserInterface() {
	sf::Texture texture;

	if (!texture.loadFromFile("sprites/heart.png"))
	{
		// error...
		std::cout << "texture error";
	}
	this->health_ = texture;
	if (!texture.loadFromFile("sprites/mana.png"))
	{
		// error...
		std::cout << "texture error";
	}
	this->mana_ = texture;
}

UserInterface::~UserInterface() {
}

sf::Texture* UserInterface::getHealthTexture() {
	return &this->health_;
}

sf::Texture* UserInterface::getManaTexture() {
	return &this->mana_;
}