#include "Board.h"

Board::Board(Tile* tile) {
	//this->board_ = new Tile(tile)[10][9];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			this->board_[i][j] = tile;
		}
	}
}

Board::~Board() {
	//delete this;
}

void Board::setBoardTile(Tile *tile, int x, int y) {
	Board::board_[x][y] = tile;
}

Tile* Board::getBoardTile(int x, int y) {
	return Board::board_[x][y];
}