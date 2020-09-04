#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>

// Contains information about the entities (players/npcs/enemies/objects) that exist in the world.
class Entity
{
public:

	Entity();

	Entity(int x, int y, bool isSolid_, sf::Texture texture);
	
	// Return forward facing sprite.
	sf::Texture* getFrontSprite();

	// Return if the entity is solid or not.
	bool hasCollision();

	// Boolean describing if the entity is currently moving, mainly for rendering purposes.
	bool moving;

	// Current location on the screen of the entity.
	int x;
	int y;
	int health;
	int mana;
	int maxHealth;
	int maxMana;

private:
	sf::Texture frontSprite_;
	bool isSolid_;
};

