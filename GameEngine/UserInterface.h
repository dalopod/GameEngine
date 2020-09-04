#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <iostream>

// Userinterface that displays health, mana, items, and other information in the bottom row.
class UserInterface
{
public:
	UserInterface();
	~UserInterface();

	sf::Texture* getHealthTexture();

	sf::Texture* getManaTexture();

private:
	sf::Texture health_;
	sf::Texture mana_;
};

