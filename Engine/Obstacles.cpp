#include "Obstacles.h"

Obstacles::Obstacles() {
}

bool Obstacles::ContainsLocation(const Location& loc) const {

	for (int i = 0; i < obstaclesCount; i++ ) {
		Location tmpLoc = obst[i].GetLocation();
		if ( tmpLoc == loc) {
			return true;
		}
	}
	return false;
}

void Obstacles::Draw(Board& board) {
	for (int i = 0; i < obstaclesCount; i++) {
		obst[i].Draw(board);
	}
}

void Obstacles::Add(std::mt19937& rng, const Board& board, const Snake& snake) {
	if (obstaclesCount < obstaclesMaxCount) {
		obst[obstaclesCount].Init(rng, board, snake, this);
		obstaclesCount++;
	}
}
