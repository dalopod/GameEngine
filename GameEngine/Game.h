#pragma once
#include "Renderer.h"
#include "Board.h"
#include "UserInterface.h"
#include "Entity.h"
#include "Tile.h"

class Game
{
public:
	// Default constructor;
	Game();
	// Constructor that connects the various engines to the central game class.
	//Game(Renderer* renderer, UserInterface* ui);

	// Deconstructor
	~Game();

	void gameLoop();
	int levelx;
	int levely;

private:
	// References to the various required engines.
	//Renderer* renderer_;
	Board* currentArea_;
	Entity* entities_;
	std::vector<Tile> tiles_;
	
	//UserInterface* ui_;
	
	// Initialize asset arrays.
	void initialize();

	// Processes the inputs and returns the last key pressed.
	bool processInput(int tick, sf::RenderWindow* window, int* action);

	// Processes inputs and updates the gamestate.
	bool update(int tick, Entity* dave, int action, bool actionTaken);

	void move(Entity* entity, int xChange, int yChange);

	// Loads a new level if necessary.
	void loadLevel(int x, int y);

	// Render the screen by calling all relevant render functions.
	void render(sf::RenderWindow* window);
};

