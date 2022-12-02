#pragma once

#include "Location.h"
#include "Colors.h"
#include "Snake.h"
#include "Element.h"
#include <random>


class Obstacles {

public:
	Obstacles();
	bool ContainsLocation(const Location& loc) const;
	void Draw(Board& board);
	void Add(std::mt19937& rng, const Board& board, const Snake& snake);

	int obstaclesCount = 0;
	static constexpr int obstaclesMaxCount = 50;
	int obstaclesSnakeIncrementCount = 0;
	static constexpr int obstaclesSnakeIncrement = 2;

private:
	Element obst[50];


};



