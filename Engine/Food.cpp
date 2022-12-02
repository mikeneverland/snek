#include "Food.h"
#include "Board.h"
#include "Snake.h"
#include <random>

Food::Food(std::mt19937& rnd, const Board& board, const Snake& snake) {

	Respawn(rnd, board, snake);

}

void Food::Respawn(std::mt19937& rnd, const Board& board, const Snake& snake) {

	std::uniform_int_distribution<int> distWidth(0, board.GetWidth() - 1);
	std::uniform_int_distribution<int> distHeight(0, board.GetHeight() - 1);
	Location newLoc;
	do {
		newLoc = { distWidth(rnd), distHeight(rnd) };

	} while (snake.ContainsLocation(newLoc));
	loc = newLoc;

}

void Food::Draw(Board& board) const {

	board.DrawCell(loc, c, 0);

}

const Location& Food::GetLocation() const {
	return loc;
}
