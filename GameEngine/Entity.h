#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>

class Entity
{
public:

	Entity();

	Entity(int x, int y, bool isSolid_, sf::Texture texture);
	sf::Texture* getFrontSprite();
	bool hasCollision();
	bool moving;
	int x;
	int y;

private:
	sf::Texture frontSprite_;
	bool isSolid_;
};

