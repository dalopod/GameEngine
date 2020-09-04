#include "Game.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/Graphics.hpp>

constexpr auto MS_PER_UPDATE = 1000 / 60;

// Game
Game::Game() {
	//this->renderer_ = new Renderer();
	this->entities_ = new Entity[32];
	Game::initialize();
	Game::loadLevel(0, 0);
	this->levelx = 0;
	this->levely = 0;
	this->ui_ = new UserInterface();
	// Ghetto memory fix
}

/*Game::Game(Renderer* renderer, UserInterface* ui) {
	this->renderer_ = renderer;
	this->ui_ = ui;
	this->entities_ = new Entity[32];

	//this->currentArea_ = Game::loadLevel();
	
}*/

Game::~Game() {
	//this->renderer_->~Renderer();
	//this->ui_->~UserInterface();
	//delete this;
}

void Game::gameLoop() {
	auto duration = std::chrono::system_clock::now().time_since_epoch();
	auto previous = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	double lag = 0.0;
	int tick = 0;
	// Temporary
	sf::Texture texture;
	if (!texture.loadFromFile("sprites/spriteFrontRed.png")) {
		// error...
		std::cout << "texture error";
	}
	Entity* dave = new Entity(3, 5, true, texture);
	this->entities_[0] = *dave;
	dave->~Entity();
	dave = &this->entities_[0];
	// End temporary
	sf::RenderWindow window(sf::VideoMode(800, 720), "SPRITE ORGY");
	int action = 0;
	bool keyReleased = false;
	bool actionTaken = false;
	while (window.isOpen())
	{
		duration = std::chrono::system_clock::now().time_since_epoch();
		auto current = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		if (!keyReleased) {
			keyReleased = Game::processInput(tick, &window, &action);
		}
		while (lag >= MS_PER_UPDATE)
		{
			actionTaken = Game::update(tick, dave, action, actionTaken);
			if ((keyReleased && actionTaken) || (action == 0)) {
				//std::cout << action << "\n";
				action = 0;
				actionTaken = false;
				keyReleased = false;
				//std::cout << "released \n";
			}
			lag -= MS_PER_UPDATE;
			tick++;
			// this might need to move
			if (tick >= 60) {
				tick = 0;
			}
		}
		Game::render(&window);

	}
}

void Game::initialize() {
	tiles_.reserve(6);
	tiles_.push_back(Tile("grass.png", true));
	tiles_.push_back(Tile("dirt.png", true));
	tiles_.push_back(Tile("water.png", false));
	tiles_.push_back(Tile("sand.png", true));
	tiles_.push_back(Tile("tree.png", false));
	tiles_.push_back(Tile("rock.png", false));
}

bool Game::processInput(int tick, sf::RenderWindow* window, int* action) {
	sf::Event event;
	bool keyReleased = false;
	while (window->pollEvent(event))
	{
		// check the type of the event...
		switch (event.type) {
		// window closed
		case sf::Event::Closed:
			window->close();
			break;

		// key pressed
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				*action = 1;
				keyReleased = false;
				break;
			case sf::Keyboard::Right:
				*action = 2;
				keyReleased = false;
				break;
			case sf::Keyboard::Down:
				*action = 3;
				keyReleased = false;
				break;
			case sf::Keyboard::Left:
				*action = 4;
				keyReleased = false;
				break;
			case sf::Keyboard::X:
				*action = 5;
				keyReleased = false;
				break;
			case sf::Keyboard::Z:
				*action = 6;
				keyReleased = false;
				break;
			default:
				*action = 7;
				break;
			}
			break;

		case sf::Event::KeyReleased:
			keyReleased = true;
			break;

		// we don't process other types of events
		default:
			break;
		}
	}
	return keyReleased;

}

bool Game::update(int tick, Entity* dave, int action, bool actionTaken) {
	if (((tick + 1) % 15) == 0) {
		if (dave->moving) {
			dave->moving = false;
		}
		switch (action) {
		// Up
		case 1:
			actionTaken = true;
			dave->moving = true;
			move(dave, 0, 1);
			break;
		// Right
		case 2:
			actionTaken = true;
			dave->moving = true;
			move(dave, 1, 0);
			break;
		// Down
		case 3:
			actionTaken = true;
			dave->moving = true;
			move(dave, 0, -1);
			break;
		// Left
		case 4:
			actionTaken = true;
			dave->moving = true;
			move(dave, -1, 0);
			break;
		case 5:
			actionTaken = true;
		case 6:
			actionTaken = true;
		case 7:
			actionTaken = true;
		default:
			break;
		}
		//std::cout << "x: " << dave->x << " " << "y: " << dave->y << "\n";
	}
	return actionTaken;
}

void Game::move(Entity* entity, int xChange, int yChange) {
	int desiredX = entity->x + xChange;
	int desiredY = entity->y + yChange;
	if (desiredX > 9) {
		this->levelx += 1;
		entity->x = 0;
		Game::loadLevel(this->levelx, this->levely);
	}
	else if (desiredX < 0) {
		entity->x = 9;
		this->levelx -= 1;
		Game::loadLevel(this->levelx, this->levely);
		
	}
	else if (desiredY > 7) {
		entity->y = 0;
		this->levely += 1;
		Game::loadLevel(this->levelx, this->levely);

	}
	else if (desiredY < 0) {
		entity->y = 7;
		this->levely -= 1;
		Game::loadLevel(this->levelx, this->levely);
	} else if (this->currentArea_->getBoardTile(desiredX, desiredY)->isPassable()) {
		entity->x = desiredX;
		entity->y = desiredY;
	}
}

void Game::loadLevel(int x, int y) {
	this->currentArea_ = new Board(&tiles_.at(0));
	std::string line;
	std::ifstream myfile("levels/" + std::to_string(x)+ std::to_string(y) + ".txt");
	if (myfile.is_open()) {
		int y = 7;
		while (getline(myfile, line)) {
			for (int i = 0; i < 10; i++) {
				currentArea_->setBoardTile(&tiles_.at((line[i]) - 48), i, y);
			}
			std::cout << y;
			y--;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
	//system("dir");
	
}

void Game::render(sf::RenderWindow* window) {
	// clear the window with black color
	window->clear(sf::Color::Black);

	// Draw level.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			sf::Sprite sprite;
			sprite.setTexture(*this->currentArea_->getBoardTile(i, j)->getTexture());
			sprite.setScale(sf::Vector2f(5.f, 5.f));
			sprite.setPosition(sf::Vector2f(i * 80.f, 560 - j * 80.f));
			window->draw(sprite);
			// draw everything here...
			// window.draw(...);
		}
	}

	// Draw Entities
	sf::Sprite sprite;
	sprite.setTexture(*this->entities_[0].getFrontSprite());
	sprite.setScale(sf::Vector2f(5.f, 5.f));
	sprite.setPosition(sf::Vector2f(this->entities_[0].x * 80.f, 560 - this->entities_[0].y * 80.f));
	window->draw(sprite);

	// Draw UI.
	sprite.setTexture(*this->ui_->getHealthTexture());
	sprite.setPosition(sf::Vector2f(0, 640));
	window->draw(sprite);

	sprite.setTexture(*this->ui_->getManaTexture());
	sprite.setPosition(sf::Vector2f(2 * 80.f, 640));
	window->draw(sprite);

	// end the current frame
	window->display();
};
	//this->renderer_->Render(this, window);//this->currentArea_, this->entities_, window);
	//this->ui_.render();