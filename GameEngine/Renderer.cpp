/*#include "Renderer.h"

Renderer::Renderer() {
}

Renderer::~Renderer() {
	delete this;
}

// Render screen
void Renderer::Render(Game* game, sf::RenderWindow* window) {//Board* currentArea, Entity entities[], sf::RenderWindow* window) {
	// clear the window with black color
	window->clear(sf::Color::Black);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			this->sprite_.setTexture(*game->currentArea_->getBoardTile(i, j)->getTexture());
			this->sprite_.setScale(sf::Vector2f(5.f, 5.f));
			this->sprite_.setPosition(sf::Vector2f(i*80.f, 560 - j*80.f));
			window->draw(sprite_);
			//sprite.;
			// draw everything here...
			// window.draw(...);
		}
	}
	this->sprite_.setTexture(game->entities_[0].getFrontSprite());
	this->sprite_.setScale(sf::Vector2f(5.f, 5.f));
	this->sprite_.setPosition(sf::Vector2f(game->entities_[0].x * 80.f, 640 - game->entities_[0].y * 80.f));
	window->draw(sprite_);
	//delete& sprite;


	// end the current frame
	window->display();
};

*/