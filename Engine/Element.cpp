#include "Obstacles.h"
#include "Element.h"

class Obstacles;

Element::Element() {
}

void Element::Init(std::mt19937& rnd, const Board& board, const Snake& snake, Obstacles* obstacles) {

	std::uniform_int_distribution<int> distWidth(0, board.GetWidth() - 1);
	std::uniform_int_distribution<int> distHeight(0, board.GetHeight() - 1);
	Location newLoc;
	do {
		newLoc = { distWidth(rnd), distHeight(rnd) };

	} while (snake.ContainsLocation(newLoc) || obstacles->ContainsLocation(newLoc));
	loc = newLoc;
}

void Element::Draw(Board& board) const {
	board.DrawCell(loc, c, 0);
}

const Location& Element::GetLocation() const {
	return loc;
}