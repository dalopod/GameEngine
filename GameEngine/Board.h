#pragma once
#include "Tile.h"
#include "Entity.h"

class Board
{
public:
	Board(Tile* tile);
	~Board();

	// Set board tile at x,y.
	void setBoardTile(Tile* tile, int x, int y);

	// Get board tile at x,y.
	Tile* getBoardTile(int x, int y);

private:
	Tile* board_[10][8];
};

