#include "Tile.h"
Tile::Tile(std::string filename, bool passable) {
	sf::Texture texture;
	if (!texture.loadFromFile("sprites/" + filename))
	{
		// error...
		std::cout << "texture error";
	}
	this->texture_ = texture;
	this->passable_ = passable;
}

Tile::~Tile() {
	//delete this;
}

bool Tile::isPassable() {
	return this->passable_;
}

sf::Texture* Tile::getTexture() {
	return &this->texture_;
}