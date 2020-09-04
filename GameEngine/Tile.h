#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <iostream>

// Container for map tiles.
class Tile
{
public:
	Tile(std::string filename, bool passable);
	~Tile();

	sf::Texture* getTexture();

	bool isPassable();

private:
	bool passable_;
	sf::Texture texture_;

};

