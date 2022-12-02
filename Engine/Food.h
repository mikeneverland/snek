#pragma once
#include "Location.h"
#include "Colors.h"
#include "Snake.h"
#include <random>

class Food {

public:
	Food(std::mt19937& rnd, const Board& board, const Snake& snake);
	void Respawn( std::mt19937& rnd, const Board& board, const Snake& snake);
	void Draw(Board& board) const;
	const Location& GetLocation() const;

private:
	Location loc;
	static constexpr Color c = Colors::Red;
};