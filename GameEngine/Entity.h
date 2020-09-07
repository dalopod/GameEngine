#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Texture.hpp>

// Contains information about the entities (players/npcs/enemies/objects) that exist in the world.
class Entity
{
public:

	Entity(std::string name, bool solid);

	Entity(int x, int y, bool isSolid_, sf::Texture texture);
	
	// Return forward facing sprite.
	sf::Texture* getSprite();

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
	int direction;

private:
	sf::Texture frontSprite_;
	sf::Texture backSprite_;
	sf::Texture rightSprite_;
	sf::Texture leftSprite_;
	bool isSolid_;
};

